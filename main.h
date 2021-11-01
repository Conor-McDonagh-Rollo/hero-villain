#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <cstdlib>
#include <time.h>
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
    std::string GetWeapon() // return enum names
    {
        if (weapon == Weapon::RUSTY_SWORD) return "Rusty Sword";
        if (weapon == Weapon::IRON_SWORD) return "Iron Sword";
        if (weapon == Weapon::STEEL_SWORD) return "Steel Sword";
        if (weapon == Weapon::IRON_GREATSWORD) return "Iron GreatSword";
        if (weapon == Weapon::STEEL_GREATSWORD) return "Steel GreatSword";
        return "";
    }
    void TakeDamage(int t_dmg)
    {
        health -= t_dmg;
    }
    int GetWeaponRoll() // return weapon dice for attackroll
    {
        if (weapon == Weapon::RUSTY_SWORD) return 4;
        if (weapon == Weapon::IRON_SWORD) return 4;
        if (weapon == Weapon::STEEL_SWORD) return 6;
        if (weapon == Weapon::IRON_GREATSWORD) return 8;
        if (weapon == Weapon::STEEL_GREATSWORD) return 12;
        return 0;
    }
    int AttackRoll() // roll damage with modifiers
    {
        int modifier = static_cast<int>(weapon);
        return (std::rand() % GetWeaponRoll() + 1) + modifier;
    }

    //VARIABLES
    int health = 1;
    int armourClass = 8;
    Weapon weapon = Weapon::RUSTY_SWORD;
    std::string name = "Person";

    //PURE VIRTUALS
    virtual std::string AnnounceSelf() = 0;
    virtual std::string AnnounceDeath() = 0;
};

class Player : public Character
{
public:
    Player()
    {
        SetHealth(30);
        SetArmourClass(12);
    }

    //PURE VIRTUALS
    std::string AnnounceSelf()
    {
        return "My name is " + name + " and I shall defeat you!";
    }

    std::string AnnounceDeath()
    {
        return "Know the name... " + name + " ... Will return!";
    }
};

//ORC CHARACTER
class Orc : public Character
{
public:
    Orc()
    {
        SetHealth(15);
        SetArmourClass(7);
        SetWeapon(Weapon::RUSTY_SWORD);
        SetName("Orc");
    }

    //PURE VIRTUALS
    std::string AnnounceSelf()
    {
        return "I am a big bad " + name + " FEAR ME!";
    }

    std::string AnnounceDeath()
    {
        return "OOOOOO MY FOOT!";
    }

};

//BEAR
class Bear : public Character
{
public:
    Bear()
    {
        SetHealth(20);
        SetArmourClass(8);
        SetWeapon(Weapon::IRON_SWORD);
        SetName("Bear");
    }

    //PURE VIRTUALS
    std::string AnnounceSelf()
    {
        return "GRAAAAAAAAAAA!";
    }

    std::string AnnounceDeath()
    {
        return "GRUUUUUUUUUUUU!";
    }
};

//BEHOLDER CHARACTER
class Beholder : public Character
{
public:
    Bear()
    {
        SetHealth(25);
        SetArmourClass(12);
        SetWeapon(Weapon::STEEL_SWORD);
        SetName("Beholder");
    }

    //PURE VIRTUALS
    std::string AnnounceSelf()
    {
        return "*Mind reading noises*";
    }

    std::string AnnounceDeath()
    {
        return "*Dead mind reading noises*";
    }
};

//MIND FLAYER CHARACTER
class MindFlayer : public Character
{
public:
    Bear()
    {
        SetHealth(35);
        SetArmourClass(15);
        SetWeapon(Weapon::IRON_GREATSWORD);
        SetName("Mind Flayer");
    }

    //PURE VIRTUALS
    std::string AnnounceSelf()
    {
        return "*Mind flayer noises*";
    }

    std::string AnnounceDeath()
    {
        return "*Dead mind flayer noises*";
    }
};

class Game
{
public:
    bool playing{ true }; //Are we still playing this beautiful game?

    Character* m_player = new Player();
    Character* m_enemy = nullptr;

    int playerGold = 0;

    void FirstTime(); //LET THE GAMES VEGIN!!!!
    void Run(); //Run the game
    void Menu(); //Menu the game
    void Shop();
    void FindVillain();
    void Encounter(Character* t_enemy);
    std::string RandomLoot();

    Character* GenerateEnemy() // ptr to a ptr
    {
        Character* gen;
        int r = rand() % 4 + 1;
        if (r == 1) gen = new Orc();
        if (r == 2) gen = new Bear();
        if (r == 3) gen = new Beholder();
        if (r == 4) gen = new MindFlayer();
        return gen; // choose which enemy we fight
    }
};
#endif