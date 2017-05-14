
#include "../include/image_pro.h"

 /*********************************��������******************************************/
void detectAndDisplay( Mat frame, Point *location )
{
    Mat frame_gray;

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );   //��RGBͼ��ת��Ϊ�Ҷ�ͼ��
    equalizeHist( frame_gray, frame_gray );          //��ת���õ��ĻҶ�ͼ����б�׼����

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
	//ͼ��ʴ������
	erode(frame, frame, element);
	//ͼ�����Ͳ�����
	dilate(frame,frame,element);
}


