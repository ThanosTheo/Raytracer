#pragma once

class Material
{
private:
	double R, G, B, reflectivity;
public:
	Material();
	Material(double r, double g, double b, double reflectivity);

	double getR() { return R; };
	double getG() { return G; };
	double getB() { return B; };
	double getReflectivity() { return reflectivity; };

	double brightness() { return (R + G + B) / 3; }


	// vale operations
	Material operator * ( const double& value);

	// material operations
	Material operator + (const Material& material);
	Material operator * (const Material& material);

	Material average(Material material);


	void setR(double r) { R = r; };
	void setG(double g) { G = g; };
	void setB(double b) { B = b; };
};

