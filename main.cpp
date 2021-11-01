#include "main.h"

int main()
{
    Game game;
    game.Run();

    return 0;
}

void Game::Run()
{
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
        Systems::ClearBadInput();
        switch (m)
        {
        case 1:
            FindVillain();
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

void Game::FindVillain()
{
    m_enemy = GenerateEnemy();
    system("clear");
    std::cout << "------------------------------\n";
    std::cout << " Found '" << m_enemy->name << "'... Fight?\n";
    std::cout << " 1) Yes\n";
    std::cout << " 2) No\n";
    std::cout << "------------------------------\n";
    std::cout << m_player->name << ":\\>";
    int m = 0;
    std::cin >> m;
    Systems::ClearBadInput();
    switch (m)
    {
    case 1:
        Encounter(m_enemy);
        break;
    default:
        break;
    }
}

void Game::Encounter(Character* t_enemy)
{
    bool ActiveEncounter = true;
    while (ActiveEncounter)
    {
        system("clear");
        std::cout << "------------------------------\n";
        std::cout << t_enemy->name << ": " << t_enemy->AnnounceSelf() << "\n";
        std::cout << "Health: " << Systems::GetHealthBar(t_enemy->health) << "\n";
        std::cout << "------------------------------\n";
        std::cout << m_player->name << ": " << m_player->AnnounceSelf() << "\n";
        std::cout << "Health: " << Systems::GetHealthBar(m_player->health) << "\n";
        std::cout << "------------------------------\n";
        std::cout << m_player->name << ":\\>";
        int m = 0;
        std::cin >> m;
        Systems::ClearBadInput();

    }
    free(t_enemy);
    m_enemy = nullptr;
}

void Game::FirstTime()
{
    system("clear");
    std::cout << "What be thy name?\n";
    std::cout << "C:\\>";
    std::string s = "";
    std::cin >> s;
    Systems::ClearBadInput();
    if (s == "")
        m_player->SetName("Hero");
    else
        m_player->SetName(s);
}