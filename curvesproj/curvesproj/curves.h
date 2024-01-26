#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <algorithm>


class Point3D {

public: 
	Point3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

	double x_;
	double y_;
	double z_;
};

//std::ostream& operator<<(std::ostream& os, Point3D& p3d) {
//	return os << "x: [" << p3d.x_ << "] y: [" << p3d.y_ << "] z: [" << p3d.z_ << "]";
//}


class Curve {

public: 
	virtual ~Curve() = default;

	virtual Point3D getPoint3D(double theta) = 0;
	virtual Point3D getFirstDerivative(double theta) = 0;
};


class Ellipse : public Curve {

public:
	Ellipse(double radiusX, double radiusY) : radiusX_(radiusX), radiusY_(radiusY) {
		if (radiusX < 0 || radiusY < 0) { throw std::invalid_argument("radii must be positive"); }
	}

	Point3D getPoint3D(double theta);
	Point3D getFirstDerivative(double theta);

	double radiusX_;
	double radiusY_;

};

class Circle : public Ellipse {

public:
	Circle(double radius) : Ellipse(radius,  radius) {
		if (radius < 0) { throw std::invalid_argument("radius must be positive"); }
	}

};

inline bool compCircles(const std::shared_ptr<Curve>& first, const std::shared_ptr<Curve>& second) {
	return std::dynamic_pointer_cast<Circle>(first)->radiusX_ < std::dynamic_pointer_cast<Circle>(second)->radiusX_;
}

class Helix3D : public Curve {
	
public:
	Helix3D(double radius, double step) : radius_(radius), step_(step) {
		if (radius < 0) { throw std::invalid_argument("radius must be positive"); }
	}

	Point3D getPoint3D(double theta);
	Point3D getFirstDerivative(double theta);

	double radius_;
	double step_;
};
