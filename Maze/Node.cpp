#include <iostream>
#include "Node.h"
#include "App.h"


#pragma region Constructors & Destructor
Node::Node() : top(new bool(false)), right(new bool(false)), bottom(new bool(false)), left(new bool(false)) {
}

Node::Node(std::shared_ptr<bool> left) : Node() {
	if (left != nullptr) {
		std::shared_ptr<bool> temp(left);
		this->left.swap(temp);
	}
}

Node::Node(std::shared_ptr<bool> left, std::shared_ptr<bool> top) : Node(left) {
	if (top != nullptr) {
		std::shared_ptr<bool> temp(top);
		this->top.swap(top);
	}
}
#pragma endregion

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	float fullSize = App::rectSize + App::borderSize * 2;
	states.transform *= getTransform();


	sf::RectangleShape rect(sf::Vector2f(fullSize, fullSize)); //TODO: Make size as variable
	rect.setFillColor(sf::Color::White);
	target.draw(rect, states);


	sf::ConvexShape border;
	border.setPointCount(4);
	border.setPoint(0, sf::Vector2f(0.0f, 0.0f));
	border.setPoint(1, sf::Vector2f(fullSize, 0.0f));
	border.setPoint(2, sf::Vector2f(App::rectSize + App::borderSize, App::borderSize));
	border.setPoint(3, sf::Vector2f(App::borderSize, App::borderSize));
	border.setOrigin(sf::Vector2f(fullSize / 2, App::borderSize / 2));
	border.setFillColor(sf::Color::Black);

	if (!*top) {
		border.setRotation(0.0f);
		border.setPosition(sf::Vector2f(fullSize / 2, App::borderSize / 2));
		target.draw(border, states);
	}
	if (!*right) {
		border.setRotation(90.0f);
		border.setPosition(sf::Vector2f(App::borderSize * 1.5f + App::rectSize, fullSize / 2));
		target.draw(border, states);
	}
	if (!*bottom) {
		border.setRotation(180.0f);
		border.setPosition(sf::Vector2f(fullSize / 2, App::borderSize * 1.5f + App::rectSize));
		target.draw(border, states);
	}
	if (!*left) {
		border.setRotation(270.0f);
		border.setPosition(sf::Vector2f(App::borderSize / 2, fullSize / 2));
		target.draw(border, states);
	}

}