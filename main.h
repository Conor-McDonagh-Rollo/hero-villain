#ifndef MAIN_H
#define MAIN_H
#include <iostream>

class Character
{
public:
    //SETTERS
    void SetHealth(int t_health) { health = t_health; }
    void SetName(std::string t_name) { name = t_name; }

    //FUNCTIONS

    //VARIABLES
    int health = 0;
    std::string name = "Flablwabl";

    //PURE VIRTUALS
    virtual void AnnounceSelf() = 0;
};

class Player : public Character
{
public:
    Player()
    {
        SetHealth(100);
    }

    void AnnounceSelf()
    {
        std::cout << "My name is " + name + " and I am a Warrior!" << std::endl;
    }
};

class Orc : public Character
{
public:
    Orc()
    {
        SetHealth(50);
    }

    void AnnounceSelf()
    {
        std::cout << "My name is " + name + " and I am a Big Bad ORC!" << std::endl;
    }
};

class Game 
{
private:
    //PRIVATE SHIZ
public:
    bool playing { true }; //Are we still playing this beautiful game?
    
    Character* m_player = new Player();
    Character* m_enemy = new Orc();

    void FirstTime(); //LET THE GAMES VEGIN!!!!
    void Run(); //Run the game
    void Menu(); //Menu the game

    void InputGood()
    {
        while (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }
};
#endif