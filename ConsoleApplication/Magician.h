#pragma once
#include "CharacterBase.h"

class Magician : public CharacterBase
{
public:
    int GetAttack(char c) override;
    int GetDefense(char c) override;

private:
    const int attack = 33;
};

