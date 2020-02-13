#ifndef _deck_hpp_

#define _deck_hpp_

#include <algorithm>
#include <random>
#include "hand.hpp"
#include "players.hpp" 

using namespace std;

class Deck : public Hand{
private:

public:
    Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& _Hand);
    void AdditionalCards(GenericPlayer& _GP);
    virtual ~Deck();
};
#endif