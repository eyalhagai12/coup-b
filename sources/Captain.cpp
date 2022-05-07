#include "Captain.hpp"

void coup::Captain::steal(coup::Player &player)
{
    if (this->n_coins >= must_coup)
    {
        throw "You have atleast 10 coins you must coup!\n";
    }

    if (this->game.turn() == this->name && player.n_coins >= captain_steals)
    {
        player.n_coins -= captain_steals;
        this->n_coins += captain_steals;
        this->game.add_blockable(this, "Captain");
        this->game.add_blockable(this, "Ambassador");
        this->stole_from = &player;
        this->game.end_turn();
    }
    else if (this->game.turn() == this->name && player.n_coins > 0)
    {
        this->n_coins += player.n_coins;
        player.n_coins = 0;
        this->game.end_turn();
    }
    else
    {
        throw "Not Enough Coins!\n";
    }
}
void coup::Captain::block(coup::Player &player)
{
    if (this->game.can_block(player, "Captain") && this->game.can_block(player, "Ambassador"))
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