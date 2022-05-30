#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

enum states
{
	MENU,
	OPTIONS,
	PLAY,
	AI,
	INSTRUCTIONS,
	BALLCOLORS,
	BATCOLORS,
	PLAYER1WIN,
	PLAYER2WIN,
};

class game
{
public:
	game();
	void run();
private:
	void handleEvents();
	void update(float &deltaTime);
	void draw();

	const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	const int screenWidth = 800;
	const int screenHeight = 500;
	const float batWidth = 30.f;
	const float batHeight = 100.f;
	const float ballRadius = 12.f;
	float ballSpeed = 300.f;
	const float paddleSpeed = 300.f;
	const float botPaddleSpeed = 250.f;
	float velBallX, velBallY;
    float deltaTime = 0.f;

	int leftMove = 0;
	int rightMove = 0;

	sf::Vector2f leftBatVel;
	sf::Vector2f rightBatVel;

	bool m_paused;
	bool player1;
	bool player2;
	bool playType;
	bool victorySound;

	states currentState = MENU;
	sf::RectangleShape pauseBackground;

	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite background;

	//Main menu
	sf::Text title;
	sf::Text buttonPlay;
	sf::Text buttonPlayAI;
	sf::Text buttonOptions;
	sf::Text buttonInstructions;
	sf::Text buttonExit;
	sf::Text instructionsTitle;
	sf::Text instructionsContents;

	//winning
	sf::Text player1win;
	sf::Text player2win;
	sf::Text replayOpinion;
    sf::Text buttonYes;
    sf::Text buttonNo;

	//Bat colors
	sf::Text buttonBatColor;
	sf::Text buttonBatColorRed;
	sf::Text buttonBatColorYellow;
	sf::Text buttonBatColorBlue;
	sf::Text buttonBatColorGreen;
	sf::Text currentBatColor;

	//ball colors
	sf::Text buttonBallColor;
	sf::Text buttonBallColorRed;
	sf::Text buttonBallColorYellow;
	sf::Text buttonBallColorBlue;
	sf::Text buttonBallColorGreen;
	sf::Text currentBallColor;

	//in game
	sf::Text pauseTitle;
	sf::Text pauseMenu;
	sf::Text pauseExit;

	//in options
	sf::Text optionsTitle;
	sf::Text buttonBack;
	sf::Text buttonVolume;
	sf::Text buttonFullscreen;
	sf::RectangleShape sliderBar;
	sf::RectangleShape slider;
	sf::View fullscreenView;
	bool selected;

	int scoreLeft = 0;
	int scoreRight = 0;
	char scoreChar[20];

    float volume;

	sf::Font font;
	sf::Text scoreBoard;
	sf::Text ballSpeedText;

	sf::Vector2f ballVelocity;

	sf::CircleShape ball;
	sf::RectangleShape leftBat;
	sf::RectangleShape rightBat;
	sf::CircleShape predBall;
	sf::Vector2f predBallVel;

	sf::SoundBuffer menuSoundBuff;
	sf::SoundBuffer paddleSoundBuff;
	sf::SoundBuffer wallSoundBuff;
	sf::SoundBuffer scoreSoundBuff;
	sf::SoundBuffer victorySoundBuff;

	sf::Sound menuSound;
	sf::Sound paddleCollision;
	sf::Sound wallCollision;
	sf::Sound scoreCollision;
	sf::Sound victory;

	bool soundPlayed;
};
