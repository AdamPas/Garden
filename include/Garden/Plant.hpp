//
// Created by adam on 24.05.20.
//

#ifndef GARDEN_PLANT_HPP
#define GARDEN_PLANT_HPP

#include <iostream>     // std::cout, std::endl
#include <string>
using namespace std;

class Plant {
    string name;
    int age;

public:
    Plant(string n, int a): name(n), age(a){};

    string& get_name(){return name;};
    int& get_age(){return age;};
    void print_plant();
};


#endif //GARDEN_PLANT_HPP
