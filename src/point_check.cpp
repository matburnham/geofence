#include <cstdint>
#include <cstdio>

#include "geofence.h"
#include "pointinpoly.h"

int main()
{
  for (double lat = 45.0; lat < 65; lat=lat + 0.1) {
    for (double lon = -15.0; lon < 7; lon=lon + 0.1) {
  	  int32_t int_lat = lat * 10000000;
  	  int32_t int_lon = lon * 10000000;
      int point = pointinpoly(UKgeofence, 10, int_lat, int_lon);
      
      if (point) {
        printf("%f", lat);
        printf(", ");
        printf("%f",lon);
        printf(", ");
        printf("\n");
      }
    }
  }


    return 0;
}