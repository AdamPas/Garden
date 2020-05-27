//
// Created by adam on 24.05.20.
//

#ifndef GARDEN_GARDEN_HPP
#define GARDEN_GARDEN_HPP

#include "Plant.hpp"
#include <vector>

class Garden {
    vector<Plant> plants;

public:
    void add_plant(void);
    void remove_plant(void);
    void print_garden(void);
};


#endif //GARDEN_GARDEN_HPP
