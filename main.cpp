#include "main.h"

int main()
{
    Game game;
    game.Run();

    return 0;
}

void Game::Run()
{
    srand(time(NULL));
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
        std::cout << "-- 2) Visit Blacksmith      --\n";
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
    m_player->SetHealth(100);
    bool ActiveEncounter = true;
    bool BlockedAttack = false;
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
        std::cout << " 1) Use " << m_player->GetWeapon() << "\n";
        std::cout << " 2) Parry\n";
        std::cout << " 3) Flee \n";
        std::cout << "------------------------------\n";
        std::cout << m_player->name << ":\\>";
        int m = 0;
        std::cin >> m;
        Systems::ClearBadInput();
        switch (m)
        {
          case 2:
            int dmg = t_enemy->AttackRoll();
            if (dmg > m_player->armourClass/2)
            {
              std::cout << "\nYour parry fails and '" << t_enemy->name << "' attacks you and deals " << dmg << " damage.";
              m_player->TakeDamage(dmg);
              break;
            }
            else
            {
              BlockedAttack = true;
              std::cout << "\nYou parry '" << t_enemy->name << "' stunning them!";
            }
            break;
          case 3:
            int rnd = rand() % 2 + 1;
            if (rnd == 1) ActiveEncounter = false;
            break;
          default:
            int dmg = m_player->AttackRoll();
            std::cout << "\nYou attack '" << t_enemy->name << "' and deal " << dmg << " damage.";
            t_enemy->TakeDamage(dmg);
            if (!BlockedAttack)
            {
              dmg = t_enemy->AttackRoll();
              std::cout << "\n'" << t_enemy->name << "' attacks you and deals " << dmg << " damage.";
              m_player->TakeDamage(dmg);
            }
            else
            {
              BlockedAttack = false;
              std::cout << "\n" << t_enemy->name << " is still stunned from the previous parry!";
            }
            break;
        }
        system("cmd /C pause");
        if (t_enemy->health <= 0)
        {
          std::cout << "\n" << t_enemy->name << " was defeated and you have received " << RandomLoot();
          ActiveEncounter = false;
          system("cmd /C pause");
        }
        else if (m_player->health <= 0)
        {
          std::cout << "\nYou have died!";
          system("cmd /C pause");
          playing = false;
          ActiveEncounter = false;
        }
    }
    free(t_enemy);
    m_enemy = nullptr;
}

std::string Game::RandomLoot()
{
  int rnd = rand() % 5 + 1;
  if (rnd == 1)
  {
    playerGold += 5;
    return "5 Gold";
  }
  if (rnd == 2)
  {
    playerGold += 10;
    return "10 Gold";
  }
  if (rnd == 3)
  {
    playerGold += 25;
    return "25 Gold";
  }
  if (rnd == 4)
  {
    playerGold += 50;
    return "50 Gold";
  }
  if (rnd == 5)
  {
    playerGold += 100;
    return "100 Gold";
  }
  return "nothing";
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