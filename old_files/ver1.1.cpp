/*
 * This is a simple garden program. It offers a text interface to a garden.
 * Should be extended with plants attributes.
 *
 * Author: adam pasvatis
 * Date: 03/2020
 *
 * */

#include "../headers/ver1.1.h"

using namespace std;

int main ()
{
    int user_input;

    cout << "Welcome to your garden!" << endl;

    // Create a garden with specific amount of places


    while(true){
        cout << "How many places should your garden have?\n";
        cin >> garden_size;
        if (garden_size > 0) break;
        else cout << "Please enter a number above 0!\n";
    }

    garden = new (nothrow) plant[garden_size];
    if(garden== nullptr){
        cout << "Error: No memory allocated!"; return -1;
    }

    // populate garden with empty places
    for (int i=0; i<garden_size; i++){
        garden[i].type = "no type";
        garden[i].name = "nameless";
        garden[i].age = 0;
    }

    // main program menu loop
    do{
        user_input = get_input();
        process_input(user_input);
    }while(user_input!=0);

    delete[] garden;
    return 0;
}


int get_input(void){
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

void process_input(int user_input){
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

void check_place(void){
    /*
    * Prints the content of the requested garden place
    * */
    int place;

    do{
        cout << "Which place would you like to check? [1-" <<  garden_size << "]\n" ;
        cin >> place;
        place--;    // translate to array index

        if(place>=garden_size or place<0)
            cout << "The garden only has " << garden_size << " real places!\n";

    }while(place>=garden_size or place<0);

    cout << "It's \n";
    print_plant(place);
}

void add_plant(void){
    /*
    * Adds a plant at the requested garden place
    * */

    int place;
    string input;

    do{
        cout << "In which place should it be planted? [1-" <<  garden_size << "]\n" ;
        cin >> place;
        place--;    // translate to array index

        if(place>=garden_size or place<0) {
            cout << "The garden only has " << garden_size << " real places!\n";
            continue;
        }

    }while(place>=garden_size or place<0);

    if(garden[place].name!="nameless"){
        cout << "This place already contains the plant: " << garden[place].name << endl;
        cout << "You have to dig it out first!\n" << endl;
    }
    else{
        cout << "Info of the plant?\n";
        cout << "Enter plant name: ";
        cin.ignore(256, '\n');
        getline(cin,garden[place].name);
        cout << "Enter plant type: ";
        //cin.ignore(256, '\n');
        getline(cin,garden[place].type);
        cout << "Enter plant age: ";
        cin >> garden[place].age;

        cout << "The plant " << garden[place].name << " has been planted!\n" << endl << endl;
    }
}

void remove_plant(void){
    /*
    * Removes a plant from the requested garden place
    * */

    int place;
    char confirm;

    do{
        cout << "In which place to dig out? [1-" <<  garden_size << "]\n" ;
        cin >> place;
        place--;    // translate to array index

        if(place>=garden_size or place<0)
            cout << "The garden only has " << garden_size << " real places!\n";

    }while(place>=garden_size or place<0);

    if(garden[place].name=="nameless")
        cout << "This place is already empty!\n" << endl;
    else {
        cout << "This place contains the plant: " << garden[place].name << endl;
        cout << "Are you sure you want to dig it out? [y/n]\n";
        cin >> confirm;

        if (confirm == 'y') {
            cout << "Digging out plant...\n" << endl;
            garden[place].type = "no type";
            garden[place].name = "nameless";
            garden[place].age = 0;
        } else
            cout << "Aborting operation.\n" << endl;
    }
}

void print_plant(int i){
    /*
     * Prints info about a plant
     * */
    cout << " Type: " << garden[i].type << endl;
    cout << " Name: " << garden[i].name << endl;
    cout << " Age: " << garden[i].age << endl;
}

