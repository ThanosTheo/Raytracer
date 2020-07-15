#pragma once

#include ".\Vector.h"
#include ".\Ray.h"
#include ".\Material.h"

class Object {
public:
	Object() {};

	virtual double Intersect(Ray r) { return 0; }

	virtual Material getMaterial() { return Material(); }
};