#include "Plane.h"

Plane::Plane(){
	point = Vector(0, -1, 0);
	normal = Vector(0, 1, 0);
	material = Material();
}

Plane::Plane(Vector p,Vector norm, Material mat){
	point = p;
	normal = norm;
	material = mat;
}

double Plane::Intersect(Ray ray) {

	double denom = Vector::dot(normal, ray.getDirection());
	
	if (denom < 0) {
		double t = Vector::dot(point - ray.getOrigin(), normal) / denom;

		return t;
	}
	else 
	{
		return INFINITY;
	}
}