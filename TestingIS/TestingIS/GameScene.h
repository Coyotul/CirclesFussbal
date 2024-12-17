#pragma once
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include "DraggableCircle.h"
#include "IGame.h"
#include "IGameListener.h"
#include "Command.h"
#include <QGraphicsTextItem>

/**
 * @class GameScene
 * @brief A scene representing the game environment where the user interacts with draggable circles (players and ball).
 *
 * This class extends QGraphicsScene and implements IGameListener. It handles user input through mouse events, manages the
 * game state, and updates the scene regularly. It allows players to drag circles and apply impulses to them.
 */
class GameScene : public QGraphicsScene, public IGameListener {
    Q_OBJECT

public:
    /**
     * @brief Constructs a GameScene object and initializes the timer for updating circle positions.
     * @param parent The parent object for this scene.
     */
    GameScene(QObject* parent = nullptr) : QGraphicsScene(parent) {
        // Timer to update positions continuously
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &GameScene::updateCircles);
        timer->start(16); // ~60 FPS
    }

    /**
     * @brief Destructor for the GameScene.
     */
    ~GameScene() override = default;

    /**
     * @brief Sets the game instance associated with this scene.
     * @param game A shared pointer to the game object.
     */
    void SetGame(std::shared_ptr<IGame> game);

    /**
     * @brief Callback function triggered when the game ends in a win.
     */
    void OnWin() override;

    /**
     * @brief Sets the pointer to the left goal item in the scene.
     * @param leftGoal The left goal QGraphicsRectItem.
     */
    void SetLeftGoalPtr(QGraphicsRectItem* leftGoal);

    /**
     * @brief Sets the pointer to the right goal item in the scene.
     * @param rightGoal The right goal QGraphicsRectItem.
     */
    void SetRightGoalPtr(QGraphicsRectItem* rightGoal);

    /**
     * @brief Sets the function to reset the board when triggered.
     * @param ResetFunction A function that resets the board.
     */
    void SetResetFunction(std::function<void(GameScene*)> ResetFunction);

    /**
     * @brief Adds a command to the command queue for later execution.
     * @param command A shared pointer to the command to be added.
     */
    void addCommand(std::shared_ptr<Command> command);

    /**
     * @brief Executes all commands in the command queue.
     */
    void executeCommands();

    void SetScoreText(QGraphicsTextItem* scoreText);


protected:
    /**
     * @brief Handles mouse press events. Starts the drag or applies the impulse when the mouse is released.
     *
     * - Initiates the drag if a circle is clicked.
     * - Applies an impulse to the selected circle based on the drag distance.
     * @param event The mouse event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    /**
     * @brief Handles mouse release events, ending the drag operation.
     * @param event The mouse event.
     */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private slots:
    /**
     * @brief Updates the positions of circles in the scene and checks for goal scoring.
     */
    void updateCircles();

private:
    /**
     * @brief Checks if the ball is inside the left goal area.
     * @param ball The ball to check.
     * @param topLeft The top left corner of the goal area.
     * @param bottomLeft The bottom left corner of the goal area.
     * @return True if the ball is in the left goal area.
     */
    bool isBallInLeftGoal(const DraggableCircle* ball, const QPointF& topLeft, const QPointF& bottomLeft);

    /**
     * @brief Checks if the ball is inside the right goal area.
     * @param ball The ball to check.
     * @param topRight The top right corner of the goal area.
     * @param bottomRight The bottom right corner of the goal area.
     * @return True if the ball is in the right goal area.
     */
    bool isBallInRightGoal(const DraggableCircle* ball, const QPointF& topRight, const QPointF& bottomRight);

    /**
     * @brief Resets the board by clearing the scene and adding new circles (players and ball).
     */
    void ResetBoard();

    /**
     * @brief Clears all items from the scene and frees the memory associated with them.
     */
    void clearScene();


private:
    std::shared_ptr<IGame> m_game; ///< The game instance associated with the scene.
    QGraphicsRectItem* m_leftGoal = nullptr; ///< Pointer to the left goal in the scene.
    QGraphicsRectItem* m_rightGoal = nullptr; ///< Pointer to the right goal in the scene.
    std::function<void(GameScene*)> m_ResetFunction; ///< Function to reset the board.
    
    std::vector<std::shared_ptr<Command>> commandQueue; ///< The command queue for queued actions.

    bool m_leftGoalScored = false;  ///< Tracks if the left-side goal has been scored.
    bool m_rightGoalScored = false; ///< Tracks if the right-side goal has been scored.


    QGraphicsTextItem* m_scoreText;

    int player1Score = 0, player2Score = 0;

    bool isDragging = false; ///< Indicates whether a circle is being dragged.
    QPointF initialMousePos; ///< The initial mouse position when dragging starts.
    DraggableCircle* activeCircle = nullptr; ///< The circle currently being dragged.
};
