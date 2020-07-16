#pragma once

#include ".\Vector.h"
#include ".\Ray.h"
#include ".\Material.h"

class Object {
public:
	Object() {};

	virtual float Intersect(Ray r) { return 0; }

	virtual Material getMaterial() { return Material(); }
	virtual Vector getPosition() { return Vector(0,0,0); }
	virtual Vector getNormalAt(Vector point) { return Vector(0,1,0); }
};