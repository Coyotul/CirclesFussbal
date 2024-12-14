#include "Command.h"
#include "DraggableCircle.h"
#include <QPointF>

class MoveCircleCommand : public Command {
    DraggableCircle* circle;
    QPointF newPosition;
public:
    MoveCircleCommand(DraggableCircle* circle, QPointF newPos)
        : circle(circle), newPosition(newPos) {}

    void execute() override {
        circle->setPos(newPosition);
    }
};



