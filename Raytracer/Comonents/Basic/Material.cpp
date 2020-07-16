#include "Material.h"

Material::Material() {
	R = 0.5f;
	G = 0.5f;
	B = 0.5f;
	reflectivity = 0.0f;
}

Material::Material(float r, float g, float b, float refl) {
	R = r;
	G = g;
	B = b;
	reflectivity = refl;
}

Material Material::operator * (const float& value) {
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