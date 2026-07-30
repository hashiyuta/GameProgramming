#pragma once
#include <memory>
#include <iostream>
#include "Team.h"

struct SelectedData
{
	int playerChar;
	int enemyChar;
	int playerAction;
	int enemyAction;
};

class Select
{
public:
	void SelectCharcter(Team& team, char c);
	void SelectAction(Team& team, char c);
	void GetSelectedData(SelectedData& data);

private:
	int playerChar_ = 0;
	int enemyChar_ = 0;
	int playerAction_ = 0;
	int enemyAction_ = 0;
};