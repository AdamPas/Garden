//
// Created by adam on 24.05.20.
//

/*
TODO: 1) Check the classes implementation, play a bit with classes and inheritance
      2) Change properties to HP and stuff
      3) Have plants specializations -> warrior, defender, caretaker
      4) Log stuff in a file
 */

#include "Garden/Plant.hpp"
#include "Garden/Garden.hpp"

using namespace std;

int main(){
    int user_input;
    Garden garden;

    cout << "Welcome to your garden!" << endl;

    // main program menu loop
    while(true) {
        cout << "What would you like to do?\n Check plants [1]\n Add a new plant [2]\n Remove an existing plant [3]\n Exit the garden [0]\n";
        cin >> user_input;

        if (user_input==1) garden.print_garden();
        else if (user_input==2) garden.add_plant();
        else if (user_input==3) garden.remove_plant();
        else break;
    }

    cout << "Bye-bye!";
    return 0;
}