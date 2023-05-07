#include "door.hpp"

Door::Door()
{
    this->pac_can_pass = false;
    this->cell_type = Cell_type::Door;
}

unsigned int Door::get_counter()
{
    return this->counter;
}

void Door::increment_counter()
{
    this->counter++;
}