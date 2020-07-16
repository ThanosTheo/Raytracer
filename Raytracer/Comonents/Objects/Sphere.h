#pragma once

#include "..\Basic\Vector.h"
#include "..\Basic\Ray.h"
#include "..\Basic\Material.h"
#include "..\Basic\Object.h"

class Sphere : public Object {
private:
	Vector center;
	float radius;
	Material material;
public:

	Sphere();
	Sphere(Vector position, float radius, Material material = Material());

	Vector getCenter() { return center; }
	float getRadius() { return radius; }
	virtual Material getMaterial() { return material; }

	virtual Vector getNormalAt(Vector point) 
	{ 
		return (point + center.invert()).normalize();
	}

	float Intersect(Ray ray);
};
