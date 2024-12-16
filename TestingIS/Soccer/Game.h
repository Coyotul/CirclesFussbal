#pragma once
#include <iostream>
#include <vector>

#include "EPlayer.h"
#include "IGame.h"
#include "IGameListener.h"

/**
 * @class Game
 * @brief Implements the `IGame` interface, representing the logic and state of the game.
 *
 * The `Game` class manages the players, ball, score, and game state. It provides methods
 * to switch players, reset the game, update the score, and notify listeners when the game is won.
 */
class Game : public IGame
{
private:
    Post m_postOne; ///< Represents the first post in the game.
    Post m_postTwo; ///< Represents the second post in the game.

    std::pair<float, float> m_ballCoord; ///< Coordinates of the ball in the game.

    std::vector<EPlayer> m_playerObjects; ///< A collection of players in the game.

    EPlayer m_currentPlayer; ///< The current player in the game.
    uint16_t m_scorePlayerOne; ///< Score for Player One.
    uint16_t m_scorePlayerTwo; ///< Score for Player Two.

    std::vector<std::weak_ptr<IGameListener>> m_listeners; ///< A list of listeners for game events.

public:

    /**
     * @brief Constructs a new `Game` object, initializing the game state.
     *
     * Initializes the game
     */
    Game();

    /**
     * @brief Switches the active player in the game.
     *
     * This method changes the current player to the other player in the game.
     */
    void SwitchPlayers() override;

    /**
     * @brief Resets the game to its initial state.
     *
     * Resets the positions, scores, and state of the game, making it ready for a new round.
     */
    void ResetGame() override;

    /**
     * @brief Updates the score for a player.
     * @param scoredOn The player who scored.
     *
     * Increases the score for the specified player.
     */
    void UpdateScore(EPlayer scoredOn) override;

    /**
     * @brief Gets the current player in the game.
     * @return The current player.
     */
    EPlayer GetCurrentPlayer() const override;

    /**
     * @brief Gets a list of player objects in the game.
     * @return A vector containing the player objects.
     */
    std::vector<EPlayer> GetPlayerObjects() const override;

    /**
     * @brief Adds a listener to the game.
     * @param gameListener Pointer to the listener to be added.
     *
     * This method allows external objects to listen for game events, such as when a player wins.
     */
    void AddListener(IGameListener* gameListener) override;

    /**
     * @brief Removes a listener from the game.
     * @param gameListener Pointer to the listener to be removed.
     *
     * This method stops the specified listener from receiving game events.
     */
    void RemoveListener(IGameListener* gameListener) override;

    /**
     * @brief Notifies all listeners that the game has been won.
     *
     * This method triggers the `OnWin` event in all the listeners when the game is won.
     */
    void NotifyListenersOnWin() override;
};
