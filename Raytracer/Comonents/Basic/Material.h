#pragma once

class Material
{
private:
	double R, G, B;
public:
	Material();
	Material(double r, double g, double b);

	double getR() { return R; };
	double getG() { return G; };
	double getB() { return B; };

	double brightness() { return (R + G + B) / 3; }


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
		double sumLight = mat.R + mat.G + mat.B;
		double excesslight = sumLight - 3;
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

