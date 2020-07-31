#include "matplotlibcpp.h"
#include "pointinpoly.h"
#include "geofence.h"

namespace plt = matplotlibcpp;

void plot_polygon(const int32_t *poly, int n)
{
  std::vector<double> x(n), y(n);
  for(int i=0; i<n; ++i) {
      y.at(i) = poly[i*2]/10000000.0;
      x.at(i) = poly[i*2+1]/10000000.0;
  }

  plt::plot(x, y);
}

void plot_geofence(const int32_t *poly, int n, double x1, double x2, double y1, double y2)
{
  int32_t int_lat;
  int32_t int_lon;
  int point = 0;
  std::vector<double> x, y, c;

  for (int32_t lat = y1; lat < y2; lat=lat + 0.2) {
    for (int32_t lon = x1; lon < x2; lon=lon + 0.2) {
  	  int_lat = lat * 10000000;
  	  int_lon = lon * 10000000;
      // TODO: not convinced lat/lon are correct here?
      point = pointinpoly(poly, n, int_lat, int_lon);
      
      if (point) {
        y.push_back(lat);
        x.push_back(lon);
      }
    }
  }

  plt::plot(x, y, ".");
}
int main()
{
  plot_geofence(UKgeofence, 10, -15.0, 7.0, 45.0, 65.0);
  plot_polygon(UKgeofence, 10);
  plt::save("out.png");

  return 0;
}
