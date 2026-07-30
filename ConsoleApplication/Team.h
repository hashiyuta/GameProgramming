#pragma once
#include <memory>
#include "Swordsman.h"
#include "Magician.h"
#include "Summoner.h"

struct Team
{
    int combatPower = 300;                 // 戦力
    std::shared_ptr<Swordsman> swordsman;  // 剣士
    std::shared_ptr<Magician> magician;    // 魔術師
    std::shared_ptr<Summoner> summoner;    // 召喚士

    // コンストラクタ（newでインスタンス化）
    Team()
    {
        swordsman = std::shared_ptr<Swordsman>(new Swordsman());
        magician = std::shared_ptr<Magician>(new Magician());
        summoner = std::shared_ptr<Summoner>(new Summoner());
    }
};

