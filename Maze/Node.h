#pragma once
#include <SFML/Graphics.hpp>

class Node : public sf::Drawable, public sf::Transformable {
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	std::shared_ptr<bool> top;
	std::shared_ptr<bool> right;
	std::shared_ptr<bool> bottom;
	std::shared_ptr<bool> left;

	Node();
	Node(std::shared_ptr<bool> left);
	Node(std::shared_ptr<bool> left, std::shared_ptr<bool> top);
	~Node();
};