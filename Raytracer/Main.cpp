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
extern const double AMBIENT_LIGHT;
extern const double ACCURACY;

const int IMAGE_WIDTH = 1280;
const int IMAGE_HEIGHT = 720;
const float ASPECT_RATIO = (float)IMAGE_WIDTH / (float)IMAGE_HEIGHT;
const float VIEWPORT_DISTANCE = 1;
const int FOV = 90;
const double AMBIENT_LIGHT = 0.2;
const double ACCURACY = 0.0000001;

int main() {
	
	// initialize image
	cv::Mat image(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8UC3, cv::Scalar(0, 0, 0));

	// define the camera
	Vector position(0, 1.1, -1);
	Vector lookAt(0, 0 , 4);
	Camera camera(position, lookAt);

	// Define basic colors;
	Material white(255, 255, 255, 0);
	Material green(122, 255, 122, 0.3);
	Material maroon(122, 64, 64, 0);
	Material black(0, 0, 0, 0);
	Material grey;

	Light light(Vector(-7, 10, -10), white);

	// Schene Objects
	Sphere sphere(Vector(0, 0, 4), 1, green);
	Plane  plane(Vector(0, -1, 0),Vector(0, 1, 0), maroon);

	// Generate a vector of objects for checking Intersections
	std::vector<Object*> Objects;
	Objects.push_back(dynamic_cast<Object*>(&sphere));
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
			double min = INFINITY;
			int count = 0, index = -1;
			for (auto const& obj: Objects) {
				double distance = obj->Intersect(ray);
				if (min > distance) {
					min = distance;
					index = count;
				}
				count++;
			}

			if (index != -1) {
				// raycast hit
				Material mat = Objects.at(index)->getMaterial();
				
				color[0] = mat.getB();	// b
				color[1] = mat.getG();	// g
				color[2] = mat.getR();	// r
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
	bool result = cv::imwrite("../Results/result3.jpg", image);
	if(result)
		std::cout << "Saved image to file" << std::endl;
	*/

	system("pause");
}
