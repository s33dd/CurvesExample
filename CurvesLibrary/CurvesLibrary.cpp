#include "pch.h"
#include <math.h>
#include <string>

Circle::Circle(double radius) {
	if (radius < 0) {
		throw std::string("Radius is negative");
	}
	this->radius = radius;
}

std::vector<double> Circle::GetPoint(double t) {
	std::vector<double> point;
	point.push_back(radius * cos(t));
	point.push_back(radius * sin(t));
	point.push_back(0); //Circle is planar so z = 0
	return point;
}

std::vector<double> Circle::GetFirstDerivative(double t) {
	std::vector<double> derivative;
	derivative.push_back(-radius * sin(t));
	derivative.push_back(radius * cos(t));
	derivative.push_back(0); //Circle is planar so z = 0
	return derivative;
}

Ellipse::Ellipse(double xRadius, double yRadius) {
	if (xRadius < 0 or yRadius < 0) {
		throw std::string("Some of radii of ellipse is negative");
	}
	this->xRadius = xRadius;
	this->yRadius = yRadius;
}

std::vector<double> Ellipse::GetPoint(double t) {
	std::vector<double> point;
	point.push_back(xRadius * cos(t));
	point.push_back(yRadius * sin(t));
	point.push_back(0); //Ellipse is planar so z = 0
	return point;
}

std::vector<double> Ellipse::GetFirstDerivative(double t) {
	std::vector<double> derivative;
	derivative.push_back(-xRadius * sin(t));
	derivative.push_back(yRadius * cos(t));
	derivative.push_back(0); //Ellipse is planar so z = 0
	return derivative;
}

Helix::Helix(double radius, double step) {
	if (radius < 0) {
		throw std::string("Radius is negative");
	}
	if (step < 0) {
		throw std::string("Step is negative");
	}
	this->radius = radius;
	this->step = step;
}

std::vector<double> Helix::GetPoint(double t) {
	std::vector<double> point;
	point.push_back(radius * cos(t));
	point.push_back(radius * sin(t));
	point.push_back(step * t);
	return point;
}

std::vector<double> Helix::GetFirstDerivative(double t) {
	std::vector<double> derivative;
	derivative.push_back(-radius * sin(t));
	derivative.push_back(radius * cos(t));
	derivative.push_back(step);
	return derivative;
}