#include "Game.h"
#include "pch.h"
#include "IGameListener.h"
#include "EPlayer.h"
#include "IGame.h"

using ::testing::_;
using ::testing::Exactly;

/**
 * @brief Mock class for IGameListener
 *
 * This mock class is used to simulate the `IGameListener` interface during unit tests.
 * It allows us to test how the `Game` class interacts with listeners without needing a real implementation.
 */
class MockGameListener : public IGameListener {
public:
    MOCK_METHOD(void, OnWin, (), (override));
};

/**
 * @class GameTest
 * @brief A test fixture class for testing the `Game` class.
 *
 * This class sets up a test environment where the `Game` class can be tested with mock listeners.
 * Each test case is executed within this fixture to verify the behavior of the `Game` class.
 */
class GameTest : public ::testing::Test {
protected:
    /**
     * @brief Sets up the test environment.
     *
     * This function runs before each test, initializing a new game instance.
     */
    void SetUp() override {
        game = IGame::Produce();
    }

    std::shared_ptr<IGame> game; ///< The game instance being tested.
};

// Test for initial state
TEST_F(GameTest, InitialState) {
    EXPECT_EQ(game->GetCurrentPlayer(), EPlayer::PLAYER1);
    EXPECT_EQ(game->GetPlayerObjects().size(), 0);
}

// Test for player switching
TEST_F(GameTest, SwitchPlayers) {
    game->SwitchPlayers();
    EXPECT_EQ(game->GetCurrentPlayer(), EPlayer::PLAYER2);

    game->SwitchPlayers();
    EXPECT_EQ(game->GetCurrentPlayer(), EPlayer::PLAYER1);
}

// Test for game reset
TEST_F(GameTest, ResetGame) {
    game->SwitchPlayers();
    game->UpdateScore(EPlayer::PLAYER1);
    game->UpdateScore(EPlayer::PLAYER2);

    game->ResetGame();
    EXPECT_EQ(game->GetCurrentPlayer(), EPlayer::PLAYER1);
    EXPECT_EQ(game->GetPlayerObjects().size(), 0);
}

// Test for score updating
TEST_F(GameTest, UpdateScore) {
    game->UpdateScore(EPlayer::PLAYER1);
    game->UpdateScore(EPlayer::PLAYER2);
    game->UpdateScore(EPlayer::PLAYER2);

    EXPECT_EQ(game->GetCurrentPlayer(), EPlayer::PLAYER1);
}
