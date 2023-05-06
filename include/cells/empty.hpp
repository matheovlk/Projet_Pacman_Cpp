#pragma once

#include "cell.hpp"

class Empty: public Cell
{
    public:
        Empty(bool is_not_wall = true)
        {
            if (!is_not_wall)
            {
                pac_can_pass = false;
                cell_type = Cell_type::Wall;
            }
            else
            {
                cell_type = Cell_type::Empty;
            }
        };
    
};