#pragma once
#include <string>
#include <unordered_set>
#include "Game.hpp"
#include <vector>
#include <random>
#include <time.h>

const int MAX_TEAMS = 20;

class League{

public:
    class Schedule{
        public:
        Schedule(League const &league);
        std::vector<Game*> games;
    };
    std::vector<Game::Team*> sets;
    League(); // Inner making sets - option a
    League(std::vector<Game::Team*> set_of_teams); // Option b - a given set of 20 teams or a set of a certain amount of teams and it will auto complete it into 20 teams


    std::vector<Game::Team*> get_teams();

    std::vector<Game::Team*>& generate_teams(int amount);
};
