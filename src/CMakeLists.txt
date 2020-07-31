include_directories(${PYTHONHOME}/include)
include_directories(/usr/include/python3.8/) # TODO: FIXME
include_directories(${PYTHONHOME}/Lib/site-packages/numpy/core/include)
link_directories(${PYTHONHOME}/libs)

add_definitions(-DMATPLOTLIBCPP_PYTHON_HEADER=Python.h)

if((NOT MATPLOTLIBCPP_INCLUDE_DIR) OR (NOT EXISTS ${MATPLOTLIBCPP_INCLUDE_DIR}))
    # we couldn't find the header files for MATPLOTLIBCPP or they don't exist
    message("Unable to find matplotlib-cpp")

    # we have a submodule setup for matplotlib-cpp, assume it is under external/matplotlib-cpp
    # now we need to clone this submodule
    execute_process(COMMAND git submodule update --init -- external/matplotlib-cpp
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    # set MATPLOTLIBCPP_INCLUDE_DIR properly
    set(MATPLOTLIBCPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/matplotlib-cpp
        CACHE PATH "matplotlib-cpp include directory")

    # also install it
    #install(DIRECTORY ${MATPLOTLIBCPP_INCLUDE_DIR} DESTINATION ${some_dest})

    # for convenience setup a target
    #add_library(matplotlib-cpp INTERFACE)
    #target_include_directories(matplotlib-cpp INTERFACE
    #                           $<BUILD_INTERFACE:${MATPLOTLIBCPP_INCLUDE_DIR}>
    #                           $<INSTALL_INTERFACE:${some_dest}>)

    # need to export target as well
    install(TARGETS matplotlib-cpp EXPORT my_export_set DESTINATION ${some_dest})
else()
    # see above, setup target as well
endif()

# Include matplotlib-cpp header-only library
find_path(MATPLOTLIBCPP_INCLUDE_DIR matplotlibcpp.h)

add_executable(point_check ${CMAKE_CURRENT_SOURCE_DIR}/point_check.cpp)
add_executable(plot_points ${CMAKE_CURRENT_SOURCE_DIR}/plot_points.cpp)

target_include_directories(plot_points PUBLIC ${MATPLOTLIBCPP_INCLUDE_DIR} ${GEOFENCE_INCLUDE_DIR})
find_package(Python3 COMPONENTS Development NumPy)
target_include_directories(plot_points PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(plot_points Python3::Python Python3::NumPy PointInPoly)

target_include_directories(point_check PUBLIC ${GEOFENCE_INCLUDE_DIR})
target_link_libraries(point_check PUBLIC PointInPoly)
