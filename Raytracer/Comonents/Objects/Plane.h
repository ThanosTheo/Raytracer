#pragma once

#include "..\Basic\Vector.h"
#include "..\Basic\Material.h"
#include "..\Basic\Ray.h"
#include "..\Basic\Object.h"

class Plane : public Object{
private:
	Vector point;
	Vector normal;
	Material material;
public:
	Plane();
	Plane(Vector point, Vector normal, Material material);

	Vector getPoint() { return point; }
	virtual Vector getNormalAt(Vector point) { return normal; }
	virtual Material getMaterial() { return material; }

	float Intersect(Ray ray);
};

