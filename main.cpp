//Accerlated C++ Unit 5 Uebung 5-2 
//要求: 使用向量抽取不及格学生的记录
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>




#include "grade.h"
#include "Student_info.h"
#include "Verarbeitung.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::setw;
using std::ifstream;
using std::ios;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;


	//打开文件读取信息
	ifstream inFile;
	inFile.open("daten_students10.dat",ios::in);
	

	while (read(inFile, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	
	//printStudent_info(students, maxlen);
	//sort(students.begin(), students.end(), compare);



	//抽取不及格的学生
	//计时测试函数性能 QueryPerformanceCounter() 微妙
	vector<Student_info> failed_students;
	int s = 0;
	failed_students = fail(students, s);

	void close();
	return 0;
}

// Note: 这个打印格式 还没有封装  