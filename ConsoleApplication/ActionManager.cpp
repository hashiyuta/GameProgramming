#include "ActionManager.h"

// 行動するキャラクターのポインタ取得
std::shared_ptr<CharacterBase> ActionManager::GetCharPtr(Team& team, int charIndex)
{
    switch (charIndex)
    {
    case 0:
        return team.swordsman;
        break;

    case 1:
        return team.magician;
        break;

    case 2:
        return team.summoner;
        break;

    default:
        return nullptr;
        break;
    }
}

// 分岐処理
void ActionManager::ExecuteAction(Team& playerTeam, Team& enemyTeam, const SelectedData& data)
{
    auto playerChar = GetCharPtr(playerTeam, data.playerChar);
    auto enemyChar = GetCharPtr(enemyTeam, data.enemyChar);

    if (!playerChar || !enemyChar) return;

    // 両者攻撃
    if (data.playerAction == Attack && data.enemyAction == Attack)
    {
        int playerAttack = playerChar->GetAttack('p');
        int enemyAttack = enemyChar->GetAttack('e');

        if (playerAttack > enemyAttack)
        {
            std::cout << "敵陣営に " << playerAttack << " ダメージ" << std::endl;
            enemyTeam.combatPower -= playerAttack;
        }
        else if (playerAttack < enemyAttack)
        {
            std::cout << "プレイヤー陣営に " << enemyAttack << " ダメージ" << std::endl;
            playerTeam.combatPower -= enemyAttack;
        }
        else
        {
            std::cout << "互角" << std::endl;
        }
    }
    // 両者防御
    else if (data.playerAction == Defense && data.enemyAction == Defense)
    {
        playerChar->GetDefense('p');
        enemyChar->GetDefense('e');

        std::cout << "両者ともに防御" << std::endl;
    }
    // プレイヤー攻撃 敵防御
    else if (data.playerAction == Attack && data.enemyAction == Defense)
    {
        OtherAction(playerTeam, data.playerChar, enemyTeam, data.enemyChar, true);
    }
    // プレイヤー防御 敵攻撃
    else if (data.playerAction == Defense && data.enemyAction == Attack)
    {
        OtherAction(enemyTeam, data.enemyChar, playerTeam, data.playerChar, false);
    }
}

void ActionManager::OtherAction(Team& attackerTeam, int attackerIndex,
								Team& defenderTeam, int defenderIndex, bool playerAttacking)
{
    auto attacker = GetCharPtr(attackerTeam, attackerIndex);
    auto defender = GetCharPtr(defenderTeam, defenderIndex);

    // result（0 = ドロー, 1 = クリティカル, 2 = カウンター）
    int result = (attackerIndex - defenderIndex + 3) % 3;

    // ドロー
    if (result == 0)
    {
        if (playerAttacking == true)
        {
            attacker->GetAttack('p');
            defender->GetDefense('e');
        }
        else
        {
            attacker->GetAttack('e');
            defender->GetDefense('p');
        }

        std::cout << "ドロー" << std::endl;
    }

    // クリティカル
    if (result == 1)
    {
        int attack;
        int defense;

        if (playerAttacking == true)
        {
            attack = attacker->GetAttack('p');
            defense = defender->GetDefense('e');
        }
        else
        {
            attack = attacker->GetAttack('e');
            defense = defender->GetDefense('p');
        }       

        attack = attack * 2;
        defenderTeam.combatPower -= attack;

        std::cout << "クリティカル" << std::endl;
        std::cout << attack << " ダメージ" << std::endl;
    }

    // カウンター
    if (result == 2)
    {
        int attack;
        int defense;

        if (playerAttacking == true)
        {
            attack = attacker->GetAttack('p');
            defense = defender->GetDefense('e');
        }
        else
        {
            attack = attacker->GetAttack('e');
            defense = defender->GetDefense('p');
        }

        attack = attack * 2;
        attackerTeam.combatPower -= attack;

        std::cout << "カウンター" << std::endl;
        std::cout << attack << "ダメージ" << std::endl;
    }
}