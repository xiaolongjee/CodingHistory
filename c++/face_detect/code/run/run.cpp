
//【宏定义】
//加载OpenCV函数库；
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
//加载windows库；
#include <windows.h>
//加载C++库；
#include <iostream>
#include <cstdio>
#include <stdlib.h>

//返回值定义；
#define		Error     -1
#define		Ok         0

//使用C++标准命名空间； 
using namespace std;
//使用CV命名空间；
using namespace cv;

//【函数声明】
//用于检测单帧图像中人脸并显示、记录中心；
//

//【全局变量声明】
//脸部特征模板存储路径，注意此处要使用绝对路径；
String face_cascade_name = "F:/Master/CV/Code/HumanFace/haarcascade_frontalface_alt2.xml";
//脸部分类器定义；
CascadeClassifier face_cascade;
//输出窗口命名；
String window_name = "人脸跟踪程序";
Point  face_center;
//容器定义；
std::vector<Rect> faces;
RNG rng(12345);


//【main函数】
int main()
{
  cout<<endl<<endl;
  cout<<"**********人脸识别程序**********"<<endl;
  cout<<"————————————————"<<endl;
  cout<<"1.程序启动…"<<endl;
  cout<<"   加载面部特征分类器…"<<endl;
  //加载级联;
  if( !face_cascade.load(face_cascade_name) )
  { 
	  printf("面部特征分类器加载失败！\n 请检测文件路径配置是否正确！");
	  return Error; 
  }
  cout<<"   分类器加载成功."<<endl;
  //读取视频
  cout<<"   开启摄像头…"<<endl;
  FILE* fp;
  fp = fopen("Data.txt", "w");
  Mat frame;
  //启用摄像头；
  VideoCapture capture(0);
  //若摄像头打开则开始检测；
  if( capture.isOpened())   
  {
	//设置摄像头打开标志；
	bool flag = true;      
	cout<<"   摄像头开启成功."<<endl;
	cout<<"2.人脸跟踪…"<<endl;
	cout<<"   人脸实时识别跟踪中…"<<endl;
	cout<<"   建立 Data.txt 以存储信息…"<<endl;
    if(fp == NULL)
	{
	  cout<<"文件创建失败！"<<endl;
	  return Error;
	}
	cout<<"   创建成功."<<endl;
	//数据存储；
    fprintf(fp,"\n  人脸识别跟踪坐标记录\n");
    fprintf(fp,"------------------------\n");
    fprintf(fp," 图帧数   X坐标   Y坐标\n");
	fprintf(fp,"------------------------\n");
	cout<<"   中心坐标实时存储中…"<<endl;
	cout<<endl<<endl<<"   按任意键可退出程序…"<<endl<<endl;
	

	//备注：此处设置检测有按键按下，用来退出程序！
	int count = 0;
    while(flag)
    {
      //将摄像头拍摄帧图像读取到frame变量;
	  capture >> frame;     
      //检测图像已被读取的情况；
      if(!frame.empty())    
       { 
		   //
		   count++;
		   ImgRate(frame); 
		   //识别人脸并标记显示,同时存储中心坐标；
		   detectAndDisplay(frame,&face_center); 
		   //将图像坐标转化到实际空间坐标；
		   //face_center.x = frame.cols - face_center.x;
		   fprintf(fp," %4d      %3d     %3d\n",count,face_center.x,face_center.y);
	  }
      else                 
       { 
		   //若图像读取失败则返回失败信息；
		   printf("图像读取失败!");
		   flag = false;
	  }
	  //等10ms通过while循环进行刷新；
	  waitKey(10);
	  if(count == 1000)
		break;
    }
  }
  fclose(fp);
  cout<<"   您关闭了程序，数据已保存."<<endl<<endl;
  cout<<"3.程序结束."<<endl;
   cout<<"————————————————"<<endl;
  system("pause");
  return Ok;
}



}


