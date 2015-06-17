#include "cv.h"
#include "highgui.h"
 
int main(int argc,char** argv)
{
   char path[255];
 
   // For Linux, path to save the captured image
   strcpy(path,"/home/pranay/Desktop/instant.jpg");
 
   // For Windows, path to save the captured image
   // strcpy(path,"c:\\home.jpg");
 
   // Pointer to current frame
   IplImage *frame;
 
   //Resize image to small size 
   IplImage *small;
 
  // Create capture device ready
  // here 0 indicates that we want to use camera at 0th index
   CvCapture *capture = cvCaptureFromCAM(0);
 
   // highgui.h is required
   cvNamedWindow("capture",CV_WINDOW_AUTOSIZE);
 
   frame = cvQueryFrame(capture);
 
   // Must be initialized before actually cvResize is used
   // we are creating image of size that is half of the original frame captured
   // 8 = Bits     3 = Channel 
   small = cvCreateImage(cvSize(frame->width/2,frame->height/2), 8, 3);
 
while(1)
{
   // Query for Frame From Camera
   frame = cvQueryFrame(capture);
 
   // Resize the grabbed frame
 
   cvResize(frame, small);    //cvResize(source, destination)
 
   // Display the captured image
   cvShowImage("capture", small);
 
  char ch =  cvWaitKey(25);  // Wait for 25 ms for user to hit any key
  if(ch==27) break;  // If Escape Key was hit just exit the loop
 
  // Save image if s was keyboard
  if(ch=='s')
  {
     cvSaveImage(path,small);
  }
  }
 
   // Release All Images and Windows
   cvReleaseImage(&frame);
   cvReleaseImage(&small);
   cvDestroyWindow("capture");
    return 0;
}
