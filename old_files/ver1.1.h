//
// Created by adam on 26.03.20.
//

#include <iostream>     // std::cout, std::endl
#include <string>
using namespace std;

#ifndef GARDEN_VER1_1_H
#define GARDEN_VER1_1_H


typedef struct {           // a plant as struct
    string type;
    string name;
    int age;
} plant;

string user_question = "What would you like to do?\n Check a spot [1]\n Plant a new plant [2]\n Remove an existing plant [3]\n Exit the garden [0]\n";
plant *garden;           // the garden as an array of plants
int garden_size;        // the garden size as input from the user

inline int get_input(void);
inline void process_input(int);
inline void check_place(void);
inline void add_plant(void);
inline void remove_plant(void);
void print_plant(int);

#endif //GARDEN_VER1_1_H
