#include "Command.h"
#include "DraggableCircle.h"
#include <QPointF>

class ApplyImpulseCommand : public Command {
    DraggableCircle* circle;
    QPointF impulse;
public:
    ApplyImpulseCommand(DraggableCircle* circle, QPointF imp)
        : circle(circle), impulse(imp) {}

    void execute() override {
        circle->applyImpulse(impulse);
    }
};