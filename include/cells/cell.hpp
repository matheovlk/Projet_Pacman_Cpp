#pragma once

#include <iostream>
#include "constants.h"

class Cell
{
    public:

        Cell(){};
        virtual ~Cell() {}

        bool get_pac_can_pass();
        
        Cell_type get_cell_type()
        {
            return cell_type;
        }

    protected:
        bool pac_can_pass = true;
        bool is_drawable = false;
        Cell_type cell_type;

};