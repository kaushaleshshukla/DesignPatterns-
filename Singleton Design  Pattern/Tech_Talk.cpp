/** Tech Talk */

/*Problem - Create a chocolate boiler which will take chocolate and mild bring them to boil and then pass them on the
next phase of making chocolate bars.*/

class ChocolateBoiler {
public:
	public ChocolateBoiler() : empty(true), boiled(true){}
    
    bool isBoiled() {
    	return boiled;
    }

    bool isEmpty(){
    	return empty;
    }

	void fill () {
		if(isEmpty()) {
			empty = false;
			boiled = false;
			//fill the container
		}
	}

	void drain () {
		if(!isEmpty() && isBoiled()) {
			//drain boiled content
			empty = true;
		}
	}

	void boil() {
		if(!isEmpty() && !isBoiled()) {
			//boil it
			boiled = true;
		}
	}

private:
	bool boiled;
	bool empty;
}

/** Singleton Pattern ensures a class has only one instance, and provides a global point of access to it. 
To get the instance of Singleton class we don't instantiate one, we just ask for the instance. (Feels like a 
global variable inside a namespace)

Uses : 
Thread pools, Caches, Dialog boxes, objects used for logging, object used for resources

Non-copyable Singleton class */

class Singleton {
public:
    static Singleton& getInstance() {
        return uniqueInstance;
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton uniqueInstance;
};

Singleton Singleton::uniqueInstance;


//Thread-safe Singleton 

//1) Synchronize whole getInstance() method 

class Singleton {
public:
    static Singleton* getInstance() {
        //lock
        if(uniqueInstance == nullptr) {
            uniqueInstance = new Singleton();
        }
        return uniqueInstance;
        //release lock
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton* uniqueInstance;
};

Singleton* Singleton::uniqueInstance = nullptr;

//2) Create instance Eagerly rather than lazily creation

class Singleton {
public:
    static Singleton& getInstance() {
        return uniqueInstance;
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton uniqueInstance;
};

Singleton Singleton::uniqueInstance;

//3) Use double-check locking

class Singleton {
public:
    static Singleton* getInstance() {
        if(uniqueInstance == nullptr) {
            // lock
            if(uniqueInstance == nullptr)
                uniqueInstance = new Singleton();
            // release lock
        }
        return uniqueInstance;
    }

private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    
    static Singleton* uniqueInstance;
};

Singleton* Singleton::uniqueInstance = nullptr;


// Mayer's Singleton
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton uniqueInstance;
        return uniqueInstance;
    }

    int get(){
        return val;
    }

private:
    Singleton() : val(0) {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    int val;
};

//static Singleton(Monospace pattern)

class Singleton {
public:
    Singleton() {};
    int get() { return value; }
private:
    static int val;
}

//Leaky Singleton

/**Pros
	1) Easy implementation
	2) Effective when you know you need one of something
	3) Avoid polluting global namespace with lots of varibles
	4) Memory is only allocated if you actually use the Singleton (implementation based)
	5) Subclassing

Cons
    1) Wrong usage could take code refactoring.
    2) Not thread-safe, adding lock will slow down application
    3) Effectively we are using globals. (most likely global under a namespace)
    4) Handles two responsibility */

//Pointer vs reference for getInstance()
   // No reason to use a pointer.
    Singleton * MySingleton = Singleton::getInstance();

    // When you have a pointer there is no ownership semantics
    // associated. So it is easy to make a mistake and accidentally
    // call delete on the pointer.


    // It returns a reference, so capture a reference
    Singleton&  MySingleton = Singleton::getInstance(); 

    // Here ownership semantics are clear.
    // You don't own the object (you simply have a reference to it).
    // It is your responsibility to make sure the object has not been
    // destroyed since you retrieved the reference.