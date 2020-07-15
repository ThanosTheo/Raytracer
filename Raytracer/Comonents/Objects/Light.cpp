#include "Light.h"

Light::Light(){
	position = Vector();
	material = Material(255, 255, 255, 0);
}

Light::Light(Vector pos, Material mat) {
	position = pos;
	material = mat;
}