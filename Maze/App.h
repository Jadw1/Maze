#pragma once
#include <SFML/Graphics.hpp>
#include "Maze.h"
#include "MazeManager.h"

class App {
private:
	sf::RenderWindow* _window;
	std::shared_ptr<Maze> _maze;
	MazeManager* _manager;

	void HandleEvent(sf::Event e);
	static void HandleInput();
	void Draw();

public:
	App();
	~App();

	static const float rectSize;
	static const float borderSize;

	App(int x, int y);
	void Run();
};