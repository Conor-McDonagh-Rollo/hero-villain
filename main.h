#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <cstdlib>
#include "systems.h"

class Character
{
public:
    //CONSTRUCTORS
    Character() {}

    //SETTERS
    void SetHealth(int t_health) { health = t_health; }
    void SetName(std::string t_name) { name = t_name; }
    void SetArmourClass(int t_class) { armourClass = t_class; }
    void SetWeapon(Weapon t_weapon) { weapon = t_weapon; }

    //FUNCTIONS
    std::string GetWeapon()
    {
        if (weapon == Weapon::RUSTY_SWORD) return "Rusty Sword";
        if (weapon == Weapon::IRON_SWORD) return "Iron Sword";
        if (weapon == Weapon::STEEL_SWORD) return "Steel Sword";
        if (weapon == Weapon::IRON_GREATSWORD) return "Iron GreatSword";
        if (weapon == Weapon::STEEL_GREATSWORD) return "Steel GreatSword";
    }
    int GetWeaponRoll()
    {
        if (weapon == Weapon::RUSTY_SWORD) return 4;
        if (weapon == Weapon::IRON_SWORD) return 4;
        if (weapon == Weapon::STEEL_SWORD) return 6;
        if (weapon == Weapon::IRON_GREATSWORD) return 8;
        if (weapon == Weapon::STEEL_GREATSWORD) return 12;
    }
    int AttackRoll()
    {
        return (std::rand() % GetWeaponRoll() + 1) /*+ weapon*/;
    }

    //VARIABLES
    int health = 1;
    int armourClass = 8;
    Weapon weapon = Weapon::RUSTY_SWORD;
    std::string name = "Person";

    //PURE VIRTUALS
    virtual std::string AnnounceSelf() = 0;
};

class Player : public Character
{
public:
    Player()
    {
        SetHealth(100);
    }

    //PURE VIRTUALS
    std::string AnnounceSelf()
    {
        return "My name is " + name + " and I shall defeat you!";
    }
};

class Orc : public Character
{
public:
    Orc()
    {
        SetHealth(50);
        if (name != "Person") SetName("Orc");
    }

    //PURE VIRTUALS
    std::string AnnounceSelf()
    {
        return "I am a big bad " + name + " FEAR ME!";
    }

};

class Game
{
private:
    //PRIVATE SHIZ
public:
    bool playing{ true }; //Are we still playing this beautiful game?

    Character* m_player = new Player();
    Character* m_enemy = new Orc();
    Character* m_enemy2 = new Orc();

    void FirstTime(); //LET THE GAMES VEGIN!!!!
    void Run(); //Run the game
    void Menu(); //Menu the game
    void FindVillain();
    void Encounter(Character* t_enemy);
};
#endif