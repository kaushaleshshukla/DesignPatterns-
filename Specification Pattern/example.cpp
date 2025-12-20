#include <iostream>
#include <vector>
#include <string>

// 1. THE ENTITY (The object we are filtering)
struct Car {
    std::string model;
    std::string type; // e.g., "SUV", "Sedan"
    int pricePerDay;
};

// 2. THE SPECIFICATION INTERFACE
template <typename T>
struct ISpecification {
    virtual ~ISpecification() = default;
    virtual bool isSatisfied(const T& item) const = 0;
};

// 3. LOGIC COMBINATORS (The "And" and "Or" Rules)
template <typename T>
struct AndSpecification : ISpecification<T> {
    const ISpecification<T>& first;
    const ISpecification<T>& second;

    AndSpecification(const ISpecification<T>& f, const ISpecification<T>& s) 
        : first(f), second(s) {}

    bool isSatisfied(const T& item) const override {
        return first.isSatisfied(item) && second.isSatisfied(item);
    }
};

template <typename T>
struct OrSpecification : ISpecification<T> {
    const ISpecification<T>& first;
    const ISpecification<T>& second;

    OrSpecification(const ISpecification<T>& f, const ISpecification<T>& s) 
        : first(f), second(s) {}

    bool isSatisfied(const T& item) const override {
        return first.isSatisfied(item) || second.isSatisfied(item);
    }
};

// 4. CONCRETE SPECIFICATIONS (The actual Business Rules)
struct TypeSpecification : ISpecification<Car> {
    std::string type;
    TypeSpecification(std::string t) : type(t) {}
    bool isSatisfied(const Car& car) const override { return car.type == type; }
};

struct PriceSpecification : ISpecification<Car> {
    int maxPrice;
    PriceSpecification(int p) : maxPrice(p) {}
    bool isSatisfied(const Car& car) const override { return car.pricePerDay <= maxPrice; }
};

// 5. THE FILTER ENGINE
struct CarFilter {
    std::vector<Car*> filter(std::vector<Car*>& cars, const ISpecification<Car>& spec) {
        std::vector<Car*> result;
        for (auto& car : cars) {
            if (spec.isSatisfied(*car)) {
                result.push_back(car);
            }
        }
        return result;
    }
};

// 6. USAGE EXAMPLE
int main() {
    Car c1{"Tesla Model 3", "Sedan", 100};
    Car c2{"Range Rover", "SUV", 250};
    Car c3{"Toyota Camry", "Sedan", 60};
    
    std::vector<Car*> inventory = {&c1, &c2, &c3};

    CarFilter filter;

    // Define rules
    TypeSpecification isSedan("Sedan");
    PriceSpecification budgetFriendly(80);

    // Combine rules: Find me a Sedan AND Budget Friendly
    AndSpecification<Car> sedanAndCheap(isSedan, budgetFriendly);

    auto results = filter.filter(inventory, sedanAndCheap);

    for (auto const& car : results) {
        std::cout << "Match found: " << car->model << " ($" << car->pricePerDay << ")\n";
    }

    return 0;
}