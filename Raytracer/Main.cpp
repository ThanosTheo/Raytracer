#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include "opencv2\opencv.hpp"

// COMPONENT CLASSES
#include "Comonents\Basic\Vector.h"
#include "Comonents\Basic\Ray.h"
#include "Comonents\Basic\Material.h"
#include "Comonents\Basic\Object.h"

#include "Comonents\Objects\Light.h"
#include "Comonents\Objects\Camera.h"
#include "Comonents\Objects\Sphere.h"
#include "Comonents\Objects\Plane.h"

// global cosntants
extern const int IMAGE_HEIGHT;
extern const float ASPECT_RATIO;
extern const int IMAGE_WIDTH;
extern const float VIEWPORT_DISTANCE;
extern const int FOV;
extern const float AMBIENT_LIGHT;
extern const float ACCURACY;

const int IMAGE_WIDTH = 1280;
const int IMAGE_HEIGHT = 720;
const float ASPECT_RATIO = (float)IMAGE_WIDTH / (float)IMAGE_HEIGHT;
const float VIEWPORT_DISTANCE = 1;
const int FOV = 45;
const float AMBIENT_LIGHT = 0.3f;
const double ERROR = 10;

Material getPixelColor(Ray ray, float min, int index, std::vector<Object*> Objects, std::vector<Object*> lightSources) {
	Vector intersectionPoint = ray.getOrigin() + ray.getDirection() * min;
	Vector n = Objects.at(index)->getNormalAt(intersectionPoint);

	Material result = Objects.at(index)->getMaterial() * AMBIENT_LIGHT;



	// Check if object is lit for each light source
	for (auto const& light : lightSources) {
		//create a ray to the light and check if there is an object between the two
		Vector lightDirection = (light->getPosition() - intersectionPoint).normalize();
		Ray lightRay(intersectionPoint, lightDirection);

		bool hit = false;
		for (auto const& obj : Objects) {
			float distance = obj->Intersect(lightRay);
			if (INFINITY > distance && distance > 0.0001) {
				hit = true;
				break;
			}
		}

		if (!hit) {
			// Blinn-Phong
			float nl = Vector::dot(n, lightDirection);

			// clamp nl between 0 and 1
			if (nl > 1.0) {
				nl = 1.0;
			}
			else if (nl < 0.0) {
				nl = 0.0;
			}

			result = result + (Objects.at(index)->getMaterial() * light->getMaterial() * nl);
		}
	}
	Material::clamp(result);
	return result;
}

int main() {
	
	// initialize image
	cv::Mat image(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8UC3, cv::Scalar(0, 0, 0));

	// define the camera
	Vector position(0, 2.1, -10);
	Vector lookAt(0, 0 , 4);
	Camera camera(position, lookAt);

	// Define basic colors;
	Material white(1.0, 1.0, 1.0);

	Material blue(0.07058, 0.76078 , 0.91372);
	Material purple(0.76862, 0.44313, 0.92941);
	Material red(0.96470, 0.30980, 0.34901);
	Material darkBlue(0.17254, 0.32549, 0.39215);
	Material black(0.0, 0.0, 0.0);

	Light light(Vector(-7, 5, 0), white);
	std::vector<Object*> lightSources;
	lightSources.push_back(dynamic_cast<Object*>(&light));

	// Schene Objects
	Sphere sphere1(Vector(-3, 0, 3), 1, blue);
	Sphere sphere2(Vector(0, 0, 4), 1, purple);
	Sphere sphere3(Vector(3, 0, 2), 1, red);
	Plane  plane(Vector(0, -1, 0),Vector(0, 1, 0), darkBlue);

	// Generate a vector of objects for checking Intersections
	std::vector<Object*> Objects;
	Objects.push_back(dynamic_cast<Object*>(&sphere1));
	Objects.push_back(dynamic_cast<Object*>(&sphere2));
	Objects.push_back(dynamic_cast<Object*>(&sphere3));
	Objects.push_back(dynamic_cast<Object*>(&plane));

	// Generate the image
	for (int y = 0; y < IMAGE_HEIGHT; ++y) {
		for (int x = 0; x < IMAGE_WIDTH; ++x) {
			// Initialize Ray;
			Ray ray(camera.getPosition(), Vector(0, 0, 1));
			ray.computeDir(x, y, camera);
			
			// get  pixel of image
			cv::Vec3b& color = image.at<cv::Vec3b>(y, x);

			// find the object that we see in the current pixel.
			float min = INFINITY;
			int index = -1;
			for (int i = 0; i < Objects.size(); i++) {
				float distance = Objects.at(i)->Intersect(ray);
				if (min > distance && index != i) {
					min = distance;
					index = i;
				}
			}

			if (index != -1) {
				// raycast hit
				Material mat = getPixelColor(ray, min, index, Objects, lightSources);

				color[0] = mat.getB() * 255;	// b
				color[1] = mat.getG() * 255;	// g
				color[2] = mat.getR() * 255;	// r
			}
			else
			{
				color[0] = black.getB();	// b
				color[1] = black.getG();	// g
				color[2] = black.getR();	// r
			}
		}
	}

	// Display Result
	cv::namedWindow("Result", cv::WINDOW_AUTOSIZE);
	cv::imshow("Result", image);
	cv::waitKey(0);

	//save image
	/*
	bool result = cv::imwrite("../Results/result4.jpg", image);
	if(result)
		std::cout << "Saved image to file" << std::endl;
	*/

	system("pause");
}
