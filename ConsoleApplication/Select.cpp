#include "Select.h"

// キャラ選択
void Select::SelectCharcter(Team& team, char c)
{
	// プレイヤーの場合
	if (c == 'p')
	{
		while (true)
		{
			// 行動するキャラクターを数字入力で決定
			std::cout << "0から2までの数字を入力してください" << std::endl;
			std::cout << "0 : 剣士　　1 : 魔術師　　2 : 召喚士" << std::endl;
			std::cout << "が行動します" << std::endl;
			std::cin >> playerChar_;
			if (playerChar_ >= 0 && playerChar_ <= 2) break;
			else if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	else
	{
		// 敵の場合は乱数
		enemyChar_ = rand() % 3;
	}
}

// キャラクター行動選択
void Select::SelectAction(Team& team, char c)
{
	if (c == 'p')
	{
		while (true)
		{
			// プレイヤー陣営のキャラの行動を数字入力で決定
			std::cout << "0か1を入力してください" << std::endl;
			std::cout << "0 : 攻撃　　1 : 防御" << std::endl;
			std::cin >> playerAction_;
			if (playerAction_ != 0 && playerAction_ != 1)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else break;
		}
	}
	else
	{
		// 敵の場合は乱数
		enemyAction_= rand() % 2;
	}
}

// 選択されたキャラと行動を伝える
void Select::GetSelectedData(SelectedData& data)
{
	data.playerChar = playerChar_;
	data.enemyChar = enemyChar_;
	data.playerAction = playerAction_;
	data.enemyAction = enemyAction_;
}