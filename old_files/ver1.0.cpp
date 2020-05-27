/*
 * This is a simple garden program. It offers a text interface to a garden.
 * Should be extended with plants attributes.
 *
 * Author: adam pasvatis
 * Date: 03/2020
 *
 * */

#include <iostream>     // std::cout, std::endl
#include <string>

using namespace std;

#define GARDEN_SIZE 10

string garden[GARDEN_SIZE];
string user_question = "What would like to do?\n Check a spot [1]\n Plant a new plant [2]\n Remove an existing plant [3]\n Exit the garden [0]\n";

inline int get_input(void);
inline void process_input(int);
inline void check_place(void);
inline void add_plant(void);
inline void remove_plant(void);


int main ()
{
    int user_input;

    // populate garden with empty places
    for (int i; i<GARDEN_SIZE; i++)
        garden[i] = "empty";

    cout << "Welcome to your garden!" << endl;

    do{
        user_input = get_input();
        process_input(user_input);
    }while(user_input!=0);

    return 0;
}


inline int get_input(void){
    /*
     * Gets user input and checks validity
     * */

    int user_input = -1;

    do{
        cout << user_question << endl;
        cin >> user_input;
        switch (user_input){
            case 0:
            case 1:
            case 2:
            case 3:
                break;
            default:
                cout << "?? Command not found! Choose again.\n";
                user_input = -1;
        }
    }while(user_input==-1);

}

inline void process_input(int user_input){
    /*
    * Performs action depending on user input
    * */

    switch (user_input){
        case 0:
            cout << "Bye-bye!\n";
            break;
        case 1:
            check_place();
            break;
        case 2:
            add_plant();
            break;
        case 3:
            remove_plant();
            break;
        default:
            break;
    }

}

inline void check_place(void){
    /*
    * Prints the content of the requested garden place
    * */
    int place;

    do{
        cout << "Which place would you like to check? [1-10]\n";
        cin >> place;
        place--;    // translate to array index

        if(place>GARDEN_SIZE or place<0)
            cout << "The garden only has " << GARDEN_SIZE << " real places!\n";

    }while(place>GARDEN_SIZE or place<0);

    cout << "It's " << garden[place] << endl << endl;
}

inline void add_plant(void){
    /*
    * Adds a plant at the requested garden place
    * */

    int place;
    string plant;

    cout << "Which plant would you like to plant today?\n";
    cout << "Enter plant name: ";
    cin.ignore(256, '\n');
    getline(cin,plant);
    cout << "Excellent choice!\n";

    do{
        cout << "In which place should it be planted? [1-10]\n";
        cin >> place;
        place--;    // translate to array index

        if(place>GARDEN_SIZE or place<0) {
            cout << "The garden only has " << GARDEN_SIZE << " real places!\n";
            continue;
        }

    }while(place>GARDEN_SIZE or place<0);

    if(garden[place]!="empty"){
        cout << "This place already contains the plant: " << garden[place] << endl;
        cout << "You have to dig it out first!\n" << endl;
    }
    else{
        garden[place] = plant;
        cout << "The plant " << plant << " has been planted!\n" << endl << endl;
    }

}

inline void remove_plant(void){
    /*
    * Removes a plant from the requested garden place
    * */

    int place;
    char confirm;

    do{
        cout << "In which place to dig out? [1-10]\n";
        cin >> place;
        place--;    // translate to array index

        if(place>GARDEN_SIZE or place<0)
            cout << "The garden only has " << GARDEN_SIZE << " real places!\n";

    }while(place>GARDEN_SIZE or place<0);

    if(garden[place]=="empty")
        cout << "This place is already empty!\n" << endl;
    else {
        cout << "This place contains the plant: " << garden[place] << endl;
        cout << "Are you sure you want to dig it out? [y/n]\n";
        cin >> confirm;

        if (confirm == 'y') {
            cout << "Digging out plant...\n" << endl;
            garden[place] = "empty";
        } else
            cout << "Aborting operation.\n" << endl;
    }
}