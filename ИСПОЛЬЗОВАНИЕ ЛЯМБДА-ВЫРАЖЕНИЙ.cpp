#include <iostream>
#include <functional>
#include <algorithm>
#include <list>
using namespace std;

const int Size = 50;

template <class T>
void create(list<T>& vec)
{
	T sum = 0;
	T i = 1;
	generate(vec.begin(), vec.end(), [&i]() { T num = i * i; i++; return num; });
	for_each(vec.begin(), vec.end(),
		[](const T& value) { cout << value << " "; });
	for_each(vec.begin(), vec.end(),
		[&sum](const T& value)->void { int a = (int)value; (a % 2 == 0) ? sum += value : sum += 0; });
	cout << "\n\n";
	cout << "Sum" << endl;
	cout << sum;
	cout << "\n\n";
	transform(vec.begin(), vec.end(), vec.begin(), [](T& value)->T { int a = (int)value; if (a % 2 == 0)return value * -1; else return value; });
	for_each(vec.begin(), vec.end(),
		[](const T& value) { cout << value << " "; });
}

int main()
{
	list<float> vec(Size);
	create(vec);
}