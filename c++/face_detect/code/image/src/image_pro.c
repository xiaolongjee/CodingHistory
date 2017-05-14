
#include "../include/image_pro.h"

 /*********************************函数定义******************************************/
void detectAndDisplay( Mat frame, Point *location )
{
    Mat frame_gray;

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );   //将RGB图像转换为灰度图像；
    equalizeHist( frame_gray, frame_gray );          //将转换得到的灰度图像进行标准化；

    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0||CV_HAAR_SCALE_IMAGE, Size(30, 30));

	int size = faces.size();
    for( int i = 0; i<size; i++ )
	{
		Point center;
		center.x = int(faces[i].x + faces[i].width *0.5);
		center.y = int(faces[i].y + faces[i].height*0.5);
		location->x = center.x;
		location->y = center.y;
        ellipse( frame, center, Size( int(faces[i].width*0.5), int(faces[i].height*0.5)), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
		
	}
	
	imshow( window_name, frame);
}

//////////////////////////////////////////////////////////////////////////////////////////////

void ImgRate(Mat frame)
 {
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	//图像腐蚀操作；
	erode(frame, frame, element);
	//图像膨胀操作；
	dilate(frame,frame,element);
}


