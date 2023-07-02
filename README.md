﻿# CurvesExample
 The program implements 3 types of 3D curves:
 * Circle (Planar and Z always equals 0);
 * Ellipse (Also planar);
 * Helix.
# CurvesLibrary
All curves are described in the dll called CurvesLibrary.
Every curve is inherited from abstract Shape class and implements methods for returning the point and the first derivative (depends on t).
# Main function
The program generates a random integer number and uses it to define the length of a container of random shapes with random parameters.
Then it prints coordinates of points and derivatives of all curves in the container with t = PI/4.
Creates another container for only circles and fills it with pointers to circles from the previous container,
sort this container by radii in ascending order and then calculate the sum of radii from the container using OpenMP parallel computations.
