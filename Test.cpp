#include "doctest.h"
#include <iostream>
#include <random>
#include <iomanip>
#include "League.hpp"
#include "Game.hpp"
#include <vector>

using namespace std;

constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;

TEST_CASE("Team making"){
    srand(time(nullptr));
    vector<string> vec = {"\a","\b","\f","\n","\t","\v","\\","\'","\"","\?"};
    // Bad team name
    for (auto& idx : vec){
        CHECK_THROWS(Game::Team a(idx,(float)rand() / (float)RAND_MAX));
    }
    // Minus random float number
    CHECK_THROWS(Game::Team a("Bulls",-((float)rand() / (float)RAND_MAX)));

    // Generate random number bigger than 1
    CHECK_THROWS(Game::Team a("BLA",rand() % 100));

    // Generate random number smaller than 0
    CHECK_THROWS(Game::Team a("BLA",-(rand() % 100)));

    // Try both a negative skill_level an bad chars as well
    for (auto& idx : vec){
        CHECK_THROWS(Game::Team a(idx,-((float)rand() / (float)RAND_MAX)));
    }


}
