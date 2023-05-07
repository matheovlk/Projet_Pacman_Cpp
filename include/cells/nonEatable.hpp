#pragma once

#include "cell.hpp"

class NonEatable: public Cell
{
    public:
        NonEatable(bool is_not_wall = true);
};