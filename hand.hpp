#ifndef _hand_hpp_

#define _hand_hpp_
#include "card.hpp"
#include <vector>

using namespace std;
class Hand{
protected:
    vector <Card*> m_Cards;

public:
    Hand();
    void Clear();
    void Add(Card* pCard);
    int GetTotal() const;
    virtual ~Hand();
};
#endif