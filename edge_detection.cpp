
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "bits/stdc++.h"

using namespace cv;
using namespace std;

Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

int CannyThreshold(int, void*){
	blur(src_gray, detected_edges, Size(3,3));
	Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
	dst = Scalar::all(0);
	src.copyTo(	dst, detected_edges);
  	imshow( "2", dst );
  	imshow( "1", detected_edges );
}

int main(int argc, char const *argv[])
{
	src = imread("/home/suryansh/Pictures/1522538.jpg");

	dst.create(src.size(), src.type());

	cvtColor(src, src_gray, CV_BGR2GRAY);

	namedWindow("edge_detection", CV_WINDOW_AUTOSIZE);

	CannyThreshold(0, 0);

	waitKey(0);
	return 0;
}