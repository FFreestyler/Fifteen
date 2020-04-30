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

	RenderWindow window(VideoMode(600, 600), "Fifteen", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	Font font;
	font.loadFromFile("Arcade.ttf");
	Text text("Arcade Fifteen game", font, 30);
	text.setPosition(80, 0);
	text.setFillColor(Color(R, G, B, A));

	Text Keys("Esc - Exit, F5 - New Game, Mouse Click - Move bones", font, 15);
	Keys.setPosition(15, 570);
	Keys.setFillColor(Color(R, G, B, A));

	RectangleShape rectangle(Vector2f(500, 500));
	rectangle.setFillColor(Color::Black);
	rectangle.setOutlineThickness(1);
	rectangle.move(50, 50);
	rectangle.setOutlineColor(Color(188, 0, 141));
	
	Texture bones;
	bones.loadFromFile("bones.png");

	int blockwidth = 125;
	int field[6][6] = { 0 };
	Sprite sprite[17];
	int n = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			n++;
			sprite[n].setTexture(bones);
			sprite[n].setTextureRect(IntRect(i * 125, j * 125, 125, 125));
			field[i + 1][j + 1] = n;
		}
	}


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
		if (time.asSeconds() > 2)
		{
			R = rand() % 255;
			G = rand() % 255;
			B = rand() % 255;

			text.setFillColor(Color(R, G, B, A));
			Keys.setFillColor(Color(R, G, B, A));
			clock.restart().asSeconds();
		}

		if (event.type == Event::MouseButtonPressed)
		{
			if (event.key.code == Mouse::Left)
			{
				Vector2i position = Mouse::getPosition(window);
				int x = position.x / blockwidth + 1;
				int y = position.y / blockwidth + 1;

				int dx = 0;
				int dy = 0;


				if (field[x + 1][y] == 16) { dx = 1; dy = 0; };
				if (field[x][y + 1] == 16) { dx = 0; dy = 1; };
				if (field[x][y - 1] == 16) { dx = 0; dy = -1; };
				if (field[x - 1][y] == 16) { dx = -1; dy = 0; };

				int temp = field[x][y];
				field[x][y] = 16;
				field[x + dx][y + dy] = temp;


				/*sprite[16].move(-dx * blockwidth, -dy * blockwidth);
				float speed = 6;
				for (int i = 0; i < blockwidth; i += speed)
				{
					sprite[temp].move(speed * dx, speed * dy);
					window.draw(sprite[16]);
					window.draw(sprite[temp]);
					window.display();
				}*/
			}

		}

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				int n = field[i + 1][j + 1];
				sprite[n].setPosition(i * blockwidth, j * blockwidth);
				sprite[n].move(50, 50);
				window.draw(sprite[n]);
			}


		window.display();
	}


	return 0;
}