/*
*
* Library that contains implementatitons of different curves.
* Each curve must be able to return point and first derivative per parameter t along the curve
* 
*/
#pragma once

#include <vector>

#ifdef CURVESLIBRARY_EXPORTS
#define CURVESLIBRARY_API __declspec(dllexport)
#else
#define CURVESLIBRARY_API __declspec(dllimport)
#endif

//Abstract class that contains declarations of neccessary functions for each type of curve
class CURVESLIBRARY_API Shape {
public:
	virtual std::vector<double> GetPoint(double t) = 0;
	virtual std::vector<double> GetFirstDerivative(double t) = 0;
};

class Circle : public Shape {
private:
	double radius;
public:
	CURVESLIBRARY_API Circle(double radius);
	CURVESLIBRARY_API double GetRadius();
	std::vector<double> GetPoint(double t) override;
	std::vector<double> GetFirstDerivative(double t) override;
	CURVESLIBRARY_API bool operator < (Circle& object);
	CURVESLIBRARY_API bool operator > (Circle& object);
	CURVESLIBRARY_API bool operator != (Circle& object);
	CURVESLIBRARY_API bool operator == (Circle& object);
};

class Ellipse : public Shape {
private:
	double xRadius;
	double yRadius;
public:
	CURVESLIBRARY_API Ellipse(double xRadius, double yRadius);
	std::vector<double> GetPoint(double t) override;
	std::vector<double> GetFirstDerivative(double t) override;
};

class Helix : public Shape {
private:
	double step;
	double radius;
public:
	CURVESLIBRARY_API Helix(double radius, double step);
	std::vector<double> GetPoint(double t) override;
	std::vector<double> GetFirstDerivative(double t) override;
};