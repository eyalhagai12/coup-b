#include "Assassin.hpp"

void coup::Assassin::coup(coup::Player &player)
{
    if (player.is_alive() && this->n_coins >= assassin_price && this->n_coins < coup_price)
    {
        this->n_coins -= assassin_price;
        player.die();
        this->game.add_blockable(this, "Contessa");
        this->last_special_coup = &player;
        this->game.end_turn();
    }
    else if (player.is_alive() && this->n_coins >= coup_price)
    {
        this->n_coins -= coup_price;
        player.die();
        this->game.end_turn();
    }
    else
    {
        throw "Player is already dead or you dont have enough coins!\n";
    }
}