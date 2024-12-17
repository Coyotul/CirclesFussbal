#pragma once

#include <vector>
#include "GameScene.h"
#include <QGraphicsTextItem>

/**
 * @class PlayerObjects
 * @brief Class representing player objects (circles) in the game, including players and the ball.
 *
 * This class manages the creation and positioning of player objects, which include both the players (represented by DraggableCircle objects)
 * and the ball. It provides methods to initialize player objects in a game scene, reset their positions, and retrieve the ball.
 */
class PlayerObjects
{
private:
    /// Vector holding the player circles (DraggableCircle objects).
    std::vector<DraggableCircle*> m_players;

    /// Pointer to the ball (DraggableCircle object).
    DraggableCircle* m_ball;

    /**
     * @brief Initializes the player objects and the ball in the provided game scene.
     *
     * This function sets up the initial positions of the players and the ball, adding them to the provided game scene.
     *
     * @param gameScene The GameScene object where the player objects will be added.
     */
    void Init(GameScene* gameScene);

    QGraphicsTextItem* m_scoreText;
    int m_redScore = 0;
    int m_blueScore = 0;

public:
    /**
     * @brief Constructor for PlayerObjects.
     *
     * This constructor initializes the player objects and adds them to the provided game scene.
     *
     * @param gameScene The GameScene object where the player objects will be added.
     */
    PlayerObjects(GameScene* gameScene);

    /**
     * @brief Resets the positions of all player objects and the ball.
     *
     * This function clears the previous player objects and ball from the scene and reinitializes them to their starting positions.
     *
     * @param gameScene The GameScene object where the player objects will be added after resetting.
     */
    void ResetPositions(GameScene* gameScene);

    void UpdateScore(int redScore, int blueScore);

    /**
     * @brief Gets the ball object.
     *
     * @return A pointer to the DraggableCircle representing the ball.
     */
    DraggableCircle* GetBall();
};
