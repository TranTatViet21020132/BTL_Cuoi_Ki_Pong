#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "game.h"

void game::draw()
{
	if (currentState == MENU)
	{
		window.clear();
		window.draw(title);
		window.draw(buttonPlay);
		window.draw(buttonPlayAI);
		window.draw(buttonOptions);
		window.draw(buttonInstructions);
		window.draw(buttonExit);
		window.display();
	}
	else if (currentState == OPTIONS)
	{
		window.clear();
		window.draw(optionsTitle);
		window.draw(buttonVolume);
		window.draw(sliderBar);
		window.draw(slider);
		window.draw(buttonFullscreen);
		window.draw(buttonBallColor);
		window.draw(buttonBatColor);
		window.draw(buttonBack);
		window.display();
	}
	else if (currentState == PLAY)
	{
        window.clear();
        window.draw(background);
		window.draw(ballSpeedText);
		window.draw(scoreBoard);
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		if (m_paused)
		{
			window.draw(pauseBackground);
			window.draw(pauseTitle);
			window.draw(pauseMenu);
			window.draw(pauseExit);
		}
		window.display();
	}
	else if (currentState == AI)
	{
		window.clear();
		window.draw(background);
		window.draw(ballSpeedText);
		window.draw(scoreBoard);
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		if (m_paused)
		{
			window.draw(pauseBackground);
			window.draw(pauseTitle);
			window.draw(pauseMenu);
			window.draw(pauseExit);
		}
		window.display();
	}
	else if (currentState == INSTRUCTIONS)
    {
        window.clear();
        window.draw(instructionsTitle);
        window.draw(instructionsContents);
        window.draw(buttonBack);
		window.display();
	}
	else if (currentState == BALLCOLORS)
    {
        window.clear();
        window.draw(currentBallColor);
        window.draw(buttonBallColorRed);
        window.draw(buttonBallColorYellow);
        window.draw(buttonBallColorBlue);
        window.draw(buttonBallColorGreen);
        window.draw(buttonBack);
		window.display();
	}
	else if (currentState == BATCOLORS)
    {
        window.clear();
        window.draw(currentBatColor);
        window.draw(buttonBatColorRed);
        window.draw(buttonBatColorYellow);
        window.draw(buttonBatColorBlue);
        window.draw(buttonBatColorGreen);
        window.draw(buttonBack);
		window.display();
    }
    else if (currentState == PLAYER1WIN)
    {
        window.clear();
        window.draw(player1win);
        window.draw(replayOpinion);
        window.draw(buttonYes);
        window.draw(buttonNo);
        window.draw(buttonBack);
		window.display();
    }
    else if (currentState == PLAYER2WIN)
    {
        window.clear();
        window.draw(player2win);
        window.draw(replayOpinion);
        window.draw(buttonYes);
        window.draw(buttonNo);
        window.draw(buttonBack);
		window.display();
    }
}
