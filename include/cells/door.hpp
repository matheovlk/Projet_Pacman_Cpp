#pragma once

#include "nonEatable.hpp"

class Door: public NonEatable
{
    public:
        Door(){
            pac_can_pass = false;
            cell_type = Cell_type::Door;
        };

    unsigned int get_counter(){
        return counter;
    }

    void increment_counter()
    {
        counter++;
    }

    private:
        unsigned int counter = 0;

};