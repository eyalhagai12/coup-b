#ifndef PLAYER_H
#define PLAYER_H
#include "Player.hpp"
#endif

#define captain_steals 2

class coup::Captain : public coup::Player
{
private:
    coup::Player *stole_from;

public:
    Captain(coup::Game &game, std::string player_name) : Player(game, player_name, "Captain"), stole_from(nullptr)
    {
        this->game.add_player(*this);
    }
    void steal(coup::Player &player);
    void block(coup::Player &player);
    ~Captain() {}
    friend class Game;
    friend class Ambassador;
};
