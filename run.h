#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "game.h"
using namespace std;

void game::run()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		handleEvents();
		deltaTime = clock.restart().asSeconds();
        if (!m_paused)
        {
            update(deltaTime);
        }
		draw();
	}
}
