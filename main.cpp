#include "main.h"

int main()
{
    Game game;
    game.Run();

    return 0;
}

void Game::Run()
{
    m_player->AnnounceSelf();
    m_enemy->AnnounceSelf();
    Menu();
}

void Game::Menu()
{
    FirstTime();
    while (playing)
    {
        system("clear");
        std::cout << "------------------------------\n";
        std::cout << "--  Heroes                  --\n";
        std::cout << "--           &              --\n";
        std::cout << "--               Villains   --\n";
        std::cout << "------------------------------\n";
        std::cout << "-- 1) Find a new Villain    --\n";
        std::cout << "-- 2) View battle stats     --\n";
        std::cout << "-- 3) Exit                  --\n";
        std::cout << "------------------------------\n";
        std::cout << m_player->name << ":\\>";
        int m = 0;
        std::cin >> m;
        InputGood();
        switch(m)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                playing = false;
                break;
            default:
                break;
        }
    }
}

void Game::FirstTime()
{
    system("clear");
    std::cout << "What be thy name?\n";
    std::cout << "C:\\>";
    std::string s = "";
    std::cin >> s;
    InputGood();
    if (s == "")
        m_player->SetName("Hero");
    else
        m_player->SetName(s);
}