#include "Sphere.h"

Sphere::Sphere() {
	center = Vector(0, 0, 1);
	radius = 1;
	material = Material();
}

Sphere::Sphere(Vector c, float r, Material mat) {
	center = c;
	radius = r;
	material = mat;
}

float Sphere::Intersect(Ray ray){
	Vector distFromCenter = (ray.getOrigin() - center);

	float a = Vector::dot(ray.getDirection(), ray.getDirection());
	float b = 2.0 * Vector::dot(distFromCenter, ray.getDirection());
	float c = Vector::dot(distFromCenter, distFromCenter) - pow(radius,2);

	float D = pow(b, 2) - 4 * a * c;

	if (D > 0) {
		float t1 = ((float)(-b) + sqrt(D)) / (2.0f * a);
		float t2 = ((float)(-b) - sqrt(D)) / (2.0f * a);
		return (t1 < t2) ? t1 : t2;
	}
	else if (D == 0) {
		float min = -b / (2.0f * a);
		return min;
	}
	else {
		return INFINITY;
	}
}