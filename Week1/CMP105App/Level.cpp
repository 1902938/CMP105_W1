#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	//Initialise Game Objects
	//Stacked Rectangles
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rect2.setSize(sf::Vector2f(30, 30));
	rect2.setPosition(110, 110);
	rect2.setFillColor(sf::Color::Green);

	rect3.setSize(sf::Vector2f(10, 10));
	rect3.setPosition(120, 120);
	rect3.setFillColor(sf::Color::Blue);

	//Corner Rectangle
	rect4.setSize(sf::Vector2f(30, 30));
	rect4.setFillColor(sf::Color::Green);

	circle.setRadius(50);
	circle.setPosition(550, 288);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(3.f);

	//Initialize Text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(550, 10);
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
	pos.x -= 30; pos.y -= 30;
	rect4.setPosition(pos.x, pos.y);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(rect2);
	window->draw(rect3);
	window->draw(circle);

	window->draw(rect4);

	window->draw(text);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}