#pragma once

#include <iostream>
#include "constants.hpp"

class Cell
{
    public:

        Cell(){};

        // virtual constructor for polymorphism
        virtual ~Cell() {}

        bool get_pac_can_pass();
        
        Cell_type get_cell_type();

    protected:
        bool pac_can_pass = true;
        bool is_drawable = false;
        Cell_type cell_type;

};