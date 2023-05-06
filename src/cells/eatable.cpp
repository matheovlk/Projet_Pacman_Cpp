#include "eatable.hpp"

void Eatable::restart()
{
    eaten = false;
}

void Eatable::set_eaten()
{
    eaten = true;
}