#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void rectifyImages(Mat& imL, Mat& imR) {

}

void stereoSearch(Mat& imL, Mat& imR) {

}

int main() {
    Mat imgLeft = imread("/images/left.jpg", IMREAD_COLOR);
    Mat imgRight = imread("/images/right.jpg", IMREAD_COLOR);

    rectifyImages(imgLeft, imgRight);

    stereoSearch(imgLeft, imgRight);


    return 0;
}
