#include "card.hpp"
#include <iostream>

using namespace std;

void Card :: Flip() {
        if (cardPos == true) cardPos = false;
        else cardPos = true;
    }
ostream& operator<< (ostream& out, Card &card){
    if (!card.cardPos) {
        switch(card.num){
            case Card :: Ace : out << " Ace of";break;
            case Card :: Two : out << " Two of";break;
            case Card :: Three : out << " Three of";break;
            case Card :: Four : out << " Four of";break;
            case Card :: Fife : out << " Fife of";break;
            case Card :: Six : out << " Six of";break;
            case Card :: Seven : out << " Seven of";break;
            case Card :: Eight : out << " Eight of";break;
            case Card :: Nine : out << " Nine of";break;
            case Card :: Ten : out << " Ten of";break;
            case Card :: Jack : out << " Jack of";break;
            case Card :: Queen : out << " Queen of";break;
            case Card :: King : out << " King of";break; 
        }
        switch(card.suit){
            case  Card :: Hearts : out << " Hearts";break;
            case  Card :: Diamonds :  out << " Diamonds";break;
            case  Card :: Clubs :  out << " Clubs";break;
            case  Card :: Spades :  out << " Spades";break;
        } 
        } else out << "xx";
         return out;
    }
    int Card :: GetValue() const{
        if (!cardPos) {
            if (num >= Ace && num <= Ten) return num;
            else return 10;
        }
        else return 0;
    }