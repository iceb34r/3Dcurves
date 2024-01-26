#include "curves.h"

Point3D Ellipse::getPoint3D(double theta) { return Point3D(radiusX_ * cos(theta),
														   radiusY_ * sin(theta),
														   0); 
}

Point3D Ellipse::getFirstDerivative(double theta) { return Point3D(radiusX_ * -sin(theta),
																   radiusY_ * cos(theta),
																   0);
}

Point3D Helix3D::getPoint3D(double theta) { return Point3D(radius_ * cos(theta),
														   radius_ * sin(theta),
														   ((step_ / M_2_PI) * theta));
}

Point3D Helix3D::getFirstDerivative(double theta) { return Point3D(radius_ * -sin(theta),
																   radius_ * cos(theta),
																   step_ / M_2_PI);
}