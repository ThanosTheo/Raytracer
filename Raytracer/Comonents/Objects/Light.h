#pragma once

#include "..\Basic\Vector.h"
#include "..\Basic\Material.h"
#include "..\Basic\Object.h"

class Light : public Object {
private:
	Vector position;
	Material material;
public:
	Light();
	Light(Vector position, Material matterial);

	Vector getPosition() { return position; }
	virtual Material getMaterial() { return material; }
};

