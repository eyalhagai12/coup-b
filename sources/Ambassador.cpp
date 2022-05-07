#include "Ambassador.hpp"

#ifndef CAP_H
#define CAP_H
#include "Captain.hpp"
#endif

void coup::Ambassador::transfer(coup::Player &from, coup::Player &to)
{
    if (this->n_coins >= must_coup)
    {
        throw "You have atleast 10 coins you must coup!\n";
    }

    if (from.n_coins > 0)
    {
        from.n_coins -= 1;
        to.n_coins += 1;
        this->game.end_turn();
    }
    else
    {
        throw "Not Enough Coins\n";
    }
}
void coup::Ambassador::block(coup::Player &player)
{
    if (this->game.can_block(player, "Ambassador"))
    {
        player.n_coins -= captain_steals;
        coup::Captain &captain = dynamic_cast<Captain &>(player); // player must be a Captain
        captain.stole_from->n_coins += captain_steals;
    }
    else
    {
        throw "Invalid Block\n";
    }
}