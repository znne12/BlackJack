#ifndef _players_hpp_

#define _players_hpp_
#include "hand.hpp"
#include <string>
#include <iostream>

using namespace std;

class GenericPlayer : public Hand {
protected:
    string name;
public: 
    GenericPlayer(string _name) : name(_name){}
    GenericPlayer() {}
    virtual bool IsHitting() const = 0;    
    bool IsBoosted() const;
    void Bust() const;
    friend ostream& operator<< (ostream& out, GenericPlayer &gp);
    virtual ~GenericPlayer() {}
 
};
class Player : public GenericPlayer {
    public:
    Player(string _name) : GenericPlayer(_name){}
    bool IsHitting() const override;
    void Win() const;
    void Lose() const;
    void Push() const;
    virtual ~Player() {}
};
class House : public GenericPlayer {
    private:

    public:
    House();
    bool IsHitting() const override;
    void FlipFirstCard();
    virtual ~House() {}
};
#endif