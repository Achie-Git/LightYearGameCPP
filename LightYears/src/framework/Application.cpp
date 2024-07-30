#include "framework/Application.h"
#include <iostream>

namespace ly
{
	Application::Application() : mWindow{ sf::VideoMode(1024,1440),"Light Years" }, mTargetFrameRate{ 60.f }, mTickClock{}
	{
		
	}

	void Application::Run()
	{
		mTickClock.restart();
		float acumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
			//float frameDeltaTime = mTickClock.restart().asSeconds();
			acumulatedTime += mTickClock.restart().asSeconds();
			while (acumulatedTime > targetDeltaTime)
			{
				acumulatedTime -= targetDeltaTime;
				Tick(targetDeltaTime);
				Render();
			}

		}

	}

	void Application::Tick(float deltaTime)
	{
		std::cout << "ticking at framerate: " << 1.f / deltaTime << std::endl;

	}

	void Application::Render()
	{
	}

}