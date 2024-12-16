#pragma once
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <cmath>

#include "EPlayer.h"

/**
 * @class DraggableCircle
 * @brief A draggable circle in a Qt-based graphics scene with collision detection and physics handling.
 *
 * This class represents a circle that can be moved and manipulated within a Qt `QGraphicsScene`.
 * It supports collision detection, velocity handling, and external forces like impulses.
 * The circle can also be assigned to a player and visually rendered in the scene.
 */
class DraggableCircle : public QGraphicsObject {
    Q_OBJECT
        Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    /**
     * @brief Constructs a DraggableCircle object.
     *
     * @param x The x-coordinate of the circle's initial position.
     * @param y The y-coordinate of the circle's initial position.
     * @param width The width (and height) of the circle.
     * @param isBall Flag indicating if this circle is the ball.
     * @param parent The parent `QGraphicsItem`, default is `nullptr`.
     */
    DraggableCircle(qreal x, qreal y, qreal width, bool isBall, QGraphicsItem* parent = nullptr);

    /**
     * @brief Returns the bounding rectangle of the circle.
     *
     * This method is used for collision detection and rendering. It defines the clickable
     * and drawable area of the circle.
     *
     * @return A QRectF representing the bounds of the circle in local coordinates.
     */
    QRectF boundingRect() const override;

    /**
     * @brief Sets the color of the circle.
     *
     * This method allows setting the color of the circle. The color is used when painting
     * the circle on the scene. If the color is red, the circle is assigned to `PLAYER1`;
     * otherwise, it is assigned to `PLAYER2`.
     *
     * @param color The color to set for the circle.
     */
    void setColor(const QColor& color);

    /**
     * @brief Paints the circle on the scene.
     *
     * This method is responsible for rendering the circle on the scene with the assigned color.
     * It overrides the `QGraphicsObject::paint()` method.
     *
     * @param painter The painter used to render the circle.
     * @param option The style option for the item.
     * @param widget The widget on which the item is painted.
     */
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

    /**
     * @brief Updates the position of the circle and handles collisions.
     *
     * This method updates the position of the circle based on its current velocity. It checks for
     * collisions with the scene's boundaries and other items and responds accordingly. It also
     * applies friction to slow down the circle's velocity.
     */
    void updatePosition();

    /**
     * @brief Handles collision response between two draggable circles.
     *
     * This method calculates the response when this circle collides with another circle.
     * It uses basic physics principles to compute the collision normal, relative velocity,
     * impulse, and overlap correction.
     *
     * @param otherCircle The other circle involved in the collision.
     */
    void handleCollision(DraggableCircle* otherCircle);

    /**
     * @brief Applies an external force (impulse) to the circle.
     *
     * This method modifies the circle's velocity by adding the specified impulse vector,
     * which simulates an external force acting on the circle.
     *
     * @param impulse The impulse vector to apply to the circle's velocity.
     */
    void applyImpulse(const QPointF& impulse) {
        m_velocity += impulse;
    }

    /**
     * @brief Checks if the circle is the ball.
     *
     * @return `true` if this circle represents the ball; `false` otherwise.
     */
    bool isBall() const;

    /**
     * @brief Freezes the position of the circle.
     *
     * This method stops the circle's movement and disables dragging and focus. It is useful
     * for temporarily halting the circle's behavior, such as during pauses or game logic events.
     */
    void freezePosition();

    /**
     * @brief Unfreezes the position of the circle.
     *
     * This method re-enables the circle's movement, allowing it to be dragged and receive focus again.
     */
    void unfreezePosition();

    /**
     * @brief Gets the player associated with the circle.
     *
     * This method returns the player associated with the circle. The player is determined
     * by the circle's color.
     *
     * @return The player associated with the circle.
     */
    EPlayer GetPlayer() const;

private:
    qreal m_width, m_height; ///< The width and height of the circle.
    QColor m_color; ///< The color of the circle.
    QPointF m_velocity; ///< The velocity of the circle (used for movement).
    bool m_isBall; ///< Flag indicating if the circle is the ball.
    EPlayer m_player; ///< The player associated with the circle.
};
