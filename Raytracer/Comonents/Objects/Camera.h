#pragma once

#include "..\Basic\Vector.h"

class Camera
{
private:
	Vector position, direction, up, right;
public:
	Camera();

	Camera(Vector position, Vector lookAt);

	Vector getPosition() { return position; }
	Vector getDirection() { return position; }
	Vector getUp() { return up; }
	Vector getRight() { return right; }

	void setPosition(Vector position);
	void setDirection(Vector direction);

};

