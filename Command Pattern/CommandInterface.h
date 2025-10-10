/*
 * CommandInterface.h
 * 
 * COMMAND INTERFACE COMPONENT
 * ===========================
 * 
 * The Command interface defines a contract for executing an operation.
 * It provides a common interface for all concrete commands, ensuring
 * they can be executed uniformly and enabling polymorphic behavior.
 * 
 * Purpose:
 * - Provides common interface for all concrete commands
 * - Ensures all commands can be executed uniformly  
 * - Enables polymorphic behavior
 * - Supports undoable operations (optional)
 */

#ifndef COMMAND_INTERFACE_H
#define COMMAND_INTERFACE_H

#include <iostream>

/**
 * Abstract Command Interface
 * 
 * This is the core interface that all concrete commands must implement.
 * It defines the contract for command execution and optional undo 
 * functionality.
 */
class Command {
public:
    /**
     * Virtual destructor to ensure proper cleanup of derived classes
     */
    virtual ~Command() = default;
    
    /**
     * Execute the command
     * 
     * This method contains the logic to perform the requested operation.
     * Concrete commands will implement this to delegate work to receivers.
     */
    virtual void execute() = 0;
    
    /**
     * Undo the command (optional)
     * 
     * This method reverses the operation performed by execute().
     * Not all commands need to support undo functionality.
     */
    virtual void undo() = 0;
    
    /**
     * Get description of the command (optional)
     * 
     * Useful for debugging, logging, or displaying command history.
     */
    virtual std::string getDescription() const {
        return "Generic Command";
    }
};

/**
 * No Operation Command
 * 
 * A null object implementation that does nothing when executed.
 * Useful as a default command or placeholder.
 */
class NoCommand : public Command {
public:
    void execute() override {
        // Do nothing
    }
    
    void undo() override {
        // Do nothing  
    }
    
    std::string getDescription() const override {
        return "No Command";
    }
};

/**
 * Macro Command
 * 
 * A command that executes multiple commands in sequence.
 * Useful for creating complex operations from simple commands.
 */
class MacroCommand : public Command {
private:
    Command** commands;
    int commandCount;
    
public:
    MacroCommand(Command** cmds, int count) 
        : commands(cmds), commandCount(count) {}
    
    void execute() override {
        for (int i = 0; i < commandCount; i++) {
            if (commands[i] != nullptr) {
                commands[i]->execute();
            }
        }
    }
    
    void undo() override {
        // Undo in reverse order
        for (int i = commandCount - 1; i >= 0; i--) {
            if (commands[i] != nullptr) {
                commands[i]->undo();
            }
        }
    }
    
    std::string getDescription() const override {
        return "Macro Command (" + std::to_string(commandCount) + " commands)";
    }
};

#endif // COMMAND_INTERFACE_H