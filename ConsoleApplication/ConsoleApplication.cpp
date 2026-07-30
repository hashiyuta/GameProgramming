#include <iostream>
#include <memory>
#include <time.h>
#include <stdlib.h>
#include "Team.h"
#include "CharacterBase.h"
#include "Swordsman.h"
#include "Magician.h"
#include "Summoner.h"
#include "Select.h"
#include "ActionManager.h"

int main()
{
    srand((unsigned int)time(NULL));

    // キャラクター生成
    Team playerTeam;
    Team enemyTeam;

    Select select;
    SelectedData selectedData;

    ActionManager actionManager;

    while (true)
    {
        // 各陣営の行動キャラを選択
        select.SelectCharcter(playerTeam, 'p');
        select.SelectCharcter(enemyTeam, 'e');

        // キャラの行動を決定
        select.SelectAction(playerTeam, 'p');
        select.SelectAction(enemyTeam, 'e');

        select.GetSelectedData(selectedData);

        // 攻撃、防御の実行
        actionManager.ExecuteAction(playerTeam, enemyTeam, selectedData);

        // 両陣営戦力確認
        if (playerTeam.combatPower <= 0)
        {
            playerTeam.combatPower = 0;
            std::cout << "敗北しました" << std::endl;
            break;
        }
        else if (enemyTeam.combatPower <= 0)
        {
            enemyTeam.combatPower = 0;
            std::cout << "勝利しました" << std::endl;
            break;
        }
    }

    return 0;
}