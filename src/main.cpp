#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void rectifyImages(Mat& imL, Mat& imR) {

}

void stereoSearch(Mat& imL, Mat& imR) {

}

int main() {
    Mat imgLeftCPU = imread("/images/left.jpg", IMREAD_GRAYSCALE);
    Mat imgRightCPU = imread("/images/right.jpg", IMREAD_GRAYSCALE);

    cuda::GpuMat imgLeft;
    imgLeft.upload(imgLeftCPU);

    cuda::GpuMat imgRight;
    imgRight.upload(imgRightCPU);

    rectifyImages(imgLeft, imgRight);

    stereoSearch(imgLeft, imgRight);


    return 0;
}
