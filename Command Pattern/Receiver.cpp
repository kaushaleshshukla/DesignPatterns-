/*
 * Receiver.cpp
 * 
 * RECEIVER COMPONENT
 * ==================
 * 
 * The Receiver is the object that performs the actual work when a 
 * command is executed. It knows how to carry out the operations 
 * associated with a request.
 * 
 * Characteristics:
 * - Contains the business logic for operations
 * - Independent of the command pattern structure
 * - Can be any object that knows how to perform requested operations
 * - Multiple commands can target the same receiver
 */

#include <iostream>
#include <string>

class Light {
private:
    std::string location;
    bool isOn;
    int currentLevel; 
    
public:
    /**
     * Constructor
     */
    Light(const std::string& loc) 
        : location(loc), isOn(false), currentLevel(0) {}
    
    /**
     * Turn light on
     */
    void on() {
        isOn = true;
        currentLevel = 100;
        std::cout << location << " light is ON (100%)" << std::endl;
    }
    
    /**
     * Turn light off
     */
    void off() {
        isOn = false;
        currentLevel = 0;
        std::cout << location << " light is OFF" << std::endl;
    }
    
    /**
     * Dim light to specific level
     */
    void dim(int level) {
        if (level >= 0 && level <= 100) {
            currentLevel = level;
            isOn = (level > 0);
            std::cout << location << " light dimmed to " 
                      << level << "%" << std::endl;
        }
    }
    
    /**
     * Get current brightness level
     */
    int getCurrentLevel() const {
        return currentLevel;
    }
    
    /**
     * Check if light is on
     */
    bool getIsOn() const {
        return isOn;
    }
};

/**
 * Stereo Receiver
 * 
 * Represents an audio system with multiple input sources and 
 * volume control.
 */
class Stereo {
private:
    std::string location;
    bool isOn;
    std::string currentInput;
    int volume;
    
public:
    /**
     * Constructor
     */
    Stereo(const std::string& loc) 
        : location(loc), isOn(false), currentInput(""), volume(0) {}
    
    /**
     * Turn stereo on
     */
    void on() {
        isOn = true;
        std::cout << location << " stereo is ON" << std::endl;
    }
    
    /**
     * Turn stereo off
     */
    void off() {
        isOn = false;
        volume = 0;
        currentInput = "";
        std::cout << location << " stereo is OFF" << std::endl;
    }
    
    /**
     * Set CD as input source
     */
    void setCD() {
        currentInput = "CD";
        std::cout << location << " stereo set to CD" << std::endl;
    }
    
    /**
     * Set DVD as input source
     */
    void setDVD() {
        currentInput = "DVD";
        std::cout << location << " stereo set to DVD" << std::endl;
    }
    
    /**
     * Set radio as input source
     */
    void setRadio() {
        currentInput = "Radio";
        std::cout << location << " stereo set to Radio" << std::endl;
    }
    
    /**
     * Set volume level
     */
    void setVolume(int vol) {
        if (vol >= 0 && vol <= 20) {
            volume = vol;
            std::cout << location << " stereo volume set to " 
                      << vol << std::endl;
        }
    }
    
    /**
     * Get current volume
     */
    int getVolume() const {
        return volume;
    }
};

/**
 * Garage Door Receiver
 * 
 * Represents an automated garage door system.
 */
class GarageDoor {
private:
    std::string location;
    bool isOpen;
    
public:
    /**
     * Constructor
     */
    GarageDoor(const std::string& loc) : location(loc), isOpen(false) {}
    
    /**
     * Open garage door
     */
    void open() {
        isOpen = true;
        std::cout << location << " garage door is opening..." 
                  << std::endl;
        std::cout << location << " garage door is open" 
                  << std::endl;
    }
    
    /**
     * Close garage door
     */
    void close() {
        isOpen = false;
        std::cout << location << " garage door is closing..." 
                  << std::endl;
        std::cout << location << " garage door is closed" 
                  << std::endl;
    }
    
    /**
     * Stop garage door movement
     */
    void stop() {
        std::cout << location << " garage door stopped" 
                  << std::endl;
    }
    
    /**
     * Turn on garage door light
     */
    void lightOn() {
        std::cout << location << " garage light is on" 
                  << std::endl;
    }
    
    /**
     * Turn off garage door light
     */
    void lightOff() {
        std::cout << location << " garage light is off" 
                  << std::endl;
    }
    
    /**
     * Check if door is open
     */
    bool getIsOpen() const {
        return isOpen;
    }
};

/**
 * Ceiling Fan Receiver
 * 
 * Represents a ceiling fan with multiple speed settings.
 */
class CeilingFan {
public:
    static const int OFF = 0;
    static const int LOW = 1;
    static const int MEDIUM = 2;
    static const int HIGH = 3;
    
private:
    std::string location;
    int speed;
    
public:
    /**
     * Constructor
     */
    CeilingFan(const std::string& loc) : location(loc), speed(OFF) {}
    
    /**
     * Set fan to high speed
     */
    void high() {
        speed = HIGH;
        std::cout << location << " ceiling fan is on HIGH" 
                  << std::endl;
    }
    
    /**
     * Set fan to medium speed
     */
    void medium() {
        speed = MEDIUM;
        std::cout << location << " ceiling fan is on MEDIUM" 
                  << std::endl;
    }
    
    /**
     * Set fan to low speed
     */
    void low() {
        speed = LOW;
        std::cout << location << " ceiling fan is on LOW" 
                  << std::endl;
    }
    
    /**
     * Turn fan off
     */
    void off() {
        speed = OFF;
        std::cout << location << " ceiling fan is OFF" 
                  << std::endl;
    }
    
    /**
     * Get current speed
     */
    int getSpeed() const {
        return speed;
    }
};

/**
 * Security System Receiver
 * 
 * Represents a home security system.
 */
class SecuritySystem {
private:
    std::string location;
    bool isArmed;
    
public:
    /**
     * Constructor
     */
    SecuritySystem(const std::string& loc) 
        : location(loc), isArmed(false) {}
    
    /**
     * Arm the security system
     */
    void arm() {
        isArmed = true;
        std::cout << location << " security system is ARMED" 
                  << std::endl;
    }
    
    /**
     * Disarm the security system
     */
    void disarm() {
        isArmed = false;
        std::cout << location << " security system is DISARMED" 
                  << std::endl;
    }
    
    /**
     * Check if system is armed
     */
    bool getIsArmed() const {
        return isArmed;
    }
};