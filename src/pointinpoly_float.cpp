/*int32_t UKgeofence[10 * 2] =
{
  // Visualisation : https://www.dropbox.com/s/c4avx6i7ppigz35/uk_geofence.kml
  // Source        : http://www.ukho.gov.uk/ProductsandServices/Services/Documents/UK%20Territorial%20Sea%20Limits.pdf
  529089020, 20654300, //Norfolk
  509999290, 16040040, //Calais
  507086340,  9448240, //Lydd
  495252080,-71191410, //Scilly Isles
  535141850,-52185060, //Isle of Man
  543357440,-84704590, //SW NI
  586026110,-76354980, //NW Western Isles
  611432350, -5822750, //Outer Hebredees
  551788680,-10986330, //Newcastle
  529089020, 20654300, //Norfolk
};*/    

/*int32_t int_lat;
int32_t int_lon;
int point = 0;

float lat, lon;*/

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
    //printf("%09i %09i w:%09i y:%09i h:%09i /:%09i %09i %01i\n", x, p0, l0-p0, y-p1, l1-p1, (y - p1) / (l1 - p1), (l0 - p0) * (y - p1) / (l1 - p1), x < p0 + (l0 - p0) * (y - p1) / (l1 - p1));
    if(x < p0 + (l0 - p0) * ((float)(y - p1) / (l1 - p1))) continue;

    c = !c;
  }
  return(c);
}

/*int main()
{
  for (lat = 45.0; lat < 65; lat=lat + 0.1) {
    for (lon = -15.0; lon < 7; lon=lon + 0.1) {
  	  int_lat = lat * 10000000;
  	  int_lon = lon * 10000000;
      point = pointinpoly(UKgeofence, 10, int_lat, int_lon);
      
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
}*/