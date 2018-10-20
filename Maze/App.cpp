#include "App.h"
#include <SFML/Graphics.hpp>

#pragma region Constructors & Destructor
const float App::rectSize = 35.0f;
const float App::borderSize = 5.0f;

App::App() {
	_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Maze");
	_clock = new sf::Clock();
}

App::App(int x, int y) : App() {
	_maze = new Maze(x, y);
}

App::~App() {
	delete _window;
	delete _maze;
	delete _clock;
}
#pragma endregion


void App::Run() {
	*_maze->nodes[0]->right = true;
	while (_window->isOpen()) {
		auto t1 = *_maze->nodes;
		auto t2 = *(_maze->nodes + 1);
		auto t3 = *(_maze->nodes + 2);
		auto t4 = *(_maze->nodes + 3);


		deltaTime = _clock->restart().asSeconds();
		sf::Event e;
		while (_window->pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				_window->close();
			}
		}

		_window->clear();
		_window->draw(*_maze);
		_window->display();

	}
}