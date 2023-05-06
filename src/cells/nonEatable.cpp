#include "nonEatable.hpp"

NonEatable::NonEatable(bool is_not_wall)
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
    