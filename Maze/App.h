#pragma once
#include <SFML/Graphics.hpp>
#include "Maze.h"

class App {
private:
	sf::RenderWindow* _window;
	Maze* _maze;
	sf::Clock* _clock;

	float deltaTime;

	//static float _rectSize;
	//static float _borderSize;

public:
	App();
	~App();

	static const float rectSize;
	static const float borderSize;

	App(int x, int y);
	void Run();
};