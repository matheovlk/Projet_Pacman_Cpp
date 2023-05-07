#pragma once

#include "nonEatable.hpp"

class Door: public NonEatable
{
    public:
        Door();

    unsigned int get_counter();

    void increment_counter();

    private:
        unsigned int counter = 0;

};