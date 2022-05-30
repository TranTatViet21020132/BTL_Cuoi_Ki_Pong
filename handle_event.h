#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "game.h"

void game::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (currentState == MENU)
		{
			//Menu play 1v1
			if (buttonPlay.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonPlay.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = PLAY;
			}
			else
			{
				buttonPlay.setColor(sf::Color::White);
				if (!buttonExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonPlayAI.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonOptions.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					soundPlayed = false;
				}

			}
			//Menu play vs AI
			if (buttonPlayAI.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonPlayAI.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = AI;
			}
			else
			{
				buttonPlayAI.setColor(sf::Color::White);
				if (!buttonPlay.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonOptions.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					soundPlayed = false;
				}
			}
			//Menu options
			if (buttonOptions.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonOptions.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = OPTIONS;
			}
			else
			{
				buttonOptions.setColor(sf::Color::White);
				if (!buttonPlay.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonPlayAI.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					soundPlayed = false;
				}
			}

			//Menu instructions
			if (buttonInstructions.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonInstructions.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = INSTRUCTIONS;
			}
			else
			{
				buttonInstructions.setColor(sf::Color::White);
                soundPlayed = false;
			}

			//Menu exit
			if (buttonExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonExit.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
					window.close();
			}
			else
			{
				buttonExit.setColor(sf::Color::White);
				if (!buttonPlay.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonPlayAI.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonOptions.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					soundPlayed = false;
				}
			}

		}
		else if (currentState == OPTIONS)
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				currentState = MENU;

			if (buttonBack.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBack.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = MENU;
			}
			else
			{
				buttonBack.setColor(sf::Color::White);
				if (!slider.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)) &&
					!buttonFullscreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					soundPlayed = false;
			}

			//volume control
			if (slider.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				slider.setFillColor(sf::Color::Red);
				slider.setOutlineColor(sf::Color::White);
				if (event.type == sf::Event::MouseButtonPressed)
				{
					selected = true;
				}
			}
			else
			{
				if (!selected)
				{
					slider.setFillColor(sf::Color::White);
					slider.setOutlineColor(sf::Color::Red);
				}
			}
			//volume
			if (selected && event.type == sf::Event::MouseButtonReleased)
				if (event.mouseButton.button == sf::Mouse::Left)
				{
				    float tempDistance = slider.getPosition().x - sliderBar.getPosition().x;
				    float tempVolume = tempDistance / sliderBar.getSize().x;
				    volume = tempVolume * 100;
                    menuSound.setVolume(volume);
                    paddleCollision.setVolume(volume);
                    wallCollision.setVolume(volume);
                    scoreCollision.setVolume(volume);

					selected = false;
					menuSound.play();
				}

			//fullscreen
			if (buttonFullscreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				buttonFullscreen.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (buttonFullscreen.getString() == "Fullscreen: OFF")
						{
							buttonFullscreen.setString("Fullscreen: ON");
							window.create(sf::VideoMode(screenWidth, screenHeight), "Pong", sf::Style::Fullscreen);
						}
						else if (buttonFullscreen.getString() == "Fullscreen: ON")
						{
							buttonFullscreen.setString("Fullscreen: OFF");
							window.create(sf::VideoMode(screenWidth, screenHeight), "Pong");
						}
					}
			}
			else
			{
				buttonFullscreen.setColor(sf::Color::White);
			}

			//ball colors
            if (buttonBallColor.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
            {
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBallColor.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = BALLCOLORS;
			}
			else
			{
				buttonBallColor.setColor(sf::Color::White);
				soundPlayed = false;
			}

			//Bat colors
			if (buttonBatColor.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
            {
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBatColor.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = BATCOLORS;
			}
			else
			{
				buttonBatColor.setColor(sf::Color::White);
				soundPlayed = false;
			}
		}

		else if (currentState == PLAY)
		{   playType = true;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				m_paused = !m_paused;
			if (!m_paused)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					leftMove = 1;

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					leftMove = 2;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					rightMove = 1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					rightMove = 2;

				}

				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					leftMove = 0;

				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					rightMove = 0;

                if (player1 == true)
                {
                    sf::sleep(sf::seconds(1.0));
                    scoreLeft = 0;
                    scoreRight = 0;
                    sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
                    scoreBoard.setString(static_cast<std::string>(scoreChar));
                    ballSpeed = 300.f;
                    ballVelocity = sf::Vector2f(ballSpeed, 0.f);
                    ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
                    leftBat.setPosition(sf::Vector2f(0.f, screenHeight / 2.f - batHeight / 2.f + 2));
                    rightBat.setPosition(sf::Vector2f(screenWidth - batWidth, screenHeight / 2.f - batHeight / 2.f + 2));
                    currentState = PLAYER1WIN;
                    victorySound = false;
                    player1 = false;
                }
                else if (player2 == true)
                {
                    sf::sleep(sf::seconds(1.0));
                    scoreLeft = 0;
                    scoreRight = 0;
                    sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
                    scoreBoard.setString(static_cast<std::string>(scoreChar));
                    ballSpeed = 300;
                    ballVelocity = sf::Vector2f(ballSpeed, 0.f);
                    ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
                    leftBat.setPosition(sf::Vector2f(0.f, screenHeight / 2.f - batHeight / 2.f + 2));
                    rightBat.setPosition(sf::Vector2f(screenWidth - batWidth, screenHeight / 2.f - batHeight / 2.f + 2));
                    currentState = PLAYER2WIN;
                    victorySound = false;
                    player2 = false;
                }
			}
			else
			{
				if (pauseMenu.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					pauseMenu.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							scoreLeft = 0;
							scoreRight = 0;
							sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
							scoreBoard.setString(static_cast<std::string>(scoreChar));
							ballSpeed = 300;
							ballVelocity = sf::Vector2f(ballSpeed, 0.f);
							ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
							leftBat.setPosition(sf::Vector2f(0.f, screenHeight / 2.f - batHeight / 2.f + 2));
							rightBat.setPosition(sf::Vector2f(screenWidth - batWidth, screenHeight / 2.f - batHeight / 2.f + 2));

							currentState = MENU;
							m_paused = false;

						}
				}
				else
				{
					pauseMenu.setColor(sf::Color::White);
					if (!pauseExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				if (pauseExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					pauseExit.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
							window.close();
				}
				else
				{
					pauseExit.setColor(sf::Color::White);
					if (!pauseMenu.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}
			}
		}
		else if (currentState == AI)
		{   playType = false;
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				m_paused = !m_paused;

			if (!m_paused)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					leftMove = 1;

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					leftMove = 2;

				}

				if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					leftMove = 0;

					if (player1 == true)
                {
                    sf::sleep(sf::seconds(1.0));
                    scoreLeft = 0;
                    scoreRight = 0;
                    sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
                    scoreBoard.setString(static_cast<std::string>(scoreChar));
                    ballSpeed = 300.f;
                    ballVelocity = sf::Vector2f(ballSpeed, 0.f);
                    ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
                    leftBat.setPosition(sf::Vector2f(0.f, screenHeight / 2.f - batHeight / 2.f + 2));
                    rightBat.setPosition(sf::Vector2f(screenWidth - batWidth, screenHeight / 2.f - batHeight / 2.f + 2));
                    currentState = PLAYER1WIN;
                    victorySound = false;
                    player1 = false;
                }
                else if (player2 == true)
                {
                    sf::sleep(sf::seconds(1.0));
                    scoreLeft = 0;
                    scoreRight = 0;
                    sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
                    scoreBoard.setString(static_cast<std::string>(scoreChar));
                    ballSpeed = 300;
                    ballVelocity = sf::Vector2f(ballSpeed, 0.f);
                    ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
                    leftBat.setPosition(sf::Vector2f(0.f, screenHeight / 2.f - batHeight / 2.f + 2));
                    rightBat.setPosition(sf::Vector2f(screenWidth - batWidth, screenHeight / 2.f - batHeight / 2.f + 2));
                    currentState = PLAYER2WIN;
                    victorySound = false;
                    player2 = false;
                }
			}
			else
			{
				if (pauseMenu.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					pauseMenu.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							scoreLeft = 0;
							scoreRight = 0;
							sprintf(scoreChar, "%d : %d", scoreLeft, scoreRight);
							scoreBoard.setString(static_cast<std::string>(scoreChar));
							ballSpeed = 300;
							ballVelocity = sf::Vector2f(ballSpeed, 0.f);
							ball.setPosition(sf::Vector2f(screenWidth / 2.f, screenHeight / 2.f));
							leftBat.setPosition(sf::Vector2f(0.f, screenHeight / 2.f - batHeight / 2.f + 2));
							rightBat.setPosition(sf::Vector2f(screenWidth - batWidth, screenHeight / 2.f - batHeight / 2.f + 2));
							predBall.setPosition(sf::Vector2f(screenWidth - 20.f, screenHeight / 2.f + 50));
							currentState = MENU;
							victorySound = false;
							m_paused = false;

						}
				}
				else
				{
					pauseMenu.setColor(sf::Color::White);
					if (!pauseExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				if (pauseExit.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					pauseExit.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
							window.close();
				}
				else
				{
					pauseExit.setColor(sf::Color::White);
					if (!pauseMenu.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}
			}
		}
		else if (currentState == INSTRUCTIONS)
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				currentState = MENU;

			if (buttonBack.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBack.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = MENU;
			}
			else
			{
				buttonBack.setColor(sf::Color::White);
				soundPlayed = false;
			}
        }
        else if (currentState == BALLCOLORS)
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				currentState = OPTIONS;

			if (buttonBack.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBack.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = OPTIONS;
			}
			else
			{
				buttonBack.setColor(sf::Color::White);

				//color red
                if (buttonBallColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBallColorRed.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::ball.setFillColor(sf::Color::Red);
							game::currentBallColor.setFont(font);
	                        game::currentBallColor.setString("Current color: Red");
	                        game::currentBallColor.setColor(sf::Color::White);
	                        game::currentBallColor.setCharacterSize(40);
                            game::currentBallColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBallColorRed.setColor(sf::Color::White);
					if (!buttonBallColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				//color blue
				if (buttonBallColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBallColorBlue.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::ball.setFillColor(sf::Color::Blue);
							game::currentBallColor.setFont(font);
	                        game::currentBallColor.setString("Current color: Blue");
	                        game::currentBallColor.setColor(sf::Color::White);
	                        game::currentBallColor.setCharacterSize(40);
                            game::currentBallColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBallColorBlue.setColor(sf::Color::White);
					if (!buttonBallColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				//color yellow
				if (buttonBallColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBallColorYellow.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::ball.setFillColor(sf::Color::Yellow);
							game::currentBallColor.setFont(font);
	                        game::currentBallColor.setString("Current color: Yellow");
	                        game::currentBallColor.setColor(sf::Color::White);
	                        game::currentBallColor.setCharacterSize(40);
                            game::currentBallColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBallColorYellow.setColor(sf::Color::White);
					if (!buttonBallColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				//color green
				if (buttonBallColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBallColorGreen.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::ball.setFillColor(sf::Color::Green);
							game::currentBallColor.setFont(font);
	                        game::currentBallColor.setString("Current color: Green");
	                        game::currentBallColor.setColor(sf::Color::White);
	                        game::currentBallColor.setCharacterSize(40);
                            game::currentBallColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBallColorGreen.setColor(sf::Color::White);
					if (!buttonBallColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBallColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}


			}
        }

        else if (currentState == BATCOLORS)
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				currentState = OPTIONS;

			if (buttonBack.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBack.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = OPTIONS;
			}
			else
			{
				buttonBack.setColor(sf::Color::White);

				//color red
                if (buttonBatColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBatColorRed.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::leftBat.setFillColor(sf::Color::Red);
							game::rightBat.setFillColor(sf::Color::Red);
							game::currentBatColor.setFont(font);
	                        game::currentBatColor.setString("Current color: Red");
	                        game::currentBatColor.setColor(sf::Color::White);
	                        game::currentBatColor.setCharacterSize(40);
                            game::currentBatColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBatColorRed.setColor(sf::Color::White);
					if (!buttonBatColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				//color blue
				if (buttonBatColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBatColorBlue.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::leftBat.setFillColor(sf::Color::Blue);
							game::rightBat.setFillColor(sf::Color::Blue);
							game::currentBatColor.setFont(font);
	                        game::currentBatColor.setString("Current color: Blue");
	                        game::currentBatColor.setColor(sf::Color::White);
	                        game::currentBatColor.setCharacterSize(40);
                            game::currentBatColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBatColorBlue.setColor(sf::Color::White);
					if (!buttonBatColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				//color yellow
				if (buttonBatColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBatColorYellow.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::leftBat.setFillColor(sf::Color::Yellow);
							game::rightBat.setFillColor(sf::Color::Yellow);
							game::currentBatColor.setFont(font);
	                        game::currentBatColor.setString("Current color: Yellow");
	                        game::currentBatColor.setColor(sf::Color::White);
	                        game::currentBatColor.setCharacterSize(40);
                            game::currentBatColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBatColorYellow.setColor(sf::Color::White);
					if (!buttonBatColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

				//color green
				if (buttonBatColorGreen.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				{
					if (!soundPlayed)
					{
						menuSound.play();
						soundPlayed = true;
					}
					buttonBatColorGreen.setColor(sf::Color::Red);
					if (event.type == sf::Event::MouseButtonReleased)
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							game::leftBat.setFillColor(sf::Color::Green);
							game::rightBat.setFillColor(sf::Color::Green);
							game::currentBatColor.setFont(font);
	                        game::currentBatColor.setString("Current color: Green");
	                        game::currentBatColor.setColor(sf::Color::White);
	                        game::currentBatColor.setCharacterSize(40);
                            game::currentBatColor.setPosition(screenWidth / 2.f - 200.f, 50.f);
						}
				}
				else
				{
					buttonBatColorGreen.setColor(sf::Color::White);
					if (!buttonBatColorYellow.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorBlue.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y))
                        &&!buttonBatColorRed.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
					{
						soundPlayed = false;
					}
				}

			}
        }
        else if (currentState == PLAYER1WIN)
        {
            if (!victorySound)
                {
                    victory.play();
                }
            victorySound = true;

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				currentState = MENU;

			if (buttonBack.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBack.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = MENU;
			}
			else
			{
				buttonBack.setColor(sf::Color::White);
                soundPlayed = false;

            //yes button
				if (buttonYes.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonYes.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if (playType == true)
                        {
                        currentState = PLAY;
                        }
                        else
                        {
                        currentState = AI;
                        }
                    }

			}
			else
            {
				buttonYes.setColor(sf::Color::White);
				if (!buttonNo.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				soundPlayed = false;
            }

            //no button
            if (buttonNo.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonNo.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        currentState = MENU;
                    }

			}
			else
            {
				buttonNo.setColor(sf::Color::White);
				if (!buttonYes.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				soundPlayed = false;
            }
            }
        }
        else if (currentState == PLAYER2WIN)
        {
            if (!victorySound)
                {
                    victory.play();
                }
                victorySound = true;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				currentState = MENU;

			if (buttonBack.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonBack.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						currentState = MENU;
			}
			else
			{
				buttonBack.setColor(sf::Color::White);
                soundPlayed = false;

            //yes button
				if (buttonYes.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonYes.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
						if (playType == true)
                        {
                        currentState = PLAY;
                        }
                        else
                        {
                        currentState = AI;
                        }
			}
			else
			{
				buttonYes.setColor(sf::Color::White);
				if (!buttonNo.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				soundPlayed = false;
			}

			//no button
            if (buttonNo.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
			{
				if (!soundPlayed)
				{
					menuSound.play();
					soundPlayed = true;
				}
				buttonNo.setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        currentState = MENU;
                    }

			}
			else
            {
				buttonNo.setColor(sf::Color::White);
				if (!buttonYes.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)))
				soundPlayed = false;
            }
            }
        }

		if (event.type == sf::Event::Closed)
			window.close();
	}

}
