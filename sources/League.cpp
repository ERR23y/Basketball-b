#include "League.hpp"

League::League(){
    this->sets = generate_teams(20);
}

League::Schedule::Schedule(League const &league){
    std::vector<Game::Team*> teams = league.sets;
        for(unsigned int i=0; i < teams.size() - 1; ++i){
            for(unsigned int j = i+1; j < teams.size(); ++j){
                this->games.push_back(new Game{*teams.at(i), *teams.at(j)});
                games.push_back(new Game{*teams.at(j), *teams.at(i)});
            }
        }
}
League::League(std::vector<Game::Team*> set_of_teams){
    /**
     * a) If set.size() > 20 throw error
     * b) If set contain same names throw error -> Sets take care of duplications
     * c) If set.size() < 20 teams -> generate amount of teams which complete it to 20 teams.
     *      Set has 4 teams - needs to generate 16 teams,
     *      set has 10 teams - needs to generate 10 teams etc.... 
     * 
     */
    if (set_of_teams.size() > MAX_TEAMS){
        throw std::invalid_argument("> Cannot add more than 20 teams");
    }
    if (set_of_teams.size() < MAX_TEAMS)
    {
        this->sets = set_of_teams;
        std::vector<Game::Team*> more = generate_teams(MAX_TEAMS - set_of_teams.size());
        for (auto& idx : more){
            this->sets.push_back(idx);
        }
    }
}

std::vector<Game::Team*>& League::generate_teams(int amount){
    srand(time(nullptr));
    std::vector<Game::Team*> teams;
    std::vector<std::string> names = {"76ers","Bucks","Bulls","Cavaliers","Celtics","Clippers","Grizzlies","Hawks","Heat","Hornets","Jazz"
    ,"Kings","Knicks","Lakers","Magic","Mavericks","Nets","Nuggets","Pacers","Pelicans"};

    for(int i = 0; i < amount; i++){
        teams.push_back(new Game::Team(names.at(i),((float)rand() / (float)RAND_MAX)));
    }
}

std::vector<Game::Team*> League::get_teams(){
    std::vector<Game::Team*> teams(20);
    for(auto& idx : this->sets){
        teams.push_back(idx);
    } 
    return teams; 
} 