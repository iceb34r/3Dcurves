#include "curves.h"

int main(int argc, char** argv) {

	//std::vector<Curve*> curvesVec;
	std::vector<std::shared_ptr<Curve>> curvesVec;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> curveType_dist(0, 2);
	std::uniform_int_distribution<> amount_dist(10, 20);
	std::uniform_real_distribution<> radius_dist(0, 25);
	std::uniform_real_distribution<> step_dist(0, 10);

	size_t vecSize = amount_dist(gen);
	for (size_t i = 0; i < vecSize; i++) {

		int curveType = curveType_dist(gen);

		if (curveType == 0) {

			//curvesVec.push_back(new Ellipse(radius_dist(gen), radius_dist(gen)));
			curvesVec.push_back(std::make_shared<Ellipse>(radius_dist(gen), radius_dist(gen)));
		}

		if (curveType == 1) {

			//curvesVec.push_back(new Circle(radius_dist(gen)));
			curvesVec.push_back(std::make_shared<Circle>(radius_dist(gen)));
		}

		if (curveType == 2) {

			//curvesVec.push_back(new Helix3D(radius_dist(gen), step_dist(gen)));
			curvesVec.push_back(std::make_shared<Helix3D>(radius_dist(gen), step_dist(gen)));
		}
	}

	for (const std::shared_ptr<Curve>& pCurve : curvesVec) {
		std::cout << typeid(*pCurve).name() << ": coords [x, y, z] [" << pCurve->getPoint3D(M_PI_4).x_ << ", "
			<< pCurve->getPoint3D(M_PI_4).y_ << ", "
			<< pCurve->getPoint3D(M_PI_4).z_ << "] || derivative [x, y, z] ["
			<< pCurve->getFirstDerivative(M_PI_4).x_ << ", "
			<< pCurve->getFirstDerivative(M_PI_4).y_ << ", "
			<< pCurve->getFirstDerivative(M_PI_4).z_ << "] || t = PI/4" << std::endl;
	}

	std::vector<std::shared_ptr<Curve>> circlesVec;

	for (const std::shared_ptr<Curve>& pCurve : curvesVec) {
		if (std::dynamic_pointer_cast<Circle>(pCurve)) { 
			circlesVec.push_back(pCurve);
		}
	}

	std::sort(circlesVec.begin(), circlesVec.end(), compCircles);

	double sumOfRadii = .0;

	for (const std::shared_ptr<Curve>& pCurve : circlesVec) {
		std::cout << typeid(*pCurve).name() << " sorted: coords [x, y, z] [" << pCurve->getPoint3D(M_PI_4).x_ << ", "
			<< pCurve->getPoint3D(M_PI_4).y_ << ", "
			<< pCurve->getPoint3D(M_PI_4).z_ << "]" << std::endl;

		sumOfRadii += pCurve->getPoint3D(M_PI_4).x_;
	}

	std::cout << "Total sum of radii = " << sumOfRadii << std::endl;

	system("PAUSE");
	return 0;
}