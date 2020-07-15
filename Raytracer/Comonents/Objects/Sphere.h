#pragma once

#include "..\Basic\Vector.h"
#include "..\Basic\Ray.h"
#include "..\Basic\Material.h"
#include "..\Basic\Object.h"

class Sphere : public Object {
private:
	Vector center;
	double radius;
	Material material;
public:

	Sphere();
	Sphere(Vector position, double radius, Material material = Material());

	Vector getCenter() { return center; }
	double getRadius() { return radius; }
	virtual Material getMaterial() { return material; }

	Vector getNormal(Vector point) 
	{ 
		return (point + center.invert()).normalize();
	}

	double Intersect(Ray ray);
};
