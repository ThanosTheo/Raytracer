#include "Light.h"

Light::Light(){
	position = Vector();
	material = Material(1.0f, 1.0f, 1.0f);
	diffusePower = 1.0f;
	specularPower = 1.0f;
}

Light::Light(Vector pos, Material mat, float diffPow, float specPow) {
	position = pos;
	material = mat;
	diffusePower = diffPow;
	specularPower = specPow;
}