#pragma once
#include <stdexcept>
#include <string>

//const int MAX_TEAMS = 2; // Maybe will be used?

class Game{

public:
    bool flag = false;
    int teams;
    class Team{
        std::string team_name;
        float skill_level;
        
        public:
        Team(const std::string& _name,const float _skill);
        float getSkillLevel();
        std::string getTeamName();
        bool is_winner;
        int score;

    };

    Team *home_team;
    Team *out_team;
    int higher_score();

    Game();
    Game(Team home, Team out);
    ~Game();
};
