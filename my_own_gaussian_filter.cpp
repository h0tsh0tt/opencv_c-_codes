
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h> 
using namespace cv;
using namespace std;
#define ll int

Mat& gaussianfilter(Mat& M, int row, int column, int sigma_x, int sigma_y){
	int channels = M.channels();
	int rows = M.rows;
	int cols = M.cols;

	int i, j;
	double* p;
	for(int i = 0; i < rows; i++){
		p = M.ptr<double>(i);
		for(int j = 0; j < cols; j++){
			double result = (double)(i*i)/(2*sigma_x*sigma_x) + (double)(j*j)/(2*sigma_y*sigma_y); 
			p[j] = exp(-result);
		}
	}
	return M;
}
int main(int argc, char const *argv[])
{
	int row, column, sigma_y, sigma_x;
	cout << "Enter Row, Column, sigma_x, sigma_y respectively!" << "\n";
	cin >> row >> column >> sigma_x >> sigma_y;
	if(sigma_x == 0)sigma_x=1;
	if(sigma_y == 0)sigma_y=1;
	Mat src, dst;
	src = imread("/home/suryansh/opencv_c++/index.jpeg", CV_LOAD_IMAGE_GRAYSCALE);
	imshow("display_image0", src);
	Mat M;
	M.create(row,column, CV_64F);
	Mat  P = gaussianfilter(M, row, column, sigma_x, sigma_y);
	cout << P << "\n";
	filter2D(src, dst, -1, P, Point(-1,-1), 0, BORDER_DEFAULT);
	imshow("display_image1", dst);
	//now lets compare this with inbuilt opencv function "GaussianBlur"
	
	Mat opencv_dst;
	GaussianBlur(src, opencv_dst, Size(row,column), sigma_x, sigma_y, BORDER_DEFAULT);
	imshow("display_image2", opencv_dst);
	waitKey(0);
	return 0;
}