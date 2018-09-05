#include"Student_info.h"
#include<fstream>
#include<iostream>
#include<iomanip>
#include<ios>

#include "Student_info.h"
#include "grade.h"


using std::istream;
using std::vector;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;
using std::domain_error;
using std::setw;
using std::setprecision;


bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

ifstream& read(ifstream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

ifstream& read_hw(ifstream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}

bool printStudent_info(vector<Student_info> s, int maxlen)
{
	
	if (s.size() == 0)
	{
		cout << "Das Dokument ist leer, bitte ¨¹berpr¨¹fen Sie!!!";
		return false;
	}


	//´òÓ¡³É¼¨
	for (std::vector<Student_info>::size_type i = 0; i < s.size(); ++i)
	{
		cout << setw(maxlen + 1) << s[i].name << "   ";
		try
		{
			double final_grade = grade(s[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec);
		}
		catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}

	return true;
}