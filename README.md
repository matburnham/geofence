# PointInPolygon

Some simple code to determine if a point is in a polygon. Aimed at embedded systems.

Most of the code is unit test wrapping to understand what was going wrong with the original code and to try other ideas out.

![C/C++ CI](https://github.com/matburnham/geofence/workflows/C/C++%20CI/badge.svg)

## Requirements

* CMake
* CPPUNIT
* [matplotlib-cpp](https://github.com/lava/matplotlib-cpp) (via git external)

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Test

```
make test
ctest --force-new-ctest-process -VV
```

## Usage

This is mostly about testing a simple algorithm. It can be used as library as you see fit.

There are two utilities for visualisation

```./plot_test``` Outputs an image visualising the dataset and output from the pointinpoly function.

```./point_check``` Outputs a list of points for processing in Excel

## Acknowledgements

This module was kicked off by a [thread on the UKHAS mailing list](https://groups.google.com/forum/#!topic/ukhas/eZRr05GG18A).
Original code was derived from [Upuaut/APRS_Projects/Pico92](https://github.com/Upuaut/APRS_Projects/tree/master/Pico92)

