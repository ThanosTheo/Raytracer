#pragma once

#include "..\Basic\Vector.h"
#include "..\Basic\Material.h"
#include "..\Basic\Object.h"

class Light : public Object {
private:
	Vector position;
	Material material;
	float diffusePower;
	float specularPower;
public:
	Light();
	Light(Vector position, Material matterial, float diffusePower, float specularPower);

	Vector getPosition() { return position; }
	float getDiffusePower() { return diffusePower; }
	float getSpecularPower() { return specularPower; }
	virtual Material getMaterial() { return material; }
};

