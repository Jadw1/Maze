#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maze.h"
#include "App.h"

Maze::Maze(int xSize, int ySize) {
	_xSize = xSize;
	_ySize = ySize;

	nodes = new Node*[_xSize * _ySize];
	GenerateMaze();
}

Maze::~Maze() {
	for (int i = 0; i < _xSize*_ySize; i++) {
		std::cout << i + " deleted" << std::endl;
		delete nodes[i];
	}
	delete[] nodes;
}

void Maze::GenerateMaze() {
	float unitLength = App::rectSize + App::borderSize * 2;

	for (int i = 0; i < _xSize * _ySize; i++) {
		
		auto debugging = (i > 0) ? nodes[i - 1] : nullptr;

		auto left = (i % _xSize == 0) ? nullptr : nodes[i - 1]->right;
		auto top = (i / _xSize == 0) ? nullptr : nodes[i - _xSize]->bottom;
		nodes[i] = new Node(left, top);

		nodes[i]->setPosition(sf::Vector2f(i % _xSize, i / _xSize) * unitLength);
	}
}

void Maze::draw(sf::RenderTarget& target, sf::RenderStates status) const {
	for (int i = 0; i < _xSize * _ySize; i++) {
		target.draw(*nodes[i], status);
	}
}