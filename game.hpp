#ifndef _game_hpp_

#define _game_hpp_
#include <string>
#include <vector> 
//#include <time.h>
#include "deck.hpp"

using namespace std;

class Game {
private:
    Deck deck;
    House dealer;
    vector<Player> m_Players;
public:
    Game(const vector<string>& names);
    ~Game(){}
    void Play();
};
#endif