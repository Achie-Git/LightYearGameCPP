#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow renderWindow{ sf::VideoMode(100,100),"My Window" };

	while (renderWindow.isOpen())
	{
		sf::Event windowEvent;
		while (renderWindow.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}
		}
	}

	std::cout << "Hello World! \n";
}