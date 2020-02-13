#include <iostream>
#include <vector>
#include <string>
#include "card.hpp"
#include "hand.hpp"
#include "players.hpp"
#include "deck.hpp"
#include "game.hpp"


using namespace std;

int main(){
     cout << "Welcome to Blackjack!\n" << endl;       
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;
    
    Game game(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        game.Play();
        cout << endl;
        cout << "Do you want to play again? (Y/N): ";
        cin >> again;
    } 


    return 0;
}