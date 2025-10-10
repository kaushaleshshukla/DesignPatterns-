/*
 * ConcreteCommand.cpp
 * 
 * CONCRETE COMMAND COMPONENT
 * ==========================
 * 
 * Concrete Command classes implement the Command interface and define 
 * the binding between a Receiver object and an action. They store the 
 * receiver and invoke corresponding operations when execute() is called.
 * 
 * Responsibilities:
 * - Store reference to receiver object
 * - Implement execute() by calling appropriate receiver methods
 * - Store state needed for undoing operations
 * - Act as bridge between invoker and receiver
 */

#include "CommandInterface.h"
#include "Receiver.cpp"
#include <iostream>
#include <string>

/**
 * Light On Command
 * 
 * Concrete command to turn on a light. Demonstrates basic command
 * implementation with receiver delegation.
 */
class LightOnCommand : public Command {
private:
    Light* light;  // Reference to receiver
    
public:
    /**
     * Constructor - stores reference to receiver
     */
    LightOnCommand(Light* l) : light(l) {}
    
    /**
     * Execute command by delegating to receiver
     */
    void execute() override {
        light->on();
    }
    
    /**
     * Undo by turning light off
     */
    void undo() override {
        light->off();
    }
    
    std::string getDescription() const override {
        return "Light On Command";
    }
};

/**
 * Light Off Command
 * 
 * Concrete command to turn off a light.
 */
class LightOffCommand : public Command {
private:
    Light* light;
    
public:
    LightOffCommand(Light* l) : light(l) {}
    
    void execute() override {
        light->off();
    }
    
    void undo() override {
        light->on();
    }
    
    std::string getDescription() const override {
        return "Light Off Command";
    }
};

/**
 * Light Dim Command
 * 
 * Command with parameters - demonstrates storing state for undo.
 */
class LightDimCommand : public Command {
private:
    Light* light;
    int dimLevel;
    int previousLevel;  // Store for undo
    
public:
    LightDimCommand(Light* l, int level) 
        : light(l), dimLevel(level), previousLevel(0) {}
    
    void execute() override {
        previousLevel = light->getCurrentLevel();
        light->dim(dimLevel);
    }
    
    void undo() override {
        light->dim(previousLevel);
    }
    
    std::string getDescription() const override {
        return "Light Dim Command (level: " + 
               std::to_string(dimLevel) + ")";
    }
};

/**
 * Stereo On Command
 * 
 * More complex command that performs multiple operations on receiver.
 */
class StereoOnWithCDCommand : public Command {
private:
    Stereo* stereo;
    
public:
    StereoOnWithCDCommand(Stereo* s) : stereo(s) {}
    
    void execute() override {
        stereo->on();
        stereo->setCD();
        stereo->setVolume(11);
    }
    
    void undo() override {
        stereo->off();
    }
    
    std::string getDescription() const override {
        return "Stereo On with CD Command";
    }
};

/**
 * Stereo Off Command
 */
class StereoOffCommand : public Command {
private:
    Stereo* stereo;
    
public:
    StereoOffCommand(Stereo* s) : stereo(s) {}
    
    void execute() override {
        stereo->off();
    }
    
    void undo() override {
        stereo->on();
        stereo->setCD();
        stereo->setVolume(11);
    }
    
    std::string getDescription() const override {
        return "Stereo Off Command";
    }
};

/**
 * Garage Door Open Command
 */
class GarageDoorOpenCommand : public Command {
private:
    GarageDoor* garageDoor;
    
public:
    GarageDoorOpenCommand(GarageDoor* gd) : garageDoor(gd) {}
    
    void execute() override {
        garageDoor->open();
    }
    
    void undo() override {
        garageDoor->close();
    }
    
    std::string getDescription() const override {
        return "Garage Door Open Command";
    }
};

/**
 * Garage Door Close Command
 */
class GarageDoorCloseCommand : public Command {
private:
    GarageDoor* garageDoor;
    
public:
    GarageDoorCloseCommand(GarageDoor* gd) : garageDoor(gd) {}
    
    void execute() override {
        garageDoor->close();
    }
    
    void undo() override {
        garageDoor->open();
    }
    
    std::string getDescription() const override {
        return "Garage Door Close Command";
    }
};

/**
 * Ceiling Fan Command
 * 
 * Demonstrates state management for multi-level operations.
 */
class CeilingFanHighCommand : public Command {
private:
    CeilingFan* ceilingFan;
    int prevSpeed;  // Store previous speed for undo
    
public:
    CeilingFanHighCommand(CeilingFan* cf) : ceilingFan(cf) {}
    
    void execute() override {
        prevSpeed = ceilingFan->getSpeed();
        ceilingFan->high();
    }
    
    void undo() override {
        switch (prevSpeed) {
            case CeilingFan::HIGH:
                ceilingFan->high();
                break;
            case CeilingFan::MEDIUM:
                ceilingFan->medium();
                break;
            case CeilingFan::LOW:
                ceilingFan->low();
                break;
            case CeilingFan::OFF:
            default:
                ceilingFan->off();
                break;
        }
    }
    
    std::string getDescription() const override {
        return "Ceiling Fan High Command";
    }
};

/**
 * Party Mode Command
 * 
 * Complex command that coordinates multiple receivers.
 */
class PartyModeCommand : public Command {
private:
    Light* light;
    Stereo* stereo;
    
public:
    PartyModeCommand(Light* l, Stereo* s) : light(l), stereo(s) {}
    
    void execute() override {
        std::cout << "Setting up party mode..." << std::endl;
        light->dim(20);  // Dim lighting
        stereo->on();
        stereo->setCD();
        stereo->setVolume(15);  // Party volume!
    }
    
    void undo() override {
        std::cout << "Turning off party mode..." << std::endl;
        light->on();  // Full brightness
        stereo->off();
    }
    
    std::string getDescription() const override {
        return "Party Mode Command";
    }
};