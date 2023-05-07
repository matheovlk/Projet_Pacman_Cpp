#pragma once

#include "cell.hpp"

// Wall or empty cell
class NonEatable: public Cell
{
    public:
        NonEatable(bool is_not_wall = true);
};