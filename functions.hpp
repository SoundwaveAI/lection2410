#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "Planar.hpp"
#include <iostream>
#include <cstddef>

Planar* make(std::istream& is);
Planar* mostleft(Planar** pls, size_t k);
Planar* make(size_t id);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);

#endif

