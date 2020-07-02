#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;


template<class T>
void createArr(T *arr, int Size)
{
	cout << "Enter mas" << endl;
	T *p = new T;
	for (int i = 0; i < Size; i++)
	{
		cin >> *p;
		arr[i] = *p;
	}
}
/////// Вывод массивов
template<class T>
void writeArr(T *arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

//// Свапы елементов
void swap(string& left, string& right)
{
	string buffer = left;
	left = right;
	right = buffer;
}
void swap(int& left, int& right)
{
	int buffer = left;
	left = right;
	right = buffer;
}

///// Определение больше ли первый елемент 
bool compare_greater(string left, string right)
{
	if (left > right)
		return true;
	else
		return false;
}
bool compare_greater(int left, int right)
{
	if (left > right)
		return true;
	else
		return false;
}

/////// Сортировка пузырьком
void sortBul(string *arr, bool(*greater)(string left, string right), void(*swp)(string& left, string& right), int Size)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = Size - 1; j > i; j--)
		{
			if (greater(arr[j - 1], arr[j]))
			{
				swp(arr[j - 1], arr[j]);
			}
		}
	}
}
void sortBul(int *arr, bool(*greater)(int left, int right), void(*swp)(int& left, int& right), int Size)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = Size - 1; j > i; j--)
		{
			if (greater(arr[j - 1], arr[j]))
			{
				swp(arr[j - 1], arr[j]);
			}
		}
	}
}


//// сортировка прямым включением
void sortPr(string *arr, bool(*greater)(string left, string right), int Size)
{
	for (int i = 1; i < Size; i++)
	{
		int index = i;
		string value = arr[i];
		string low1 = value;
		transform(low1.begin(), low1.end(), low1.begin(), tolower);
		string low2 = arr[index - 1];
		transform(low2.begin(), low2.end(), low2.begin(), tolower);
		while ((index > 0) && (greater(low2, low1)))
		{

			arr[index] = arr[index - 1];
			index--;
			if (index != 0) transform(arr[index - 1].begin(), arr[index - 1].end(), low2.begin(), tolower);
		}
		arr[index] = value;
	}

}
void sortPr(int *arr, bool(*greater)(int left, int right), int Size)
{
	for (int i = 1; i < Size; i++)
	{
		int value = arr[i];
		int index = i;
		while ((index > 0) && (greater(arr[index - 1], value)))
		{
			arr[index] = arr[index - 1];
			index--;
		}
		arr[index] = value;
	}
}

template<class T>
void delS(T *&mas,int &Size)
{
	int count = 1;
	int j = 1;
	for (int i = 1; i < Size; i++)
	{
		if (mas[i] != mas[i - 1]) count++;
	}
	T *b = new T[count];
	b[0] = mas[0];
	for (int i = 1; i < Size; i++)
	{
		if (mas[i] != mas[i - 1]) b[j++] = mas[i];
	}
	Size = count;
	delete[]mas;
	mas = b;
}

int main()
{
	int SizeI = 5;
	int SizeS = 5;
	cout << "INTEGER" << endl;
	int *mas = new int[SizeI];
	createArr(mas, SizeI);
	writeArr(mas, SizeI);
	sortBul(mas, compare_greater, swap, SizeI);
	writeArr(mas, SizeI);
	delS(mas,SizeI);
	writeArr(mas, SizeI);
	delete[]mas;
	cout << "string" << endl;
	string *vv = new string[SizeS];
	createArr(vv, SizeS);
	writeArr(vv, SizeS);
	sortPr(vv, compare_greater, SizeS);
	writeArr(vv, SizeS);
	delS(vv, SizeS);
	writeArr(vv, SizeS);
	delete[]vv;
}


