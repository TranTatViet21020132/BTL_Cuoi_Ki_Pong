#include "game.h"

game::game() : ball(ballRadius), ballVelocity(sf::Vector2f(ballSpeed, 0.f)), leftBat(sf::Vector2f(30.f, 200.f)), rightBat(sf::Vector2f(30.f, 200.f)),
                m_paused(false), soundPlayed(false), predBall(ballRadius), predBallVel(sf::Vector2f(ballSpeed, 0.f)), selected(false), playType(false),
                player1(false), player2(false), victorySound(false)
{
	window.create(sf::VideoMode(screenWidth, screenHeight), "Pong");
    volume = 100;

	sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);

	font.loadFromFile("fonts/Peepo.ttf");
    texture.loadFromFile("images/gameBackground.png");
    background.setTexture(texture);

	scoreBoard.setFont(font);
	scoreBoard.setColor(sf::Color::White);
	scoreBoard.setString(static_cast<std::string>(scoreChar));
	scoreBoard.setPosition(screenWidth / 2.f - scoreBoard.getGlobalBounds().width / 2.f, 10.f);

	ballSpeedText.setFont(font);
	ballSpeedText.setString("Speed: " + std::to_string(static_cast<int>(ballSpeed / 10)));
	ballSpeedText.setColor(sf::Color::White);
	ballSpeedText.setCharacterSize(20);
	ballSpeedText.setPosition(screenWidth / 2.f - ballSpeedText.getGlobalBounds().width / 2.f, screenHeight - 50.f);

	ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
	leftBat.setPosition(sf::Vector2f(0.f, screenHeight / 2.f - batHeight / 2.f + 2));
	rightBat.setPosition(sf::Vector2f(screenWidth - batWidth, screenHeight / 2.f - batHeight / 2.f + 2));
	predBall.setPosition(sf::Vector2f(screenWidth - 20.f, screenHeight / 2.f));
	predBall.setFillColor(sf::Color::Blue);

	title.setFont(font);
	title.setString("Pong");
	title.setColor(sf::Color::White);
	title.setCharacterSize(50);
	title.setPosition(screenWidth / 2.f - (title.getGlobalBounds().width / 2.f), 50.f);

	//instructions
	instructionsTitle.setFont(font);
	instructionsTitle.setString("INSTRUCTIONS");
	instructionsTitle.setColor(sf::Color::White);
	instructionsTitle.setCharacterSize(50);
	instructionsTitle.setPosition(screenWidth / 2.f - (instructionsTitle.getGlobalBounds().width / 2.f), 50.f);

	instructionsContents.setFont(font);
	instructionsContents.setString("Case 1: Playing against another player:\n"
	                               "P1: Move up with W, move down with S.\n"
	                               "P2: Move up with Up key, move down with Down key.\n"
	                               "Case 2: Playing against an AI:\n"
	                               "Move up with W, move down with S.\n");
	instructionsContents.setColor(sf::Color::White);
	instructionsContents.setCharacterSize(25);
	instructionsContents.setPosition(screenWidth / 2.f - (instructionsContents.getGlobalBounds().width / 2.f), 150.f);

	//menu
	buttonPlay.setFont(font);
	buttonPlay.setString("1 vs 1");
	buttonPlay.setColor(sf::Color::White);
	buttonPlay.setPosition(screenWidth / 2.f - (buttonPlay.getGlobalBounds().width / 2.f), 180.f);

	buttonPlayAI.setFont(font);
	buttonPlayAI.setString("vs AI");
	buttonPlayAI.setColor(sf::Color::White);
	buttonPlayAI.setPosition(screenWidth / 2.f - (buttonPlayAI.getGlobalBounds().width / 2.f), 240.f);

	buttonOptions.setFont(font);
	buttonOptions.setString("OPTIONS");
	buttonOptions.setColor(sf::Color::White);
	buttonOptions.setPosition(screenWidth / 2.f - (buttonOptions.getGlobalBounds().width / 2.f), 300.f);

	buttonInstructions.setFont(font);
	buttonInstructions.setString("INSTRUCTIONS");
	buttonInstructions.setColor(sf::Color::White);
	buttonInstructions.setPosition(screenWidth / 2.f - (buttonInstructions.getGlobalBounds().width / 2.f), 360.f);

	buttonExit.setFont(font);
	buttonExit.setString("EXIT");
	buttonExit.setColor(sf::Color::White);
	buttonExit.setPosition(screenWidth / 2.f - (buttonExit.getGlobalBounds().width / 2.f), 420.f);

	//pause
	pauseBackground.setFillColor(sf::Color::Black);
	pauseBackground.setOutlineColor(sf::Color::Red);
	pauseBackground.setOutlineThickness(2.f);
	pauseBackground.setSize(sf::Vector2f(300.f, 150.f));
	pauseBackground.setPosition(screenWidth / 2.f - pauseBackground.getGlobalBounds().width / 2.f, screenHeight / 2.f - pauseBackground.getGlobalBounds().height / 2.f);

	pauseTitle.setFont(font);
	pauseTitle.setString("Pause");
	pauseTitle.setColor(sf::Color::White);
	pauseTitle.setPosition(screenWidth / 2.f - (pauseTitle.getGlobalBounds().width / 2.f), 180.f);

	pauseMenu.setFont(font);
	pauseMenu.setString("MENU");
	pauseMenu.setColor(sf::Color::White);
	pauseMenu.setCharacterSize(20);
	pauseMenu.setPosition(screenWidth / 2.f - (pauseMenu.getGlobalBounds().width / 2), 240.f);

	pauseExit.setFont(font);
	pauseExit.setString("EXIT");
	pauseExit.setColor(sf::Color::White);
	pauseExit.setCharacterSize(20);
	pauseExit.setPosition(screenWidth / 2.f - (pauseExit.getGlobalBounds().width / 2.f), 280.f);

	//options
	optionsTitle.setFont(font);
	optionsTitle.setString("OPTIONS");
	optionsTitle.setColor(sf::Color::White);
	optionsTitle.setCharacterSize(40);
	optionsTitle.setPosition(screenWidth / 2.f - optionsTitle.getGlobalBounds().width / 2.f, 50);

	buttonVolume.setFont(font);
	buttonVolume.setString("Volume: ");
	buttonVolume.setColor(sf::Color::White);
	buttonVolume.setCharacterSize(20);
	buttonVolume.setPosition(screenWidth / 2.f - 200.f, 150.f);

	buttonFullscreen.setFont(font);
	buttonFullscreen.setString("Fullscreen: OFF");
	buttonFullscreen.setColor(sf::Color::White);
	buttonFullscreen.setCharacterSize(20);
	buttonFullscreen.setPosition(screenWidth / 2.f - 200.f, 200.f);

	buttonBallColor.setFont(font);
	buttonBallColor.setString("Ball colors:");
	buttonBallColor.setColor(sf::Color::White);
	buttonBallColor.setCharacterSize(20);
	buttonBallColor.setPosition(screenWidth / 2.f - 200.f, 250.f);

	buttonBatColor.setFont(font);
	buttonBatColor.setString("Bat colors:");
	buttonBatColor.setColor(sf::Color::White);
	buttonBatColor.setCharacterSize(20);
	buttonBatColor.setPosition(screenWidth / 2.f - 200.f, 300.f);

	//button for color options
	currentBallColor.setFont(font);
    currentBallColor.setString("Current color: ");
    currentBallColor.setColor(sf::Color::White);
    currentBallColor.setCharacterSize(40);
    currentBallColor.setPosition(screenWidth / 2.f - 200.f, 50.f);

    buttonBallColorRed.setFont(font);
	buttonBallColorRed.setString("RED");
	buttonBallColorRed.setColor(sf::Color::White);
	buttonBallColorRed.setCharacterSize(30);
	buttonBallColorRed.setPosition(screenWidth / 2.f - 200.f, 150.f);

	buttonBallColorBlue.setFont(font);
	buttonBallColorBlue.setString("BLUE");
	buttonBallColorBlue.setColor(sf::Color::White);
	buttonBallColorBlue.setCharacterSize(30);
	buttonBallColorBlue.setPosition(screenWidth / 2.f - 200.f, 200.f);

	buttonBallColorYellow.setFont(font);
	buttonBallColorYellow.setString("YELLOW");
	buttonBallColorYellow.setColor(sf::Color::White);
	buttonBallColorYellow.setCharacterSize(30);
	buttonBallColorYellow.setPosition(screenWidth / 2.f - 200.f, 250.f);

	buttonBallColorGreen.setFont(font);
	buttonBallColorGreen.setString("GREEN");
	buttonBallColorGreen.setColor(sf::Color::White);
	buttonBallColorGreen.setCharacterSize(30);
	buttonBallColorGreen.setPosition(screenWidth / 2.f - 200.f, 300.f);

	//button for Bat colors
	currentBatColor.setFont(font);
    currentBatColor.setString("Current color: ");
    currentBatColor.setColor(sf::Color::White);
    currentBatColor.setCharacterSize(40);
    currentBatColor.setPosition(screenWidth / 2.f - 200.f, 50.f);

    buttonBatColorRed.setFont(font);
	buttonBatColorRed.setString("RED");
	buttonBatColorRed.setColor(sf::Color::White);
	buttonBatColorRed.setCharacterSize(30);
	buttonBatColorRed.setPosition(screenWidth / 2.f - 200.f, 150.f);

	buttonBatColorBlue.setFont(font);
	buttonBatColorBlue.setString("BLUE");
	buttonBatColorBlue.setColor(sf::Color::White);
	buttonBatColorBlue.setCharacterSize(30);
	buttonBatColorBlue.setPosition(screenWidth / 2.f - 200.f, 200.f);

	buttonBatColorYellow.setFont(font);
	buttonBatColorYellow.setString("YELLOW");
	buttonBatColorYellow.setColor(sf::Color::White);
	buttonBatColorYellow.setCharacterSize(30);
	buttonBatColorYellow.setPosition(screenWidth / 2.f - 200.f, 250.f);

	buttonBatColorGreen.setFont(font);
	buttonBatColorGreen.setString("GREEN");
	buttonBatColorGreen.setColor(sf::Color::White);
	buttonBatColorGreen.setCharacterSize(30);
	buttonBatColorGreen.setPosition(screenWidth / 2.f - 200.f, 300.f);

    //winning buttons
    player1win.setFont(font);
	player1win.setString("Player 1 won!");
	player1win.setColor(sf::Color::White);
	player1win.setCharacterSize(50);
	player1win.setPosition(screenWidth / 2.f - (player1win.getGlobalBounds().width / 2.f), 50.f);

	player2win.setFont(font);
	player2win.setString("Player 2 won!");
	player2win.setColor(sf::Color::White);
	player2win.setCharacterSize(50);
	player2win.setPosition(screenWidth / 2.f - (player2win.getGlobalBounds().width / 2.f), 50.f);

	replayOpinion.setFont(font);
	replayOpinion.setString("Do you want to play again?");
	replayOpinion.setColor(sf::Color::White);
	replayOpinion.setCharacterSize(30);
	replayOpinion.setPosition(screenWidth / 2.f - (replayOpinion.getGlobalBounds().width / 2.f), 150.f);

	buttonYes.setFont(font);
	buttonYes.setString("YES");
	buttonYes.setColor(sf::Color::White);
	buttonYes.setCharacterSize(30);
	buttonYes.setPosition(screenWidth / 2.f - (buttonYes.getGlobalBounds().width), 225.f);

	buttonNo.setFont(font);
	buttonNo.setString("NO");
	buttonNo.setColor(sf::Color::White);
	buttonNo.setCharacterSize(30);
	buttonNo.setPosition(screenWidth / 2.f + (buttonNo.getGlobalBounds().width), 225.f);

	//side buttons
	buttonBack.setFont(font);
	buttonBack.setString("Back");
	buttonBack.setColor(sf::Color::White);
	buttonBack.setPosition(30.f, screenHeight - buttonBack.getGlobalBounds().height - 40.f);

	sliderBar.setSize(sf::Vector2f(150.f, 10.f));
	sliderBar.setOrigin(0.f, 5.f);
	sliderBar.setFillColor(sf::Color::White);
	sliderBar.setPosition(screenWidth / 2.f - 190 + buttonVolume.getGlobalBounds().width, buttonVolume.getPosition().y + buttonVolume.getGlobalBounds().height);

	slider.setSize(sf::Vector2f(10.f, 30.f));
	slider.setOrigin(5.f, 15.f);
	slider.setFillColor(sf::Color::White);
	slider.setOutlineColor(sf::Color::Red);
	slider.setOutlineThickness(2);
	slider.setPosition(sliderBar.getPosition().x + sliderBar.getGlobalBounds().width , sliderBar.getPosition().y);

	menuSoundBuff.loadFromFile("soundtrack/mouseOver.wav");
	paddleSoundBuff.loadFromFile("soundtrack/collisionPaddle.wav");
	wallSoundBuff.loadFromFile("soundtrack/collisionWall.wav");
	scoreSoundBuff.loadFromFile("soundtrack/collisionScore.wav");
	victorySoundBuff.loadFromFile("soundtrack/victory.wav");

	menuSound.setBuffer(menuSoundBuff);
	paddleCollision.setBuffer(paddleSoundBuff);
	wallCollision.setBuffer(wallSoundBuff);
	scoreCollision.setBuffer(scoreSoundBuff);
	victory.setBuffer(victorySoundBuff);

	menuSound.setVolume(volume);
	paddleCollision.setVolume(volume);
	wallCollision.setVolume(volume);
	scoreCollision.setVolume(volume);
	victory.setVolume(volume);
}
