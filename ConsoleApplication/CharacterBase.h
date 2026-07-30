#pragma once
#include <iostream>

class CharacterBase
{
public:
    virtual int GetAttack(char c);
    virtual int GetDefense(char c);

protected:
    int attack = 0;
};