#pragma once
#include "CharacterBase.h"

class Swordsman : public CharacterBase
{
public:
    int GetAttack(char c) override;
    int GetDefense(char c) override;

private:
    const int attack = 35;
};