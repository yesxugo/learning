#ifndef WR_H
#define WR_H
#include<iostream>
#include<vector>
#include<io.h>
using namespace std;

#define MAX_PATH 180


class wr
{
public:

	void getFiles(string path, string path2, vector<string>& files);
	void getFiles(string path, vector<string>& files);
	void getAllFiles(string path, vector<string>& files);

};



#endif // WR_H



