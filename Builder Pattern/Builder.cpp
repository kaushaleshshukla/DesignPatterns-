#include <iostream>
#include <string>

// Product
class House {
public:
    std::string walls;
    std::string roof;
    std::string doors;
    bool hasGarage = false;
    bool hasPool = false;
    bool hasGarden = false;

    void show() const {
        std::cout << "House with " << walls << " walls, "
                  << roof << " roof, " << doors << " doors";
        if (hasGarage) std::cout << ", garage";
        if (hasPool) std::cout << ", pool";
        if (hasGarden) std::cout << ", garden";
        std::cout << std::endl;
    }
};

// Builder Interface
class HouseBuilder {
public:
    virtual ~HouseBuilder() = default;
    virtual void reset() = 0;
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual void buildDoors() = 0;
    virtual void buildGarage() = 0;
    virtual void buildPool() = 0;
    virtual void buildGarden() = 0;
};

// Concrete Builder: Wooden House
class WoodenHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    WoodenHouseBuilder() { reset(); }
    void reset() override { house = House(); }

    void buildWalls() override { house.walls = "wooden"; }
    void buildRoof() override { house.roof = "wooden shingle"; }
    void buildDoors() override { house.doors = "wooden"; }
    void buildGarage() override { house.hasGarage = true; }
    void buildPool() override { house.hasPool = true; }
    void buildGarden() override { house.hasGarden = true; }

    House getResult() {
        House result = house;
        reset();
        return result;
    }
};

// Concrete Builder: Stone House
class StoneHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    StoneHouseBuilder() { reset(); }
    void reset() override { house = House(); }

    void buildWalls() override { house.walls = "stone"; }
    void buildRoof() override { house.roof = "slate tile"; }
    void buildDoors() override { house.doors = "iron-reinforced"; }
    void buildGarage() override { house.hasGarage = true; }
    void buildPool() override { house.hasPool = true; }
    void buildGarden() override { house.hasGarden = true; }

    House getResult() {
        House result = house;
        reset();
        return result;
    }
};

// Director: Knows HOW to build, delegates WHAT to the builder
class Director {
public:
    void constructSimpleHouse(HouseBuilder &builder) {
        builder.reset();
        builder.buildWalls();
        builder.buildRoof();
        builder.buildDoors();
    }

    void constructLuxuryHouse(HouseBuilder &builder) {
        builder.reset();
        builder.buildWalls();
        builder.buildRoof();
        builder.buildDoors();
        builder.buildGarage();
        builder.buildPool();
        builder.buildGarden();
    }
};

int main() {
    Director director;

    // Build a simple wooden house via director
    WoodenHouseBuilder woodenBuilder;
    director.constructSimpleHouse(woodenBuilder);
    House simpleWooden = woodenBuilder.getResult();
    std::cout << "Simple wooden: ";
    simpleWooden.show();

    // Build a luxury stone house via director
    StoneHouseBuilder stoneBuilder;
    director.constructLuxuryHouse(stoneBuilder);
    House luxuryStone = stoneBuilder.getResult();
    std::cout << "Luxury stone:  ";
    luxuryStone.show();

    // Build a custom house without director (client drives steps)
    woodenBuilder.buildWalls();
    woodenBuilder.buildRoof();
    woodenBuilder.buildDoors();
    woodenBuilder.buildGarden();
    House customWooden = woodenBuilder.getResult();
    std::cout << "Custom wooden:  ";
    customWooden.show();

    return 0;
}
