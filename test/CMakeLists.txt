# Add catch as an interface library
set(GEOFENCE_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib)
#add_library(Catch INTERFACE)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")
FIND_PACKAGE(CPPUNIT REQUIRED)

FILE(GLOB UnitTests_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "Test*.cpp" )
ADD_EXECUTABLE(UnitTester test_runner.cpp ${UnitTests_SRCS})
FOREACH(test ${UnitTests_SRCS})
        GET_FILENAME_COMPONENT(TestName ${test} NAME_WE)
        ADD_TEST(${TestName} UnitTester ${TestName})
ENDFOREACH(test)

target_include_directories(UnitTester PUBLIC ${GEOFENCE_INCLUDE_DIR})

#add_library(PointInPoly pointinpoly.cpp)

# Add test executable
#add_executable (tests testmain.cpp testA.cpp testB.cpp)
#target_link_libraries(tests Catch CommonSourceCode)
target_link_libraries(UnitTester cppunit PointInPoly)