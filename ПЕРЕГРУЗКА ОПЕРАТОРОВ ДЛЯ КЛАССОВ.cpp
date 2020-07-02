#include <iostream>
using namespace std;

const int Size = 5;

template<class T> class MyArray {
public:
	MyArray() {
		for (int i = 0; i < Size; i++)
		{
			nums[i] = 0;
		}
	}
	bool operator == (const MyArray  &Mon)
	{
		for (int i = 0; i < Size; i++)
		{
			if(this->nums[i] != Mon.nums[i]) return false;
		}
		return true;

	}
	bool operator!=(const MyArray  &Mon)
	{
		for (int i = 0; i < Size; i++)
		{
			if (this->nums[i] == Mon.nums[i]) return false;
		}
		return true;
	}
	T operator[](const int index)
	{
		if (index > Size - 1)
		{
			cout << "выход за границы массива !!!!! Возвращен мусор - ";
		}
		else return this->nums[index];
	}

	friend ostream & operator<< (ostream &stream, MyArray  ob)
	{
		for (int i = 0; i < 5; i++)
		{
			stream << ob.nums[i] << "\t";
		}
		stream << "\n";
		return stream;
	}
	friend istream & operator>> (istream &stream, MyArray  &ob)
	{
		cout << "Введите 5 чисел" << endl;
		for (int i = 0; i < 5; i++) {
			stream >> ob.nums[i];
		}
		return stream;
	}
private:
	T nums [Size];
};

int main()
{
	setlocale(LC_ALL, "ru");
	MyArray <int> P1;
		cin >> P1;
		MyArray <int> P2;
		cin >> P2;
	cout << P1;
	cout << P2;

	(P1 == P2) ? cout << "Да они равны\n" : cout << "Нет они не равны\n";
	(P1 != P2) ? cout << "Да они не равны\n" : cout << "Нет они равны\n";
	cout << P1[9]+1;
}