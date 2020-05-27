//
// Created by adam on 27.05.20.
//

# include "Garden/Garden.hpp"

void Garden::add_plant(void){
    /*
     * Adds a plant to the garden as user input
     * */

    string name;
    int age;

    cout << "Enter plant name: ";
    cin.ignore(256, '\n');
    getline(cin,name);

    cout << "Enter plant age: ";
    cin >> age;

    this->plants.push_back(Plant(name,age));
    cout << "The plant " << name << " has been planted!\n" << endl << endl;
}

void Garden::remove_plant(void){
    /*
     * Removes a specified plant from the garden
     */

    int index;

    cout << "Enter the index of the plant to be removed: ";
    cin >> index;

    if (index<0 or index >= (this->plants.size()))
        cout << "Index out of bounds!\n";
    else {
        cout << "Removing plant: \n";
        this->plants[index].print_plant();
        this->plants.erase (this->plants.begin()+index);
    }
}

void Garden::print_garden(void){
    /*
     * Prints all the plants in the garden
     */

    if(plants.size()==0){
        cout << "The garden is empty!\n";
    }
    else{
        // Print all plants
        cout << "The garden consists of: \n";
        int i = 1;
        for (vector<Plant>::iterator it = this->plants.begin() ; it != this->plants.end(); ++it){
            cout << i << ". ";
            it->print_plant();
            i++;
        }
        cout << endl;
    }
}