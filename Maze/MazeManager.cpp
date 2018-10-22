#include "MazeManager.h"
#include <stdlib.h>

MazeManager::MazeManager(std::shared_ptr<Maze> maze) : isFinished(_isFinished), maze(maze) {
	_isFinished = false;
	action = Actions::None;
	recursionStack = nullptr;
	actionStatus = ActionStatus::FirstStep;
}

bool MazeManager::SelectAction(Actions action) {
	if (!_isFinished)
		return false;
	this->action = action;
}

void MazeManager::update(const float& dt) {
	RecursiveBacktracker();
}

void MazeManager::RecursiveBacktracker() {
	if (maze == nullptr)
		return;

	static sf::Vector2i size;
	static int activeNode;

	if (actionStatus == ActionStatus::FirstStep) {
		if (recursionStack == nullptr)
			recursionStack = new std::stack<int>;

		size = maze->GetSize();

		activeNode = std::rand() % size.x;

		*maze->nodes[activeNode]->top = false;
		maze->nodes[activeNode]->SetNodeStatus(NodeStatus::Active);

		actionStatus = ActionStatus::Working;
	}
	else if (actionStatus == ActionStatus::Working) {
		auto active = maze->nodes[activeNode];
		auto left = maze->nodes[activeNode - 1];

		auto neighbours = maze->GetUnvisitedNeighbours(activeNode);

		if (neighbours.size() > 0) {
			maze->nodes[activeNode]->SetNodeStatus(NodeStatus::Visited);
			recursionStack->push(activeNode);

			activeNode = neighbours[std::rand() % neighbours.size()];
			maze->OpenWall(recursionStack->top(), activeNode);
			maze->nodes[activeNode]->SetNodeStatus(NodeStatus::Active);
		}
		else if (!recursionStack->empty()) {
			maze->nodes[activeNode]->SetNodeStatus(NodeStatus::DeadEnd);

			activeNode = recursionStack->top();
			recursionStack->pop();
			maze->nodes[activeNode]->SetNodeStatus(NodeStatus::Active);
		}
	}
}

void MazeManager::SetNodeStatus(Node* node, NodeStatus status) {
	node->SetNodeStatus(status);
}