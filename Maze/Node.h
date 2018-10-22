#pragma once
#include <SFML/Graphics.hpp>

enum NodeStatus {
	Default,
	Active,
	Visited,
	DeadEnd
};

static sf::Color StatusToColor(NodeStatus status) {
	if (status == NodeStatus::Default) return sf::Color::White;
	else if (status == NodeStatus::Active) return sf::Color::Green;
	else if (status == NodeStatus::Visited) return sf::Color::Blue;
	else if (status == NodeStatus::DeadEnd) return sf::Color::Red;
	return sf::Color::White;
}

class Node : public sf::Drawable, public sf::Transformable {
private:
	NodeStatus status;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	std::shared_ptr<bool> top;
	std::shared_ptr<bool> right;
	std::shared_ptr<bool> bottom;
	std::shared_ptr<bool> left;
	bool visited;


	void SetNodeStatus(NodeStatus status);

	Node();
	Node(std::shared_ptr<bool> left);
	Node(std::shared_ptr<bool> left, std::shared_ptr<bool> top);
};