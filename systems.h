#ifndef SYSTEMS_H
#define SYSTEMS_H
#include <iostream>

enum class Weapon // THE WEAPONS
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
    static void ClearBadInput() // Get rid of garbage input for cin
    {
        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }

    static std::string GetHealthBar(int t_health) // RETURN THE HEALTH (divided)
    {
        std::string healthbar = "";
        for (int i = 0; i < t_health / 2; i++)
        {
            healthbar.append("=");
        }
        return healthbar;
    }
};

#endif