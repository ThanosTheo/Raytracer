#include "Light.h"

Light::Light(){
	position = Vector();
	material = Material(1.0f, 1.0f, 1.0f);
}

Light::Light(Vector pos, Material mat) {
	position = pos;
	material = mat;
}