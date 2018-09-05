#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


#include <iomanip>
#include <ios>
#include <stdexcept>


#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<Mmsystem.h>


#include"Student_info.h"
#include"grade.h"
#include"median.h"

using std::vector;
using std::cin;
using std::setw;
using std::cout;
using std::setprecision;
using std::streamsize;
using std::domain_error;
using std::endl;


std::vector<Student_info> fail(std::vector<Student_info>& s, int failedsize)
{
	vector<Student_info> failed_students;

	LARGE_INTEGER large_interger;
	double dff;
	__int64 c1, c2;
	QueryPerformanceFrequency(&large_interger);
	dff = large_interger.QuadPart; //高精度计时器频率
	QueryPerformanceCounter(&large_interger);
	c1 = large_interger.QuadPart; //第一次计时器值


	double final_grade;
	for (vector<Student_info>::iterator sir = s.begin(); sir < s.end(); sir++)
	{
		final_grade = grade(*sir);
		if (final_grade < 40)
		{
			failed_students.push_back(*sir);
			sir = s.erase(sir);
		}
	}

	QueryPerformanceCounter(&large_interger);
	c2 = large_interger.QuadPart;//第二次计时器值

	double Dauer = (c2 - c1) * 1000 / dff;
	printf("本机高精度计时器频率%lf\n", dff);
	printf("第一次计时器值%I64d 第二次计时器值%I64d 计时器差%I64d\n", c1, c2, c2 - c1);
	printf("计时%lf毫秒\n", (c2 - c1) * 1000 / dff);
	printf("By Chen Shao\n");




	failedsize = failed_students.size();
	cout << "Unter  "<<s.size()<< " Studenten sind insgesamt   " << failedsize << "  Studenten nicht ausreichend.";
	return failed_students;
}

//
//int print_grade(std::vector<Student_info> s,int maxlen)
//{
//	for (std::vector<Student_info>::size_type i = 0; i < s.size(); ++i)
//	{
//		cout << setw(maxlen + 1) << s[i].name<<"   ";
//
//
//		try
//		{
//			double final_grade = grade(s[i]);
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << final_grade    
//				<< setprecision(prec);
//		}
//		catch (domain_error e)
//		{
//			cout << e.what();
//		}
//		cout << endl;
//	}
//	return 0;
//}
