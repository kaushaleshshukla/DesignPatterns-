#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

// The request travelling through the chain
struct Request {
    std::string user;
    std::string password;
    std::string ip;
    std::string payload;   // raw, possibly dirty input
    std::string action;    // e.g., "view", "delete"
};

// 1. HANDLER INTERFACE / BASE HANDLER
class Handler {
protected:
    Handler* next = nullptr;
public:
    virtual ~Handler() = default;

    // Returns the next handler so chains read fluently:
    //   auth.setNext(&perm)->setNext(&cache);
    Handler* setNext(Handler* h) { next = h; return h; }

    // Default behavior: forward if a successor exists, otherwise accept.
    virtual bool handle(Request& req) {
        if (next) return next->handle(req);
        return true;
    }
};

// 2. CONCRETE HANDLERS

// (a) Authentication - stops the chain if credentials are wrong
class AuthHandler : public Handler {
    std::unordered_map<std::string, std::string> users{
        {"alice", "pw123"}, {"bob", "hunter2"}
    };
public:
    bool handle(Request& req) override {
        auto it = users.find(req.user);
        if (it == users.end() || it->second != req.password) {
            std::cout << "[Auth] rejected: bad credentials\n";
            return false;
        }
        std::cout << "[Auth] ok\n";
        return Handler::handle(req);
    }
};

// (b) Permission - only admins can do destructive actions
class PermissionHandler : public Handler {
    std::unordered_set<std::string> admins{"alice"};
public:
    bool handle(Request& req) override {
        if (req.action == "delete" && !admins.count(req.user)) {
            std::cout << "[Perm] rejected: '" << req.user << "' is not admin\n";
            return false;
        }
        std::cout << "[Perm] ok\n";
        return Handler::handle(req);
    }
};

// (c) Brute-force filter - blocks repeated failures from same IP
class ThrottleHandler : public Handler {
    std::unordered_map<std::string, int> hits;
    const int limit = 3;
public:
    bool handle(Request& req) override {
        if (++hits[req.ip] > limit) {
            std::cout << "[Throttle] rejected: too many requests from " << req.ip << "\n";
            return false;
        }
        std::cout << "[Throttle] ok (" << hits[req.ip] << "/" << limit << ")\n";
        return Handler::handle(req);
    }
};

// (d) Validation / sanitization - strips obvious garbage
class ValidationHandler : public Handler {
public:
    bool handle(Request& req) override {
        if (req.payload.find('<') != std::string::npos) {
            std::cout << "[Validate] rejected: payload contains '<'\n";
            return false;
        }
        std::cout << "[Validate] ok\n";
        return Handler::handle(req);
    }
};

// (e) Cache - short-circuits the chain on a hit
class CacheHandler : public Handler {
    std::unordered_set<std::string> seen;
public:
    bool handle(Request& req) override {
        std::string key = req.user + "|" + req.action + "|" + req.payload;
        if (seen.count(key)) {
            std::cout << "[Cache] hit - short-circuiting chain\n";
            return true;
        }
        seen.insert(key);
        std::cout << "[Cache] miss\n";
        return Handler::handle(req);
    }
};

// 3. CLIENT - assembles the chain and dispatches requests
int main() {
    ThrottleHandler   throttle;
    AuthHandler       auth;
    PermissionHandler perm;
    ValidationHandler validate;
    CacheHandler      cache;

    // Throttle -> Auth -> Permission -> Validate -> Cache
    throttle.setNext(&auth)->setNext(&perm)->setNext(&validate)->setNext(&cache);

    auto dispatch = [&](Request r, const std::string& label) {
        std::cout << "\n--- " << label << " ---\n";
        std::cout << (throttle.handle(r) ? "ACCEPTED\n" : "REJECTED\n");
    };

    dispatch({"alice", "pw123",  "1.1.1.1", "hello",   "view"},   "valid view by alice");
    dispatch({"bob",   "wrong",  "1.1.1.1", "hello",   "view"},   "wrong password");
    dispatch({"bob",   "hunter2","1.1.1.1", "hello",   "delete"}, "bob tries to delete (not admin)");
    dispatch({"alice", "pw123",  "1.1.1.1", "<script>","delete"}, "alice with dirty payload");
    dispatch({"alice", "pw123",  "1.1.1.1", "hello",   "view"},   "repeat -> cache hit");

    return 0;
}
