#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(){
    //Read image to dilate
    Mat image = imread("../assets/dilation.png");
    
    //Create a structuring element/kernel
    int dilationSize = 6;
    Mat element = getStructuringElement(MORPH_CROSS, Size(2*dilationSize + 1, 2*dilationSize + 1), Point(dilationSize, dilationSize));

    Mat dilatedImage;

    //Apply dilate function on input image. Dilation will increase brightness, First Parameter is the original image, 
    //second is the dilated image
    dilate(image, dilatedImage, element);

    //create windows to show image
    namedWindow("input image", WINDOW_NORMAL);
    namedWindow("dilated image", WINDOW_NORMAL);

    //Display input and dilated image
    imshow("input image", image);
    imshow("dilated image", dilatedImage);

    //Press esc on keyboard to exit the program
    waitKey(0);

    //Close all the opened windows
    destroyAllWindows();

    return 0;
}