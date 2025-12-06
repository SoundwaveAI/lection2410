#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "Planar.hpp"
#include <iostream>
#include <cstddef>

struct PlanarPair
{
  Planar* fir;
  Planar* sec;
};

Planar* make(std::istream& is);
Planar** mostleft(Planar** pls, size_t k);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);
Planar* max_area(Planar** pls, size_t k);
Planar max_frame_sects(Planar** pls, size_t k);

#endif

