/* boneCV.cpp
 *
 * Copyright Derek Molloy, School of Electronic Engineering, Dublin City University
 * www.derekmolloy.ie
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that source code redistributions retain this notice.
 *
 * This software is provided AS IS and it comes with no warranties of any type. 
 */

#include<cstdlib>
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    VideoCapture capture(0);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,1920);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
    if(!capture.isOpened()){
	    cerr << "Failed to connect to the camera." << endl;
	    return EXIT_FAILURE;
    }
    Mat frame, edges;
    capture >> frame;
    if(frame.empty()){
		cerr << "Failed to capture an image" << endl;
		return  EXIT_FAILURE;
    }
    cvtColor(frame, edges, CV_BGR2GRAY);
    Canny(edges, edges, 0, 30, 3);
    imwrite("edges.png", edges);
    imwrite("capture.png", frame);
    return EXIT_SUCCESS;
}
