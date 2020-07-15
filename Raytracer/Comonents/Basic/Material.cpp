#include "Material.h"

Material::Material() {
	R = 122;
	G = 122;
	B = 122;
	reflectivity = 0;
}

Material::Material(double r, double g, double b, double refl) {
	R = r;
	G = g;
	B = b;
	reflectivity = refl;
}

Material Material::operator * (const double& value) {
	return Material(R * value, G * value, B * value, reflectivity);
}

Material Material::operator + (const Material& mat) {
	return Material(R + mat.R, G + mat.G, B + mat.B, reflectivity);
}

Material Material::operator * (const Material& mat) {
	return Material(R * mat.R, G * mat.G, B * mat.B, reflectivity);
}

Material  Material::average(Material mat) {
	return Material((R + mat.R)/2, (G + mat.G) / 2, (B + mat.B) / 2, reflectivity);
}