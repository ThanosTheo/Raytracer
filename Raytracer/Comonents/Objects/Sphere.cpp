#include "Sphere.h"

Sphere::Sphere() {
	center = Vector(0, 0, 1);
	radius = 1;
	material = Material();
}

Sphere::Sphere(Vector c, double r, Material mat) {
	center = c;
	radius = r;
	material = mat;
}

double Sphere::Intersect(Ray ray){
	Vector distFromCenter = (ray.getOrigin() - center);

	double a = Vector::dot(ray.getDirection(), ray.getDirection());
	double b = 2.0 * Vector::dot(distFromCenter, ray.getDirection());
	double c = Vector::dot(distFromCenter, distFromCenter) - pow(radius,2);

	double D = pow(b, 2) - 4 * a * c;

	if (D > 0) {
		double t1 = (-b + sqrt(D)) / (2.0 * a);
		double t2 = (-b - sqrt(D)) / (2.0 * a);
		return (t1 < t2) ? t1 : t2;
	}
	else if (D == 0) {
		double min = -b / (2.0 * a);
		return min;
	}
	else {
		return INFINITY;
	}
}