/**
 * @file main.cpp
 * Computer Vision Assignment 3
 * Dr. Abid
 * @author Michael Perez
 */

#include "opencv2/imgproc.hpp"
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "sift.h"

using namespace cv;
using namespace std;

// Global variables
const string image_name = "blocks_L-150x150.png";
Mat image, grayImage, editedImage, labImage, filteredImage;
int key;

/**
 * @function main
 */
int main(int argc, char** argv)
{
	// Display windows
	image = imread(image_name);

	imshow("Image", image);

	if (image.empty())
	{
		cout << "The image could not be read. Exiting Program. ";
		return -1;
	}

	// Main loop
	while (1)
	{
		key = waitKey(10); // Scan for key press every 10 ms

		if (key == '1') // 
		{
			if (image.channels() == 1)
			{
				sift feat(image, 4, 5);

				feat.CreateScaleSpace();
				feat.DoGExtrema();
				feat.FilterDoGExtrema();
				feat.AssignOrientations();

				//feat.display_images(2, 4, 3); // Scale Space, Difference of Gaussians(DoG), DoG Keypoints
			}
			else if (image.channels() == 3)
			{
				cvtColor(image, grayImage, COLOR_BGR2GRAY);
				sift feat(grayImage, 4, 5);

				feat.CreateScaleSpace();
				feat.DoGExtrema();
				feat.FilterDoGExtrema();
				feat.AssignOrientations();
				//feat.display_images(2, 4, 3); // Scale Space, Difference of Gaussians(DoG), DoG Keypoints
			}
		}
	}
	return 0;
}
