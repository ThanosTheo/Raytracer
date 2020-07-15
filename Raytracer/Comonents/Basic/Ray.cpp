#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Ray.h"


// include global constants
extern const int IMAGE_HEIGHT;
extern const float ASPECT_RATIO;
extern const int IMAGE_WIDTH;
extern const float VIEWPORT_DISTANCE;
extern const int FOV;

Ray::Ray() {
	origin = Vector();
	direction = Vector(0, 0, 1);
}

Ray::Ray(Vector orgn, Vector dir) {
	origin = orgn;
	direction = dir;
}

void Ray::computeDir(int x, int y, Camera camera) {
	// calculate camera axes
	Vector vn = camera.getUp();
	Vector bn = camera.getRight();
	Vector tn = Vector::cross(vn, bn);

	// calculate pixel shifting vectors
	double gx = (double)VIEWPORT_DISTANCE * tan((FOV / 2) * (M_PI / 180));
	double gy = gx / ASPECT_RATIO;

	Vector qx = bn * (2 * gx) / IMAGE_WIDTH;
	Vector qy = vn * (2 * gy) / IMAGE_HEIGHT;

	// calculate bottom left viewport pixel
	Vector p1m = tn * VIEWPORT_DISTANCE - bn * gx - vn * gy;

	Vector dir = p1m + qx * x + qy * y;
	dir = dir.normalize();

	this->direction = dir;
}