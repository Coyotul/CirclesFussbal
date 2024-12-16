/**
 * @mainpage main.cpp
 * @brief Main entry point for the game application.
 *
 * This file initializes the game application, sets up the game scene,
 * and creates the player and terrain objects. It also creates and displays
 * the main game view using `QGraphicsView`.
 *
 * The main function initializes the QApplication, sets up the game scene with
 * terrain and player objects, and starts the event loop.
 */

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "PlayerObjects.h"
#include "TerrainObjects.h"
#include "Command.h"

 /**
  * @brief Main entry point for the game application.
  *
  * Initializes the game, sets up the scene and objects, and starts the event loop.
  *
  * @param argc Number of command-line arguments.
  * @param argv Array of command-line arguments.
  * @return int Exit status of the application.
  */
int main(int argc, char* argv[]) {
    // Initialize the QApplication
    QApplication app(argc, argv);

    // Produce the game instance (assumes IGame::Produce() creates a game object)
    auto game = IGame::Produce();

    // Create a new game scene and set the game for it
    GameScene* scene = new GameScene();
    scene->SetGame(game);
    scene->setSceneRect(-300, -300, 1200, 800); // Set the scene rectangle size and position

    // Instantiate terrain and player objects
    TerrainObjects terrain(scene);
    PlayerObjects player(scene);

    // Set the reset function for player positions
    scene->SetResetFunction(std::bind(&PlayerObjects::ResetPositions, &player, scene));

    // Create the QGraphicsView to display the scene
    QGraphicsView view(scene);
    view.setRenderHint(QPainter::Antialiasing); // Enable anti-aliasing for smoother graphics
    view.setSceneRect(-300, -300, 1200, 800);  // Set the view rectangle to match the scene
    view.show(); // Show the view

    // Start the application's event loop
    return app.exec();
}
