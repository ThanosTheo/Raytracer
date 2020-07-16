#pragma once

class Material
{
private:
	float R, G, B, reflectivity;
public:
	Material();
	Material(float r, float g, float b, float reflectivity = 0.0f);

	float getR() { return R; };
	float getG() { return G; };
	float getB() { return B; };
	float getReflectivity() { return reflectivity; };

	float brightness() { return (R + G + B) / 3; }


	// vale operations
	Material operator * ( const float& value);

	// material operations
	Material operator + (const Material& material);
	Material operator * (const Material& material);

	Material average(Material material);


	void setR(float r) { R = r; };
	void setG(float g) { G = g; };
	void setB(float b) { B = b; };

	static void clamp(Material &mat) {
		float sumLight = mat.R + mat.G + mat.B;
		float excesslight = sumLight - 3;
		if (excesslight > 0) {
			mat.R = mat.R + excesslight * (mat.R / sumLight);
			mat.G = mat.G + excesslight * (mat.G / sumLight);
			mat.B = mat.B + excesslight * (mat.B / sumLight);
		}

		mat.R = mat.R > 1 ? 1.0f : mat.R;
		mat.G = mat.G > 1 ? 1.0f : mat.G;
		mat.B = mat.B > 1 ? 1.0f : mat.B;
	}
};

