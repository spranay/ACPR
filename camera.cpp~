#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    char path[255];

    Mat img;

    // For Linux, path to save the captured image
   strcpy(path,"/home/pranay/Desktop/image.jpg");

    VideoCapture cap(0); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
    cout  << "Cannot open the video file" << endl;
        return -1;
    }

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the  video
    cout << "Frame size : " << dWidth << " x " << dHeight << endl;
    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
    while (1)
    {
       Mat frame;
       bool bSuccess = cap.read(frame); // read a new frame from video
       if (!bSuccess) //if not success, break loop
        {
         cout << "Cannot read a frame from video file" << endl;
            break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window
        
        char ch =  waitKey(25);
         // Save image if s was keyboard
        if(ch=='s')
      {
         imwrite(path,frame);
      }

        if (ch == 27) 
        {
        //cout << "esc key is pressed by user" << endl;
          break; 
        }
    }
    return 0;

}

