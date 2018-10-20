#pragma once
#include <SFML/Graphics.hpp>
#include "Node.h"


class Maze : public sf::Drawable {
private:
	int _xSize;
	int _ySize;

	void GenerateMaze();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates status) const;

public:
	Node** nodes;

	Maze(int xSize, int ySize);
	~Maze();
};