#include "PlayerObjects.h"

void PlayerObjects::Init(GameScene* gameScene)
{

#pragma region PlayersDeclaration
	//Red Team
	//Def
	DraggableCircle* redDef1 = new DraggableCircle(-80, -160, 60, false);
	DraggableCircle* redDef2 = new DraggableCircle(-80, 240, 60, false);
	DraggableCircle* redDef3 = new DraggableCircle(-80, 40, 60, false);
	redDef1->setColor(Qt::red);
	redDef2->setColor(Qt::red);
	redDef3->setColor(Qt::red);
	m_players.emplace_back(redDef1);
	m_players.emplace_back(redDef2);
	m_players.emplace_back(redDef3);
	//Att
	DraggableCircle* redAtt1 = new DraggableCircle(120, -80, 60, false);
	DraggableCircle* redAtt2 = new DraggableCircle(120, 160, 60, false);
	redAtt1->setColor(Qt::red);
	redAtt2->setColor(Qt::red);
	m_players.emplace_back(redAtt1);
	m_players.emplace_back(redAtt2);


	//Blue Team
	//Def
	DraggableCircle* blueAtt1 = new DraggableCircle(450, 160, 60, false);
	DraggableCircle* blueAtt2 = new DraggableCircle(450, -80, 60, false);
	blueAtt1->setColor(Qt::blue);
	blueAtt2->setColor(Qt::blue);
	m_players.emplace_back(blueAtt1);
	m_players.emplace_back(blueAtt2);
	//Att
	DraggableCircle* blueDef1 = new DraggableCircle(620, -180, 60, false);
	DraggableCircle* blueDef2 = new DraggableCircle(620, 40, 60, false);
	DraggableCircle* blueDef3 = new DraggableCircle(620, 240, 60, false);
	blueDef1->setColor(Qt::blue);
	blueDef2->setColor(Qt::blue);
	blueDef3->setColor(Qt::blue);
	m_players.emplace_back(blueDef1);
	m_players.emplace_back(blueDef2);
	m_players.emplace_back(blueDef3);

    m_scoreText = new QGraphicsTextItem("Red: 0 - Blue: 0");
    m_scoreText->setFont(QFont("Arial", 24));
    m_scoreText->setDefaultTextColor(Qt::white);
    m_scoreText->setPos(180, -300);

    gameScene->addItem(m_scoreText);
    gameScene->SetScoreText(m_scoreText);
#pragma endregion

	//ball
	m_ball = new DraggableCircle(279, 79, 50, true);
	m_ball->setColor(Qt::white);


	for (size_t i = 0; i < m_players.size(); i++)
	{
		gameScene->addItem(m_players[i]);
		gameScene->addItem(m_ball);
	}
}

void PlayerObjects::UpdateScore(int redScore, int blueScore)
{
	m_scoreText->setPlainText("Red: " + QString::number(redScore) + " - Blue: " + QString::number(blueScore));
}

PlayerObjects::PlayerObjects(GameScene* gameScene)
{
	Init(gameScene);
}

void PlayerObjects::ResetPositions(GameScene* gameScene)
{
    // Clear the vector to ensure no dangling pointers remain
    m_players.clear();

    // Reinitialize players and ball
#pragma region PlayersDeclaration
// Red Team
// Defenders
    DraggableCircle* redDef1 = new DraggableCircle(-80, -160, 60, false);
    DraggableCircle* redDef2 = new DraggableCircle(-80, 240, 60, false);
    DraggableCircle* redDef3 = new DraggableCircle(-80, 40, 60, false);
    redDef1->setColor(Qt::red);
    redDef2->setColor(Qt::red);
    redDef3->setColor(Qt::red);
    m_players.emplace_back(redDef1);
    m_players.emplace_back(redDef2);
    m_players.emplace_back(redDef3);

    // Attackers
    DraggableCircle* redAtt1 = new DraggableCircle(120, -80, 60, false);
    DraggableCircle* redAtt2 = new DraggableCircle(120, 160, 60, false);
    redAtt1->setColor(Qt::red);
    redAtt2->setColor(Qt::red);
    m_players.emplace_back(redAtt1);
    m_players.emplace_back(redAtt2);

    // Blue Team
    // Attackers
    DraggableCircle* blueAtt1 = new DraggableCircle(450, 160, 60, false);
    DraggableCircle* blueAtt2 = new DraggableCircle(450, -80, 60, false);
    blueAtt1->setColor(Qt::blue);
    blueAtt2->setColor(Qt::blue);
    m_players.emplace_back(blueAtt1);
    m_players.emplace_back(blueAtt2);

    // Defenders
    DraggableCircle* blueDef1 = new DraggableCircle(620, -180, 60, false);
    DraggableCircle* blueDef2 = new DraggableCircle(620, 40, 60, false);
    DraggableCircle* blueDef3 = new DraggableCircle(620, 240, 60, false);
    blueDef1->setColor(Qt::blue);
    blueDef2->setColor(Qt::blue);
    blueDef3->setColor(Qt::blue);
    m_players.emplace_back(blueDef1);
    m_players.emplace_back(blueDef2);
    m_players.emplace_back(blueDef3);
#pragma endregion

    // Ball
    m_ball = new DraggableCircle(279, 79, 50, true);

    // Add items to the scene
    gameScene->addItem(m_ball);

    for (size_t i = 0; i < m_players.size(); i++) {
        gameScene->addItem(m_players[i]);
    }
}

DraggableCircle* PlayerObjects::GetBall()
{
	return m_ball;
}


