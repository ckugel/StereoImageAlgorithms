#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <opencv2/opencv.hpp>
#include <opencv2/cudastereo.hpp>

using namespace std;
using namespace cv;

void stereoRectify(Mat& camera1Matrix, Mat& camera2Matrix, Mat& cam1Dist, Mat& cam2Dist, cv::Size imgSize, Mat& Q) {
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

// default system is post-processing
int main() {
    Ptr<cuda::StereoSGM> sgm = cuda::createStereoSGM();

    // TODO: load these from xml file
    Mat camera1Matrix;
    Mat camera2Matrix;
    Mat cam1Dist;
    Mat cam2Dist;
    cv::Size imgSize;

    Mat Q; // disparity to depth matrix

    stereoRectify(camera1Matrix, camera2Matrix, cam1Dist, cam2Dist, imgSize, Q);

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

    time_t t = std::time(nullptr);
    string dt = ctime(&t);

    imwrite("3D-output-" + dt, output);

    //     imagesStill = false;
    // }

    return 0;
}

// real-time processing
void takePhotos() {
    Ptr<cuda::StereoSGM> sgm = cuda::createStereoSGM();
    // TODO: load these from xml file
    Mat camera1Matrix;
    Mat camera2Matrix;
    Mat cam1Dist;
    Mat cam2Dist;
    cv::Size imgSize;

    Mat Q; // disparity to depth matrix

    // stack allocation
    cuda::GpuMat im1;
    cuda::GpuMat im2;
    VideoCapture cap1;
    VideoCapture cap2;
    if (!cap1.isOpened()) {
        std::cout << "can't open camera 1" << std::endl;
    }
    if (!cap2.isOpened()) {
        std::cout << "can't open camera 2" << std::endl;
    }

    stereoRectify(camera1Matrix, camera2Matrix, cam1Dist, cam2Dist, imgSize, Q);
    while (true) {
        // will probably need to be replaced with a Gstreamer call
        // jetson PTSD
        // TODO: Test opening two caps while both cameras are pointed at the same stopwatch to test latency
        cap1.open(0, cv::CAP_ANY);
        cap2.open(1, cv::CAP_ANY);

        cap1.read(im1);
        cap2.read(im2);

        // TODO: record bot position right here

        // generates a disparity matrix from stereo correspondence
        // Basically in each "pixel" spot you now have a disparity value instead
        cuda::GpuMat disparity;
        sgm->compute(im1, im2, disparity);

        cuda::GpuMat xyz;
        reprojectImageTo3D(disparity, xyz, Q, 3);

        time_t t = std::time(nullptr);
        string dt = ctime(&t);
        imwrite("3D-live-output-" + dt, xyz);

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

/*;
 * remove the field from the point cloud using constant known about the field
 * For FRC
*/
void removeFieldFromPC() {

}