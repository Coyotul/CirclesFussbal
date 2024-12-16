#include "Command.h"
#include "DraggableCircle.h"
#include <QPointF>

/**
 * @class MoveCircleCommand
 * @brief A concrete command to move a DraggableCircle to a new position.
 *
 * This class is a concrete implementation of the Command pattern. It moves a DraggableCircle to a specified
 * position when the `execute()` method is called. The class holds a reference to the circle and its new position,
 * encapsulating the action of moving the circle into a command object.
 */
class MoveCircleCommand : public Command {
    DraggableCircle* circle; ///< Pointer to the DraggableCircle that will be moved
    QPointF newPosition; ///< The new position to move the circle to

public:
    /**
     * @brief Constructs a MoveCircleCommand object.
     *
     * Initializes the command with the DraggableCircle to be moved and the new position.
     *
     * @param circle The DraggableCircle that will be moved.
     * @param newPos The new position to move the circle to.
     */
    MoveCircleCommand(DraggableCircle* circle, QPointF newPos)
        : circle(circle), newPosition(newPos) {
    }

    /**
     * @brief Executes the move command.
     *
     * Moves the specified DraggableCircle to the new position.
     */
    void execute() override {
        circle->setPos(newPosition);
    }
};
