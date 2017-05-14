
//���궨�塿
//����OpenCV�����⣻
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
//����windows�⣻
#include <windows.h>
//����C++�⣻
#include <iostream>
#include <cstdio>
#include <stdlib.h>

//����ֵ���壻
#define		Error     -1
#define		Ok         0

//ʹ��C++��׼�����ռ䣻 
using namespace std;
//ʹ��CV�����ռ䣻
using namespace cv;

//������������
//���ڼ�ⵥ֡ͼ������������ʾ����¼���ģ�
//

//��ȫ�ֱ���������
//��������ģ��洢·����ע��˴�Ҫʹ�þ���·����
String face_cascade_name = "F:/Master/CV/Code/HumanFace/haarcascade_frontalface_alt2.xml";
//�������������壻
CascadeClassifier face_cascade;
//�������������
String window_name = "�������ٳ���";
Point  face_center;
//�������壻
std::vector<Rect> faces;
RNG rng(12345);


//��main������
int main()
{
  cout<<endl<<endl;
  cout<<"**********����ʶ�����**********"<<endl;
  cout<<"��������������������������������"<<endl;
  cout<<"1.����������"<<endl;
  cout<<"   �����沿������������"<<endl;
  //���ؼ���;
  if( !face_cascade.load(face_cascade_name) )
  { 
	  printf("�沿��������������ʧ�ܣ�\n �����ļ�·�������Ƿ���ȷ��");
	  return Error; 
  }
  cout<<"   ���������سɹ�."<<endl;
  //��ȡ��Ƶ
  cout<<"   ��������ͷ��"<<endl;
  FILE* fp;
  fp = fopen("Data.txt", "w");
  Mat frame;
  //��������ͷ��
  VideoCapture capture(0);
  //������ͷ����ʼ��⣻
  if( capture.isOpened())   
  {
	//��������ͷ�򿪱�־��
	bool flag = true;      
	cout<<"   ����ͷ�����ɹ�."<<endl;
	cout<<"2.�������١�"<<endl;
	cout<<"   ����ʵʱʶ������С�"<<endl;
	cout<<"   ���� Data.txt �Դ洢��Ϣ��"<<endl;
    if(fp == NULL)
	{
	  cout<<"�ļ�����ʧ�ܣ�"<<endl;
	  return Error;
	}
	cout<<"   �����ɹ�."<<endl;
	//���ݴ洢��
    fprintf(fp,"\n  ����ʶ����������¼\n");
    fprintf(fp,"------------------------\n");
    fprintf(fp," ͼ֡��   X����   Y����\n");
	fprintf(fp,"------------------------\n");
	cout<<"   ��������ʵʱ�洢�С�"<<endl;
	cout<<endl<<endl<<"   ����������˳�����"<<endl<<endl;
	

	//��ע���˴����ü���а������£������˳�����
	int count = 0;
    while(flag)
    {
      //������ͷ����֡ͼ���ȡ��frame����;
	  capture >> frame;     
      //���ͼ���ѱ���ȡ�������
      if(!frame.empty())    
       { 
		   //
		   count++;
		   ImgRate(frame); 
		   //ʶ�������������ʾ,ͬʱ�洢�������ꣻ
		   detectAndDisplay(frame,&face_center); 
		   //��ͼ������ת����ʵ�ʿռ����ꣻ
		   //face_center.x = frame.cols - face_center.x;
		   fprintf(fp," %4d      %3d     %3d\n",count,face_center.x,face_center.y);
	  }
      else                 
       { 
		   //��ͼ���ȡʧ���򷵻�ʧ����Ϣ��
		   printf("ͼ���ȡʧ��!");
		   flag = false;
	  }
	  //��10msͨ��whileѭ������ˢ�£�
	  waitKey(10);
	  if(count == 1000)
		break;
    }
  }
  fclose(fp);
  cout<<"   ���ر��˳��������ѱ���."<<endl<<endl;
  cout<<"3.�������."<<endl;
   cout<<"��������������������������������"<<endl;
  system("pause");
  return Ok;
}



}


