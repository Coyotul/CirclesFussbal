#pragma once

#include <memory>

/**
 * @typedef IGameWeakPtr
 * @brief Alias for a weak pointer to an `IGameListener` object.
 *
 * This alias simplifies the use of a `std::weak_ptr` to an `IGameListener` object,
 * which allows for safe references without affecting the reference count.
 */
using IGameWeakPtr = std::weak_ptr<class IGameListener>;

/**
 * @class IGameListener
 * @brief Interface for a game listener.
 *
 * This interface allows classes to listen for game events, such as when the game is won.
 * It provides a method for handling the win event.
 */
class IGameListener
{
public:
    virtual ~IGameListener() = default;

    /**
     * @brief Called when the game is won.
     *
     * This function is triggered when a player wins the game. Implementations
     * should define the actions to take upon winning, such as updating the UI or scoring.
     */
    virtual void OnWin() = 0;
};
