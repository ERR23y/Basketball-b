#include "Game.hpp"

Game::Game(){
    this->teams = 0;
    this->home_team = nullptr;
    this->out_team = nullptr;
}

Game::Team::Team(const std::string& _name,const float _skill) : team_name(_name) , skill_level(_skill), score(0), is_winner(false){}


Game::Game(Team home, Team out){
    if (this->flag != false){
        throw std::invalid_argument("> Game already started cannot change teams!");
    }
    if (home.getTeamName() == out.getTeamName()){
        throw std::invalid_argument("> Teams need to have different names");
    }
    
    this->home_team = new Team(home);
    this->out_team = new Team(out);
    this->flag = true;
}

int Game::higher_score(){
    return this->home_team->score > this->out_team->score ? this->home_team->score : this->out_team->score;
}

float Game::Team::getSkillLevel(){return this->skill_level;}

std::string Game::Team::getTeamName(){return this->team_name;}

Game::~Game(){
    delete this->home_team;
    delete this->out_team;
}