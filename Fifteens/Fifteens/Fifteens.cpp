#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>

using namespace sf;
using namespace std;

int main()
{
	srand(time(NULL));
	int R = 100;
	int G = 100;
	int B = 100;
	int A = 255;

	RenderWindow window(VideoMode(600, 600), "English Word", sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	Font font;
	font.loadFromFile("Arcade.ttf");
	Text text("Arcade Fifteens game", font, 30);
	text.setPosition(75, 0);
	text.setFillColor(Color(R, G, B, A));

	Text Keys("Esc - Exit, F5 - New Game, Arrow Keys - Move bones", font, 15);
	Keys.setPosition(15, 570);
	Keys.setFillColor(Color(R, G, B, A));

	RectangleShape rectangle(Vector2f(500, 500));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineThickness(1);
	rectangle.move(50, 50);
	rectangle.setOutlineColor(Color(197, 0, 128));

	sf::Clock clock;
	sf::Time time;
	

	while (window.isOpen())
	{
		window.draw(text);
		window.draw(rectangle);
		window.draw(Keys);

		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape) window.close();
			}
		}

		time = clock.getElapsedTime();
		if (time.asSeconds() > 1)
		{
			R = rand() % 255;
			G = rand() % 255;
			B = rand() % 255;

			text.setFillColor(Color(R, G, B, A));
			Keys.setFillColor(Color(R, G, B, A));
			clock.restart().asSeconds();

		}

		window.display();
	}

	return 0;
}