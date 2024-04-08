#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "base-types.hpp"

namespace suppFunctions
{
  point_t findSummVector(point_t point, double dx, double dy);
  point_t findDifference(point_t position, point_t rect);
  point_t makeScale(point_t point, point_t center, double k);
}

#endif
