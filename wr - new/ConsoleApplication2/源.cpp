//头文件
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp> //含有定义filter2D的头文件
#include "iostream"
#include "wr.h"
#include <io.h>
#include <string>
#include<stdlib.h>
#include<vector>
#include <fstream>
#include "wr.h"
#include <sstream>
#include <set>
#include <time.h>


using namespace cv;
using namespace std;

#define fc "87_front_center.jpg"
#define fl "87_front_left.jpg"
#define fr "87_front_right.jpg"
#define bc "87_back_center.jpg"
#define bl "87_back_left.jpg"
#define br "87_back_right.jpg"

//#define fc1 "_front_center"
//#define fl1 "_front_left"
//#define fr1 "_front_right"
//#define bc1 "_back_center"
//#define bl1 "_back_left"
//#define br1 "_back_right"

#define fc1 "11"
#define fl1 "10"
#define fr1 "12"
#define bc1 "01"
#define bl1 "00"
#define br1 "02"

#define jpg ".jpg"

string getTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}

int main()
{
	string   time = getTime();
	cout << time << endl;
	vector<string> files, aimfilefc, aimfilefl, aimfilefr, aimfilebc, aimfilebl, aimfilebr;
	vector<string> r_aimfilefc;
	char * filePath = "C:\\Users\\XW\\Desktop\\sour";//原始图片文件地址
	string aimpath = "C:\\Users\\XW\\Desktop\\size";//存储目标文件地址
	//string str,str1;//取出iter指针的内容str
	int fc_count=0, fl_count=0, fr_count=0, bl_count=0, br_count=0, bc_count=0;
	Mat src;

	//00000表示序号
	int num = 508;
	char buf[6] = { 0 };


	wr wr;
	////获取该路径下的所有文件  
	wr.getFiles(filePath, files);
	//char str[3i];
	int size = files.size();

	//aimfilefc 获取完整的文件名 C:\\Users\\XW\\Desktop\\aim\\87_front_center\\87_front_center0.jpg
	for (int i = 0; i < size; i++)
	{
		
		_snprintf_s(buf, sizeof(buf), "%05d", num);
		char *a = buf;
	
		aimfilefc.push_back(aimpath + "\\" + a +"\\"  + a + fc1 + jpg);
		aimfilefl.push_back(aimpath + "\\" + a + "\\" + a + fl1 + jpg);
		aimfilefr.push_back(aimpath + "\\" + a + "\\" + a + fr1 + jpg);
		aimfilebc.push_back(aimpath + "\\" + a + "\\" + a + bc1 + jpg);
		aimfilebl.push_back(aimpath + "\\" + a + "\\" + a + bl1 + jpg);
		aimfilebr.push_back(aimpath + "\\" + a + "\\" + a + br1 + jpg);

		/*aimfilefc.push_back(aimpath + fc1+fc1 + to_string(i) + jpg);
		aimfilefl.push_back(aimpath + fl1+fl1 + to_string(i) + jpg);
		aimfilefr.push_back(aimpath + fr1+fr1 + to_string(i) + jpg);
		aimfilebc.push_back(aimpath + bc1+bc1 + to_string(i) + jpg);
		aimfilebl.push_back(aimpath + bl1+bl1 + to_string(i) + jpg);
		aimfilebr.push_back(aimpath + br1+br1 + to_string(i) + jpg);*/

		num++;

	}

	

	for (int i = 0; i < size; i++)
	{
	
		//过滤
		if (files[i].substr(files[i].length() - 1 - 19 + 1, files[i].length() - 1) == fc)
		{
			//cout << aimfilefc[fc_count] << endl;
			 src = imread(files[i].c_str(), 1);
			imwrite(aimfilefc[fc_count].c_str(), src);
			fc_count++;
		
		}

		if (files[i].substr(files[i].length() - 1 - 18 + 1, files[i].length() - 1) == fr)
		{
			 src = imread(files[i].c_str(), 1);
			 imwrite(aimfilefr[fr_count].c_str(), src);
			 fr_count++;
		}
		if (files[i].substr(files[i].length() - 1 - 17 + 1, files[i].length() - 1) == fl)
		{
			 src = imread(files[i].c_str(), 1);
			 imwrite(aimfilefl[fl_count].c_str(), src);
			 fl_count++;
		}	
		if (files[i].substr(files[i].length() - 1 - 18 + 1, files[i].length() - 1) == bc)
		{
			 src = imread(files[i].c_str(), 1);
			 imwrite(aimfilebc[bc_count].c_str(), src);
		    bc_count++;
		}	
		if (files[i].substr(files[i].length() - 1 - 17 + 1, files[i].length() - 1) == br)
		{
			src = imread(files[i].c_str(), 1);
			imwrite(aimfilebr[br_count].c_str(), src);
			br_count++;
		}	
		if (files[i].substr(files[i].length() - 1 - 16 + 1, files[i].length() - 1) == bl)
		{
			src = imread(files[i].c_str(), 1);
			imwrite(aimfilebl[bl_count].c_str(), src);
			bl_count++;
		}	
	


	}



	//cout << files[i].c_str() << endl;
	//cout << files[i].substr(files[i].length()-1-19+1, files[i].length() - 1) << endl;

	string   time1 = getTime();
	cout << time1 << endl;

	system("pause");
	//waitKey(i);
	return 0;
}