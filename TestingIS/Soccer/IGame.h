#pragma once

#include <vector>
#include <memory>

enum class EPlayer;
class IGameListener;

/**
 * @class IGame
 * @brief Interface representing the game.
 *
 * This interface defines the basic operations of the game, including switching players,
 * notifying listeners, updating the score, and resetting the game.
 */
class IGame {
public:
    virtual ~IGame() = default;

    /**
     * @brief Gets the list of player objects in the game.
     * @return A vector of `EPlayer` values representing the players.
     */
    virtual std::vector<EPlayer> GetPlayerObjects() const = 0;

    /**
     * @brief Gets the current player.
     * @return The current player's identifier.
     */
    virtual EPlayer GetCurrentPlayer() const = 0;

    /**
     * @brief Creates and returns a shared pointer to an `IGame` instance.
     * @return A shared pointer to a new `IGame` instance.
     */
    static std::shared_ptr<IGame> Produce();

    /**
     * @brief Adds a listener to the game.
     * @param gameListener Pointer to the listener to be added.
     */
    virtual void AddListener(IGameListener* gameListener) = 0;

    /**
     * @brief Removes a listener from the game.
     * @param gameListener Pointer to the listener to be removed.
     */
    virtual void RemoveListener(IGameListener* gameListener) = 0;

    /**
     * @brief Switches the active player in the game.
     */
    virtual void SwitchPlayers() = 0;

    /**
     * @brief Notifies all listeners that a player has won.
     */
    virtual void NotifyListenersOnWin() = 0;

    /**
     * @brief Resets the game to its initial state.
     */
    virtual void ResetGame() = 0;

    /**
     * @brief Updates the score of a player.
     * @param scoredOn The player who scored.
     */
    virtual void UpdateScore(EPlayer scoredOn) = 0;
};

/**
 * @struct Post
 * @brief Represents a post with coordinates.
 *
 * This struct stores the coordinates of a postz.
 */
struct Post {
    float x;  ///< The x-coordinate of the post.
    float y1; ///< The first y-coordinate.
    float y2; ///< The second y-coordinate.
};
