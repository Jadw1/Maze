#include "App.h"
#include "MazeManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

#pragma region Constructors & Destructor
const float App::rectSize = 35.0f;
const float App::borderSize = 2.0f;

App::App() {
	_window = new sf::RenderWindow(sf::VideoMode(800, 800), "Maze");

	std::srand(std::time(nullptr));
}

App::App(int x, int y) : App() {
	std::shared_ptr<Maze> temp(new Maze(x, y));
	_maze.swap(temp);
	_manager = new MazeManager(_maze);

}

App::~App() {
	delete _window;
	delete _manager;
}
#pragma endregion


void App::Run() {
	/**_maze->nodes[0]->right = true;
	*_maze->nodes[1]->bottom = true;
	*_maze->nodes[1 + 20]->bottom = true;
	*_maze->nodes[1 + 20 + 20]->bottom = true;

	*_maze->nodes[5]->bottom = true;
	*_maze->nodes[5]->right = true;
	*_maze->nodes[5 + 20]->right = true;
	*_maze->nodes[6]->bottom = true;*/

	sf::Clock clock;
	float deltaTime;

	while (_window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event e;

		while (_window->pollEvent(e))
			HandleEvent(e);

		_manager->update(deltaTime);

		Draw();
	}

}

void App::HandleEvent(sf::Event e) {
	if (e.type == sf::Event::Closed) {
		_window->close();
	}
	else if (e.type == sf::Event::KeyPressed || e.type == sf::Event::KeyReleased) {
		HandleInput();
	}
	else if (e.type == sf::Event::Resized) {
		_window->setSize(sf::Vector2u(e.size.width, e.size.height));
	}
}

void App::HandleInput() {
	std::cout << "test\n";
}

void App::Draw() {
	_window->clear();
	_window->draw(*_maze);
	_window->display();
}