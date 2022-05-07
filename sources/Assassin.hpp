#ifndef PLAYER_H
#define PLAYER_H
#include "Player.hpp"
#endif

#define assassin_price 3

class coup::Assassin : public coup::Player
{
private:
    coup::Player *last_special_coup;

public:
    Assassin(coup::Game &game, std::string player_name) : Player(game, player_name, "Assassin"), last_special_coup(nullptr)
    {
        game.add_player(*this);
    }
    virtual void coup(coup::Player &player);
    ~Assassin() {}
    friend class Game;
    friend class Contessa;
};
