#include "Vector.h"

Vector::Vector() { x = 0; y = 0; z = 0; }

Vector::Vector(double a, double b, double c) {
	x = a;
	y = b;
	z = c;
}

void Vector::operator = (const Vector& other) {
	x = other.x;
	y = other.y;
	z = other.z;
}


// Vector-Value Operations
Vector Vector::operator * (const double value) {
	return Vector(x * value, y * value, z * value);
}

Vector Vector::operator / (const int value) {
	return Vector(x / value, y / value, z / value);
}

// Vector Operations

Vector Vector::operator + (const Vector& other) {
	return Vector((x + other.x), (y + other.y), (z + other.z));
}

Vector Vector::operator - (const Vector& other) {
	return Vector((x - other.x), (y - other.y), (z - other.z));
}

Vector Vector::operator / (const Vector& other) {
	return Vector((x / other.x), (y / other.y), (z / other.z));
}

double Vector::magnitude() {
	return sqrt((x * x) + (y * y) + (z * z));
}

Vector Vector::normalize() {
	double mag = this->magnitude();
	return Vector(x / mag, y / mag, z / mag);
}


Vector Vector::invert() {
	return Vector(-x, -y, -z);
}