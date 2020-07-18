#pragma once

#include <cmath>

class Vector
{
private:
	float x, y, z;
public:
	Vector();
	Vector(float a, float b, float c);

	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }

	void operator = (const Vector&);

	Vector operator * (const float);
	Vector operator / (const int);

	Vector operator + (const Vector&);
	Vector operator - (const Vector&);
	Vector operator * (const Vector&);
	Vector operator / (const Vector&);


	// normalize vector
	float magnitude();
	Vector normalize();

	// invert vector
	Vector invert();

	// cross
	static Vector cross(Vector first, Vector seccond) {
		Vector result;
		result.x = first.y * seccond.z - first.z * seccond.y;
		result.y = first.x * seccond.z - first.z * seccond.x;
		result.z = first.x * seccond.y - first.y * seccond.x;

		return result;
	}

	// dot product
	static float dot(Vector first, Vector seccond) {
		return (first.x * seccond.x) + (first.y * seccond.y) + (first.z * seccond.z);
	}
};

