#pragma once
#include <stdlib.h>
#include "Swordsman.h"
#include "Magician.h"
#include "Summoner.h"
#include "Select.h"

class ActionManager
{
private:
	// 行動を定数化
	enum Action
	{
		Attack = 0,
		Defense = 1
	};

public:
	// 分岐処理
	void ExecuteAction(Team& playerTeam, Team& enemyTeam, const SelectedData& data);

private:
	// 選択されたキャラクターのポインタ取得関数
	std::shared_ptr<CharacterBase> GetCharPtr(Team& team, int charIndex);

	// 攻撃vs防御の分岐処理
	void OtherAction(Team& attackerTeam, int attackerIndex,
					 Team& defenderTeam, int defenderIndex, bool playerAttacking);
};

