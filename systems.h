#ifndef SYSTEMS_H
#define SYSTEMS_H
#include <iostream>

enum class Weapon
{
    RUSTY_SWORD = 1,
    IRON_SWORD = 2,
    STEEL_SWORD = 3,
    IRON_GREATSWORD = 4,
    STEEL_GREATSWORD = 5
};

class Systems
{
public:
    static void ClearBadInput()
    {
        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }

    static bool InputGood()
    {
        if (std::cin.good())
            return true;
        return false;
    }

    static std::string GetHealthBar(int t_health)
    {
        std::string healthbar = "";
        for (int i = 0; i < t_health / 10; i++)
        {
            healthbar.append("=");
        }
        return healthbar;
    }
};

#endif