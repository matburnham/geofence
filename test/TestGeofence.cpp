#include <cppunit/config/SourcePrefix.h>
#include <cstdio>

#include "TestGeofence.h"
#include "geofence.h"
#include "pointinpoly.h"
#include "test_points.h"

CPPUNIT_TEST_SUITE_REGISTRATION( TestGeofence );

void TestGeofence::testPoints(char* message, int32_t list[], int points, int expected)
{
  for(; points; points--)
  {
    int p = points - 1;
    // TODO: x and y do seem to be backwards here
    CPPUNIT_ASSERT_MESSAGE(message, pointinpoly(UKgeofence, 10, list[p*2], list[p*2+1]) == expected);
  }
}

void TestGeofence::testPointsInside()
{
  testPoints("Points expected to be inside were detected outside", inside, 2, 1);
}

void TestGeofence::testPointsOutside()
{
  testPoints("Points expected to be outside were detected inside", outside, 2, 0);
}

void TestGeofence::setUp()
{
}