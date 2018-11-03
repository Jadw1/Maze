#pragma once
#include <stack>
#include <utility>
#include "Maze.h"
enum Actions {
	None,
	RecursiveBacktracker
};

enum ActionStatus {
	Idle,
	FirstStep,
	Working,
	Done
};



class MazeManager {
private:
	std::shared_ptr<Maze> maze;
	bool _isFinished;
	Actions action;
	ActionStatus actionStatus;

	std::stack<int>* recursionStack;

	void RecursiveBacktracker();
	void SetNodeStatus(Node* node, NodeStatus status);

public:
	const bool& isFinished;

	MazeManager(std::shared_ptr<Maze> maze);
	bool SelectAction(Actions action);
	void update(const float &dt);
};
