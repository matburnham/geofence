#include <cstdint>

#include "pointinpoly.h"

int pointinpoly(const int32_t *poly, int points, int32_t x, int32_t y)
{
  int32_t p0, p1, l0, l1;
  int c = 0;

  /* Read the final point */
  p0 = poly[points * 2 - 2];
  p1 = poly[points * 2 - 1];
  
  for(; points; points--, poly += 2)
  {
    l0 = p0;
    l1 = p1;
    p0 = poly[0];
    p1 = poly[1];

    if(y < p1 && y < l1) continue;
    if(y >= p1 && y >= l1) continue;
    if(x < p0 + (l0 - p0) * (float) (y - p1) / (l1 - p1)) continue;

    c = !c;
  }
  return(c);
}



