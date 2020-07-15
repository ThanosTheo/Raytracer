#pragma once

#include "Vector.h"
#include "..\Objects\Camera.h"

class Ray {
private:
	Vector origin, direction;
public:
	Ray();
	Ray(Vector orgn, Vector dir);

	Vector getOrigin() { return origin; }
	Vector getDirection() { return direction; }

	void computeDir(int pixelX,int pixelY, Camera camera);
};

