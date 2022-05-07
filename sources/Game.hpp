#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

#define max_players 6

namespace coup
{
    // declare the names of the classes in the namespace
    class Game;
    class Player;
    class Duke;
    class Assassin;
    class Ambassador;
    class Captain;
    class Contessa;
} // namespace coup

class coup::Game
{
private:
    std::vector<coup::Player *> player_list; // the list of players
    size_t current_player;                 // a pointer that keeps track of the current player

    // a map that keeps a list of all the players a role can block, the key is the blocking role and the value
    // is a list of pointer to players that can be blocked
    std::unordered_map<std::string, std::vector<coup::Player *>> blockable_dict;

    bool game_started;

public:
    Game() : current_player(0), game_started(false)
    {
        std::vector<std::string> role_list = {"Duke", "Assassin", "Ambassador", "Captain", "Contessa"};

        for (std::string role : role_list)
        {
            std::pair<std::string, std::vector<coup::Player *>> kv_pair = {role, std::vector<coup::Player *>()};
            blockable_dict.insert(kv_pair);
        }
    }
    void add_player(coup::Player &player);
    void add_blockable(coup::Player *player, const std::string &blocking_role);
    bool can_block(coup::Player &player_to_block, const std::string &my_role);
    void remove_blockable_player();
    void print_players();
    std::vector<std::string> players();
    std::string turn();
    std::string winner();
    void end_turn();
    ~Game() {}
};
