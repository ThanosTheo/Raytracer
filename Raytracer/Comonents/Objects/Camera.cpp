#include "Camera.h"

Camera::Camera(){
	Vector position = Vector(0, 0, 0);
	Vector direction = Vector(0, 0, 1);
	Vector up = Vector(0, 1, 0);
	Vector right = Vector(1, 0, 0);
}

Camera::Camera(Vector pos, Vector lookAt) {
	position = pos;

	Vector difference = (position - lookAt);
	direction = difference.invert().normalize();
	right = Vector::cross(Vector(0, 1, 0), direction).normalize();
	up = Vector::cross(right, direction).invert();
}

void Camera::setPosition(Vector pos){
	this->position = pos;
}

void Camera::setDirection(Vector dir) {
	this->direction = dir;
}