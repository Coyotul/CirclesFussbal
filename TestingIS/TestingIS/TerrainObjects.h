#pragma once
#include "GameScene.h"

/**
 * @class TerrainObjects
 * @brief Class representing the terrain objects (goals, middle line, etc.) in the game scene.
 *
 * This class manages the creation and positioning of various terrain elements in the game scene, such as the borders, goal areas,
 * middle line, and the large rectangles that define the playing area. It adds these objects to the provided GameScene.
 */
class TerrainObjects
{
public:
    /**
     * @brief Constructor for TerrainObjects.
     *
     * This constructor initializes the terrain objects (borders, goals, middle line, etc.) and adds them to the provided game scene.
     *
     * @param gameScene The GameScene object where the terrain objects will be added.
     */
    TerrainObjects(GameScene* gameScene);

private:
    /// Width of the goal area.
    qreal goalWidth = 100;

    /// Height of the goal area.
    qreal goalHeight = 200;

    /// Pointer to the rectangle representing the scene's border.
    QGraphicsRectItem* borderRect;

    /// Pointer to the line representing the middle of the playing field.
    QGraphicsLineItem* middleLine;

    /// X-coordinate of the middle line.
    qreal midX;

    /// Y-coordinate of the middle line.
    qreal midY;

    /// Pointer to the ellipse in the center of the scene.
    QGraphicsEllipseItem* middleEllipse;

    /// Pointer to the rectangle representing the left goal area.
    QGraphicsRectItem* leftGoal;

    /// Pointer to the rectangle representing the right goal area.
    QGraphicsRectItem* rightGoal;

    /// Pointer to the rectangle representing the left large area on the field.
    QGraphicsRectItem* leftBigRect;

    /// Pointer to the rectangle representing the right large area on the field.
    QGraphicsRectItem* rightBigRect;

    /// Width of the large rectangles.
    qreal bigRectWidth = 150;

    /// Height of the large rectangles.
    qreal bigRectHeight = 300;
};
