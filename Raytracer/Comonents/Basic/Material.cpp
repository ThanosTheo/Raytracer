#include "Material.h"

Material::Material() {
	R = 0.5f;
	G = 0.5f;
	B = 0.5f;
}

Material::Material(double r, double g, double b) {
	R = r;
	G = g;
	B = b;
}

Material Material::operator * (const float& value) {
	return Material(R * value, G * value, B * value);
}

Material Material::operator + (const Material& mat) {
	return Material(R + mat.R, G + mat.G, B + mat.B);
}

Material Material::operator * (const Material& mat) {
	return Material(R * mat.R, G * mat.G, B * mat.B);
}

Material  Material::average(Material mat) {
	return Material((R + mat.R)/2, (G + mat.G) / 2, (B + mat.B) / 2);
}