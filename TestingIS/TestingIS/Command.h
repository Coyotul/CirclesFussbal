#pragma once

/**
 * @class Command
 * @brief Abstract base class for all command types.
 *
 * The Command class is an abstract base class for implementing the Command design pattern. It defines an interface
 * for executing commands. Concrete command classes will derive from this class and implement the `execute()` method
 * to perform specific actions.
 */
class Command {
public:
    /**
     * @brief Executes the command.
     *
     * This pure virtual function must be implemented by derived classes. It defines the action that will be
     * executed when the command is invoked.
     */
    virtual void execute() = 0;
};
