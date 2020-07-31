#ifndef TESTGEOFENCE_H
#define TESTGEOFENCE_H

#include <cppunit/extensions/HelperMacros.h>

class TestGeofence : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( TestGeofence );
  CPPUNIT_TEST( testPointsInside );
  CPPUNIT_TEST( testPointsOutside );
  CPPUNIT_TEST_SUITE_END();

private:
  void testPoints(char* message, int32_t* list, int points, int expected);

public:
  void setUp();

protected:
  void testPointsInside();
  void testPointsOutside();
};


#endif