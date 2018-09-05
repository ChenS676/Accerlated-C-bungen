#ifndef GUARD_Verarbeitung_h
#define GUARD_Verarbeitung_h


#include<vector>
#include<string>
#include"Student_info.h"
#include"grade.h"


//抽取不合格学生的成绩
std::vector<Student_info> fail(std::vector<Student_info>&, int);
//int printgrade(std::vector<Student_info>,int)
#endif // !GUARD_Verarbeitung_h
