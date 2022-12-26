#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/cudastereo.hpp>

using namespace std;
using namespace cv;

Mat Q; // disparity to depth matrix

void stereoRectify(Mat& camera1Matrix, Mat& camera2Matrix, Mat& cam1Dist, Mat& cam2Dist, cv::Size imgSize) {
    /**
    * Allocated stack space for output of rectify function
    * https://docs.opencv.org/4.x/d9/d0c/group__calib3d.html#ga617b1685d4059c6040827800e72ad2b6
    */
    Mat stereoRotation; // describes the rotation between the two cameras
    Mat stereoTranslation; // describes the translation between the two cameras

    Mat R1; // rotation matrix for cameraCoords rotated into base rotation
    Mat R2; // same thing but fot the other camera

    Mat P1; // 3x4 projection matrix for camera 1
    Mat P2; // 3x4 projection matrix for camera 2

    // we only need Q's output
    stereoRectify(camera1Matrix, cam1Dist, camera2Matrix, cam2Dist, imgSize, stereoRotation, stereoTranslation, R1, R2,
                  P1, P2, Q);
}

int main() {
    Ptr<cuda::StereoSGM> sgm = cuda::createStereoSGM();

    // TODO: load these from xml file
    Mat camera1Matrix;
    Mat camera2Matrix;
    Mat cam1Dist;
    Mat cam2Dist;
    cv::Size imgSize;

    stereoRectify(camera1Matrix, camera2Matrix, cam1Dist, cam2Dist, imgSize);

    // bool imagesStill = true;
    // while (imagesStill) {
    Mat imgLeftCPU = imread("/images/left.jpg", IMREAD_GRAYSCALE);
    Mat imgRightCPU = imread("/images/right.jpg", IMREAD_GRAYSCALE);

    cuda::GpuMat imgLeft;
    imgLeft.upload(imgLeftCPU);

    cuda::GpuMat imgRight;
    imgRight.upload(imgRightCPU);

    cuda::GpuMat disp;
    sgm->compute(imgLeft, imgRight, disp);

    cuda::GpuMat xyz;
    reprojectImageTo3D(disp, xyz, Q, 3);

    Mat output;
    xyz.download(output);

    imshow("Output 3D", output);

    //     imagesStill = false;
    // }

    return 0;
}
