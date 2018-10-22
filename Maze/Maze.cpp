#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maze.h"
#include "App.h"

#pragma region Constructor&Destructor
Maze::Maze(int xSize, int ySize) {
	_xSize = xSize;
	_ySize = ySize;

	nodes = new Node*[_xSize * _ySize];
	GenerateMaze();
}

Maze::~Maze() {
	for (int i = 0; i < _xSize*_ySize; i++) {
		delete nodes[i];
	}
	delete[] nodes;
}
#pragma endregion

void Maze::GenerateMaze() {
	float unitLength = App::rectSize + App::borderSize * 2;

	for (int i = 0; i < _xSize * _ySize; i++) {
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

std::vector<int> Maze::GetUnvisitedNeighbours(int i) {
	std::vector<int> vec;

	if (i / _xSize != 0 && !nodes[i - _xSize]->visited)
		vec.push_back(i - _xSize);
	if (i % _xSize != _xSize - 1 && !nodes[i + 1]->visited)
		vec.push_back(i + 1);
	if (i / _xSize != _ySize - 1 && !nodes[i + _xSize]->visited)
		vec.push_back(i + _xSize);
	if (i % _xSize != 0 && !nodes[i - 1]->visited)
		vec.push_back(i - 1);

	return vec;
}

sf::Vector2i Maze::GetSize() {
	return sf::Vector2i(_xSize, _ySize);
}

bool Maze::OpenWall(int from, int to) {
	if (from >= _xSize * _ySize || to >= _xSize * _ySize)
		return false;

	if (from - _xSize == to) {
		*nodes[from]->top = true;
		return true;
	}
	else if (from + 1 == to) {
		*nodes[from]->right = true;
		return true;
	}
	else if (from + _xSize == to) {
		*nodes[from]->bottom = true;
		return true;
	}
	else if (from - 1 == to) {
		*nodes[from]->left = true;
		return true;
	}
	return false;
}