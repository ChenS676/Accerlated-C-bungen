//median函数的源文件
#include<algorithm>
#include<stdexcept>
#include<vector>

using std::domain_error;
using std::sort;
using std::vector;

//计算一个vector<double>类型的对象中值 version 1
//double median(vector<double> vec)
//{
//	typedef vector<double>::size_type vec_sz;
//
//	vec_sz size = vec.size();
//
//	if (size == 0)
//	{
//		throw domain_error("median of an empty vector");
//	}
//
//	sort(vec.begin(), vec.end());
//	vec_sz mid = size / 2;
//	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
//}



//计算一个vector<double>类型的对象平均值  version 2
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();

	if (size == 0)
	{
		throw domain_error("median of an empty vector");
	}

	sort(vec.begin(), vec.end());
	

	double num = 0;
	for (vector<double>::iterator vecir = vec.begin(); vecir != vec.end(); vecir++)
	{
		num = num + (*vecir);
	}
	return num/size;
}
