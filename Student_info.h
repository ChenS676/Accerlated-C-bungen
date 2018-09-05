#ifndef GUARD_Student_info
#define GUARD_Student_info

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

std::ifstream& read(std::ifstream&, Student_info&);

std::ifstream& read_hw(std::ifstream&, std::vector<double>&);

bool printStudent_info(std::vector<Student_info>,int);





#endif // !GUARD_Student_info
