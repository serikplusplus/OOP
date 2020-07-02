
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class  Student
{
public:
	Student()
	{
		name = new string;
		*name = "";
		age = new int;
		*age = 0;
		bal = new float;
		*bal = 0;
	}
	Student(const string m,const int a,const double b)
	{
		name = new string;
		*name = m;
		age = new int;
		*age = a;
		bal = new float;
		*bal = b;
	}
	Student(const Student& aMess)
	{
		name = new string;
		*name = *(aMess.name);
		age = new int;
		*age = *(aMess.age);
		bal = new float;
		*bal = *(aMess.bal);
	}
	Student(Student&& aMess)
	{
		cout << "Move copy constructor called." << endl;
		name = aMess.name;
		aMess.name = nullptr;
		age = aMess.age;
		aMess.age = nullptr;
		bal = aMess.bal;
		aMess.bal = nullptr;
	}

	Student& operator=(Student&& aMess)
	{
		cout << "Move assignment operator function called." << endl;
		delete name,age,bal;
		name = aMess.name;
		aMess.name = nullptr;
		age = aMess.age;
		aMess.age = nullptr;
		bal = aMess.bal;
		aMess.bal = nullptr;
		return *this;
	}

	Student& operator=(const Student& aMess)
	{
		delete name, age, bal;
		name = new string;
		*name = *(aMess.name);
		age = new int;
		*age = *(aMess.age);
		bal = new float;
		*bal = *(aMess.bal);
		return *this;
	}
	void print()
	{
		cout << *name <<"\t"<<*age<<"\t"<<*bal<< endl;
	}
	~Student()
	{
		delete name, age, bal;
	}
private:
	string *name;
	int *age;
	float *bal;
};

int main()
{
	Student *student1 = new Student("Nikita",15,6.3);
	Student *student2 = new Student(move(*student1));
	Student *student3 = new Student;
	*student3 = move(*student2);
	student3->print();
}
