#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "game.h"

void game::update(float &deltaTime)
{

	if (currentState == PLAY)
	{
		//Left bat
		if (ball.getGlobalBounds().intersects(leftBat.getGlobalBounds()))
		{
			paddleCollision.play();
			if (ballSpeed == 300.f)
				ballSpeed = 600.f;
            velBallX = ballSpeed;
			velBallY = (leftBat.getGlobalBounds().top + (leftBat.getGlobalBounds().height / 2.f)) - (ball.getGlobalBounds().top + (ball.getGlobalBounds().height / 2.f));
			ballVelocity = sf::Vector2f(velBallX, -velBallY * 2.f);
			ballSpeed += 10.f;
		}

		//Right bat
		if (ball.getGlobalBounds().intersects(rightBat.getGlobalBounds()))
		{
			paddleCollision.play();
			if (ballSpeed == 300.f)
				ballSpeed = 600.f;
            velBallX = ballSpeed;
			velBallY = (rightBat.getGlobalBounds().top + (rightBat.getGlobalBounds().height / 2.f)) - (ball.getGlobalBounds().top + (ball.getGlobalBounds().height / 2.f));
			ballVelocity = sf::Vector2f(-velBallX, -velBallY * 2.f);
			ballSpeed += 10.f;

		}

		//Top screen bounce
		if (ball.getGlobalBounds().top <= 0)
		{
			wallCollision.play();
			ballVelocity.y *= -1.f;
		}
		//Bottom screen bounce
		else if (ball.getGlobalBounds().top + ball.getGlobalBounds().height >= screenHeight)
		{
			wallCollision.play();
			ballVelocity.y *= -1.f;
		}

		//Left screen collision
		if (ball.getGlobalBounds().left <= 0)
		{
			scoreCollision.play();
			scoreRight++;
			sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
			scoreBoard.setString(static_cast<std::string>(scoreChar));
			ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
			ballSpeed = 300.f;
			ballVelocity = sf::Vector2f(-ballSpeed, 0.f);
		}
		//Right screen collision
		if (ball.getGlobalBounds().left + ball.getGlobalBounds().width >= screenWidth)
		{
			scoreCollision.play();
			scoreLeft++;
			sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
			scoreBoard.setString(static_cast<std::string>(scoreChar));
			ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
			ballSpeed = 300.f;
			ballVelocity = sf::Vector2f(ballSpeed, 0.f);
		}

		//winning
		if (scoreLeft == 5 && scoreRight < 5)
        {
            player1 = true;
            deltaTime = 0.f;
		}
		else if (scoreRight == 5 && scoreLeft < 5)
        {
            player2 = true;
            deltaTime = 0.f;
        }

		ball.move(ballVelocity.x * deltaTime, ballVelocity.y * deltaTime);

		//leftbat move
		if (leftMove == 1)
		{
			if (leftBat.getPosition().y > 0)
				leftBat.move(0.f, -paddleSpeed * deltaTime);
		}
		else if (leftMove == 2)
		{
			if (leftBat.getPosition().y + leftBat.getGlobalBounds().height < screenHeight)
				leftBat.move(0.f, paddleSpeed * deltaTime);
		}
		else if (leftMove == 0)
		{
			leftBatVel = sf::Vector2f(0, 0);
		}

        //rightbat move
		if (rightMove == 1)
		{
			if (rightBat.getPosition().y > 0)
				rightBat.move(0.f, -paddleSpeed * deltaTime);
		}
		else if (rightMove == 2)
		{
			if (rightBat.getPosition().y + rightBat.getGlobalBounds().height < screenHeight)
				rightBat.move(0.f, paddleSpeed * deltaTime);
		}
		else if (rightMove == 0)
		{
			rightBatVel = sf::Vector2f(0, 0);
		}

		ballSpeedText.setString("Speed: " + std::to_string(static_cast<int>(ballSpeed / 10)));

	}
	else if (currentState == AI)
	{
		//Left bat
		if (ball.getGlobalBounds().intersects(leftBat.getGlobalBounds()))
		{
			paddleCollision.play();
			if (ballSpeed == 300.f)
				ballSpeed = 600.f;
            velBallX = ballSpeed;
			velBallY = (leftBat.getGlobalBounds().top + (leftBat.getGlobalBounds().height / 2.f)) - (ball.getGlobalBounds().top + (ball.getGlobalBounds().height / 2.f));
			ballVelocity = sf::Vector2f(velBallX, -velBallY * 2.f);
			predBall.setPosition(ball.getPosition());
			predBallVel = ballVelocity;
			ballSpeed += 10.f;

		}

		//Right bat
		if (ball.getGlobalBounds().intersects(rightBat.getGlobalBounds()))
		{
			paddleCollision.play();
			if (ballSpeed == 300.f)
				ballSpeed = 600.f;
            velBallX = ballSpeed;
			velBallY = (rightBat.getGlobalBounds().top + (rightBat.getGlobalBounds().height / 2.f)) - (ball.getGlobalBounds().top + (ball.getGlobalBounds().height / 2.f));
			ballVelocity = sf::Vector2f(-velBallX, -velBallY * 2.f);
			predBall.setPosition(ball.getPosition());
			predBallVel = ballVelocity;
			ballSpeed += 10.f;

		}

		//Top side bounce
		if (ball.getGlobalBounds().top <= 0)
		{
			wallCollision.play();
			ballVelocity.y *= -1.f;
		}
		//Bottom side bounce
		else if (ball.getGlobalBounds().top + ball.getGlobalBounds().height >= screenHeight)
		{
			wallCollision.play();
			ballVelocity.y *= -1.f;
		}
		//Predball
		if (predBall.getGlobalBounds().top <= 0)
		{
			predBallVel.y *= -1.f;
		}
		else if (predBall.getGlobalBounds().top + predBall.getGlobalBounds().height >= screenHeight)
		{
			predBallVel.y *= -1.f;
		}

		//Left side collision
		if (ball.getGlobalBounds().left <= 0)
		{
			scoreCollision.play();
			scoreRight++;
			sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
			scoreBoard.setString(static_cast<std::string>(scoreChar));
			ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
			ballSpeed = 300.f;
			ballVelocity = sf::Vector2f(-ballSpeed, 0.f);

		}
		//Right side collision
		if (ball.getGlobalBounds().left + ball.getGlobalBounds().width >= screenWidth)
		{
			scoreCollision.play();
			scoreLeft++;
			sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
			scoreBoard.setString(static_cast<std::string>(scoreChar));
			ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
			ballSpeed = 300.f;
			ballVelocity = sf::Vector2f(ballSpeed, 0.f);
			predBall.setPosition(sf::Vector2f(screenWidth - 20.f, screenHeight / 2.f + 100));
		}


		ball.move(ballVelocity.x * deltaTime, ballVelocity.y * deltaTime);

        //winning
		if (scoreLeft == 5 && scoreRight < 5)
        {
            player1 = true;
            deltaTime = 0.f;
		}
		else if (scoreRight == 5 && scoreLeft < 5)
        {
            player2 = true;
            deltaTime = 0.f;
        }

		//paddle move

		if (leftMove == 1)
		{
			if (leftBat.getPosition().y > 0)
				leftBat.move(0.f, -paddleSpeed * deltaTime);
		}
		else if (leftMove == 2)
		{
			if (leftBat.getPosition().y + rightBat.getGlobalBounds().height < screenHeight)
				leftBat.move(0.f, paddleSpeed * deltaTime);
		}
		else if (leftMove == 0)
		{
			leftBatVel = sf::Vector2f(0, 0);
		}

		//AI

		if (predBall.getGlobalBounds().left > 0 && predBall.getGlobalBounds().left + predBall.getGlobalBounds().width + 30.f < screenWidth)
		{
			predBall.move(predBallVel.x * deltaTime * 1.3f, predBallVel.y * deltaTime * 1.3f);
		}

			if (ball.getPosition().x >= screenWidth / 2.f)
			{
				if (rightBat.getGlobalBounds().top + rightBat.getGlobalBounds().height / 2.f < predBall.getPosition().y && !rightBat.getGlobalBounds().intersects(predBall.getGlobalBounds()))
				{
					rightBat.move(0, paddleSpeed * deltaTime);
					if (rightBat.getGlobalBounds().top + rightBat.getGlobalBounds().height >= screenHeight)
						rightBat.move(0, -paddleSpeed * deltaTime);
				}
				else if (rightBat.getGlobalBounds().top + rightBat.getGlobalBounds().height / 2.f > predBall.getPosition().y && !rightBat.getGlobalBounds().intersects(predBall.getGlobalBounds()))
				{
					rightBat.move(0, -botPaddleSpeed  * deltaTime);
					if (rightBat.getGlobalBounds().top <= 0)
						rightBat.move(0, botPaddleSpeed * deltaTime);
				}
			}


		ballSpeedText.setString("Speed: " + std::to_string(static_cast<int>(ballSpeed / 10)));

	}
	else if (currentState == OPTIONS)
	{
		if (selected)
		{
			slider.setPosition(static_cast<float>(sf::Mouse::getPosition(window).x), slider.getPosition().y);
			if (slider.getGlobalBounds().left + slider.getGlobalBounds().width / 2.f <= sliderBar.getGlobalBounds().left)
				slider.setPosition(sliderBar.getPosition().x, slider.getPosition().y);
			else if (slider.getGlobalBounds().left + slider.getGlobalBounds().width / 2.f >= sliderBar.getGlobalBounds().left + sliderBar.getGlobalBounds().width)
				slider.setPosition(sliderBar.getPosition().x + sliderBar.getGlobalBounds().width, slider.getPosition().y);
		}
	}

}
