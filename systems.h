#ifndef SYSTEMS_H
#define SYSTEMS_H
#include <iostream>
#include <vector>

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

    /*
        written in format:
        { "How is the weather today?", "Good", "Bad", "", "" },
        { "What was the answer to the assignment?", "A", "B", "C", "D" },
        { "Which do you prefer?", "Sword", "Bow", "Axe", "" }
    */
    static void Question(const std::vector<std::vector<std::string>> &t_question)
    {
        for (int i = 0; i < t_question.size(); i++)
        {
            for (int j = 0; j < t_question[i].size(); j++)
            {
                std::cout << "\n" << t_question[i][0];
                std::cout << "\n"
            }
        }
    }
};

#endif