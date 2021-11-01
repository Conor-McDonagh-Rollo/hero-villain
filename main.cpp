#include "main.h"

int main()
{
    Game game;
    game.Run();

    return 0;
}

void Game::Run()
{
    srand(time(NULL)); //seed rand
    Menu();
}

void Game::Menu() // MAIN MENU
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
            FindVillain(); // begin encounter stuffs
            break;
        case 2:
            Shop(); // go to shop
            break;
        case 3:
            playing = false; // exit game loop
            break;
        default:
            break;
        }
    }
}

void Game::Shop()
{
    system("clear"); // BLACKSMITH SHOP
    std::cout << "------------------------------\n";
    std::cout << "Your current weapon: " << m_player->GetWeapon() << "\n";
    std::cout << "Your current gold: " << playerGold << "\n";
    std::cout << "1) Rusty Sword - 10g\n" << "2) Iron Sword - 50g\n" << "3) Steel Sword - 100g\n" << "4) Iron GreatSword - 250g\n" << "5) Steel GreatSword - 500g\n" << "6) Exit\n";
    std::cout << "------------------------------\n";
    std::cout << m_player->name << ":\\>";
    int m = 0;
    std::cin >> m;
    Systems::ClearBadInput();
    switch (m)
    {
    case 1:
        if (playerGold >= 10)
        {
          playerGold -= 10;
          m_player->SetWeapon(Weapon::RUSTY_SWORD);
        }
        break;
    case 2:
        if (playerGold >= 10)
        {
          playerGold -= 50;
          m_player->SetWeapon(Weapon::IRON_SWORD);
        }
        break;
    case 3:
        if (playerGold >= 10)
        {
          playerGold -= 100;
          m_player->SetWeapon(Weapon::STEEL_SWORD);
        }
        break;
    case 4:
        if (playerGold >= 10)
        {
          playerGold -= 250;
          m_player->SetWeapon(Weapon::IRON_GREATSWORD);
        }
        break;
    case 5:
        if (playerGold >= 10)
        {
          playerGold -= 500;
          m_player->SetWeapon(Weapon::STEEL_GREATSWORD);
        }
        break;    
    default:
        break;
    }
}

void Game::FindVillain()
{
    m_enemy = GenerateEnemy(); // Make the neemy
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
        Encounter(m_enemy); // pass the enemy
        break;
    default:
        break;
    }
}

void Game::Encounter(Character* t_enemy)
{
    m_player->SetHealth(30);
    bool ActiveEncounter = true;
    bool BlockedAttack = false;
    while (ActiveEncounter) // encounter loop
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
        switch (m) // DAMAGE AND OTHER STUFF code hurts eyes (wear sunscreen)
        {
          case 2:
          {
            int dmg = t_enemy->AttackRoll();
            if (dmg > m_player->armourClass/2)
            {
              std::cout << "\nYour parry fails and '" << t_enemy->name << "' attacks you and deals " << dmg << " damage.\n";
              m_player->TakeDamage(dmg);
              break;
            }
            else
            {
              BlockedAttack = true;
              std::cout << "\nYou parry '" << t_enemy->name << "' stunning them!\n";
            }
            break;
          }
          case 3:
          {
            int rnd = rand() % 2 + 1;
            if (rnd == 1) ActiveEncounter = false;
            break;
          }
          default:
          {
            int dmg = m_player->AttackRoll();
            std::cout << "\nYou attack '" << t_enemy->name << "' and deal " << dmg << " damage.\n";
            t_enemy->TakeDamage(dmg);
            if (!BlockedAttack)
            {
              dmg = t_enemy->AttackRoll();
              std::cout << "\n'" << t_enemy->name << "' attacks you and deals " << dmg << " damage.\n";
              m_player->TakeDamage(dmg);
            }
            else
            {
              BlockedAttack = false;
              std::cout << "\n" << t_enemy->name << " is still stunned from the previous parry!\n";
            }
            break;
          }
        }
        system("cmd /C pause");
        if (t_enemy->health <= 0) // Enemy has died
        {
          std::cout << "\n" << t_enemy->AnnounceDeath(); // loot
          std::cout << "\n" << t_enemy->name << " was defeated and you have received " << RandomLoot() << std::endl;
          ActiveEncounter = false;
          system("cmd /C pause");
        }
        else if (m_player->health <= 0) // you have died!
        {
          std::cout << "\n" << m_player->AnnounceDeath();
          std::cout << "\nYou have died!\n";
          system("cmd /C pause");
          playing = false;
          ActiveEncounter = false;
        }
        std::cout << "\n";
    }
    free(t_enemy); // free the enemy that was generated and replace with null
    m_enemy = nullptr;
}

std::string Game::RandomLoot()
{
  int rnd = rand() % 5 + 1; // VERY FAIR LOOT TABLE
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
    std::cout << "What be thy name?\n"; // set the players name for the game
    std::cout << "C:\\>";
    std::string s = "";
    std::cin >> s;
    Systems::ClearBadInput();
    if (s == "")
        m_player->SetName("Hero");
    else
        m_player->SetName(s);
}