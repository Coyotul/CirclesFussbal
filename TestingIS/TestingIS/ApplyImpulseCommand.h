#include "Command.h"
#include "DraggableCircle.h"
#include <QPointF>

/**
 * @class ApplyImpulseCommand
 * @brief Command to apply an impulse to a DraggableCircle.
 *
 * This class is a concrete implementation of the Command pattern. It encapsulates the action of applying an impulse
 * to a DraggableCircle object. The command can be executed to modify the state of the circle by applying the specified impulse.
 */
class ApplyImpulseCommand : public Command {
    /// Pointer to the DraggableCircle that the impulse will be applied to.
    DraggableCircle* circle;

    /// The impulse to apply, represented as a QPointF (x, y).
    QPointF impulse;

public:
    /**
     * @brief Constructor for the ApplyImpulseCommand class.
     *
     * Initializes the command with the DraggableCircle and the impulse to be applied.
     *
     * @param circle The DraggableCircle object to apply the impulse to.
     * @param imp The impulse to apply, represented as a QPointF.
     */
    ApplyImpulseCommand(DraggableCircle* circle, QPointF imp)
        : circle(circle), impulse(imp) {
    }

    /**
     * @brief Executes the command to apply the impulse to the DraggableCircle.
     *
     * This method applies the stored impulse to the circle by calling the `applyImpulse` method on the circle.
     */
    void execute() override {
        circle->applyImpulse(impulse);
    }
};
