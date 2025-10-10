/*
 * Invoker.cpp
 * 
 * INVOKER COMPONENT
 * =================
 * 
 * The Invoker holds commands and can make requests by calling the 
 * command's execute() method. It doesn't know anything about the 
 * concrete command or the receiver.
 * 
 * Responsibilities:
 * - Store command objects
 * - Trigger command execution
 * - Support features like macro commands, queuing, logging
 * - Maintain command history for undo functionality
 * - Remain decoupled from specific command implementations
 */

#include "CommandInterface.h"
#include <iostream>
#include <vector>
#include <stack>

/**
 * Remote Control Invoker
 * 
 * A simple remote control invoker that can store and execute commands.
 */
class RemoteControl {
private:
    static const int NUM_SLOTS = 7;
    Command* onCommands[NUM_SLOTS];
    Command* offCommands[NUM_SLOTS];
    Command* undoCommand;
    NoCommand* noCommand;
    
public:
    /**
     * Constructor - initialize all slots with NoCommand
     */
    RemoteControl() {
        noCommand = new NoCommand();
        undoCommand = noCommand;
        
        for (int i = 0; i < NUM_SLOTS; i++) {
            onCommands[i] = noCommand;
            offCommands[i] = noCommand;
        }
    }
    
    /**
     * Destructor
     */
    ~RemoteControl() {
        delete noCommand;
    }
    
    /**
     * Set command for a specific slot
     */
    void setCommand(int slot, Command* onCommand, Command* offCommand) {
        if (slot >= 0 && slot < NUM_SLOTS) {
            onCommands[slot] = onCommand;
            offCommands[slot] = offCommand;
        }
    }
    
    /**
     * Execute on command for specified slot
     */
    void onButtonWasPushed(int slot) {
        if (slot >= 0 && slot < NUM_SLOTS) {
            onCommands[slot]->execute();
            undoCommand = onCommands[slot];
        }
    }
    
    /**
     * Execute off command for specified slot
     */
    void offButtonWasPushed(int slot) {
        if (slot >= 0 && slot < NUM_SLOTS) {
            offCommands[slot]->execute();
            undoCommand = offCommands[slot];
        }
    }
    
    /**
     * Undo the last executed command
     */
    void undoButtonWasPushed() {
        undoCommand->undo();
    }
    
    /**
     * Display current remote configuration
     */
    void displayRemote() const {
        std::cout << "\n------ Remote Control ------" << std::endl;
        for (int i = 0; i < NUM_SLOTS; i++) {
            std::cout << "[slot " << i << "] " 
                      << onCommands[i]->getDescription()
                      << "    " 
                      << offCommands[i]->getDescription() 
                      << std::endl;
        }
        std::cout << "[undo] " 
                  << undoCommand->getDescription() << std::endl;
    }
};

/**
 * Command Queue Invoker
 * 
 * Invoker that can queue commands for batch execution.
 */
class CommandQueue {
private:
    std::vector<Command*> commandQueue;
    
public:
    /**
     * Add command to queue
     */
    void addCommand(Command* command) {
        if (command != nullptr) {
            commandQueue.push_back(command);
            std::cout << "Added command: " 
                      << command->getDescription() << std::endl;
        }
    }
    
    /**
     * Execute all commands in queue
     */
    void executeAll() {
        std::cout << "\nExecuting " << commandQueue.size() 
                  << " commands..." << std::endl;
        
        for (Command* command : commandQueue) {
            if (command != nullptr) {
                std::cout << "Executing: " 
                          << command->getDescription() << std::endl;
                command->execute();
            }
        }
        
        // Clear queue after execution
        commandQueue.clear();
        std::cout << "All commands executed." << std::endl;
    }
    
    /**
     * Clear the command queue
     */
    void clearQueue() {
        commandQueue.clear();
        std::cout << "Command queue cleared." << std::endl;
    }
    
    /**
     * Get queue size
     */
    size_t getQueueSize() const {
        return commandQueue.size();
    }
};

/**
 * Command History Invoker
 * 
 * Invoker that maintains a history of executed commands with 
 * unlimited undo capability.
 */
class CommandHistory {
private:
    std::stack<Command*> history;
    static const int MAX_HISTORY = 10;
    
public:
    /**
     * Execute command and add to history
     */
    void executeCommand(Command* command) {
        if (command != nullptr) {
            command->execute();
            history.push(command);
            
            // Limit history size
            if (history.size() > MAX_HISTORY) {
                // In a real implementation, you might want to 
                // manage memory more carefully here
                history.pop();
            }
            
            std::cout << "Command executed and added to history: " 
                      << command->getDescription() << std::endl;
        }
    }
    
    /**
     * Undo last command
     */
    void undo() {
        if (!history.empty()) {
            Command* lastCommand = history.top();
            history.pop();
            lastCommand->undo();
            std::cout << "Undone: " 
                      << lastCommand->getDescription() << std::endl;
        } else {
            std::cout << "No commands to undo!" << std::endl;
        }
    }
    
    /**
     * Get history size
     */
    size_t getHistorySize() const {
        return history.size();
    }
    
    /**
     * Clear history
     */
    void clearHistory() {
        while (!history.empty()) {
            history.pop();
        }
        std::cout << "Command history cleared." << std::endl;
    }
};
