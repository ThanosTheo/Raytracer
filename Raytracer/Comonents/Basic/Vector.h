#pragma once

#include <cmath>

class Vector
{
private:
	double x, y, z;
public:
	Vector();
	Vector(double a, double b, double c);

	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }

	void operator = (const Vector&);

	Vector operator * (const double);
	Vector operator / (const int);

	Vector operator + (const Vector&);
	Vector operator - (const Vector&);
	Vector operator / (const Vector&);


	// normalize vector
	double magnitude();
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
	static double dot(Vector first, Vector seccond) {
		return (first.x * seccond.x) + (first.y * seccond.y) + (first.z * seccond.z);
	}
};

