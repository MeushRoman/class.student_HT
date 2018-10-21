#include <iostream>

using namespace std;

class student
{
	char *name;
	bool sex;
	int age;
	int *grades = 0, size = 1;

public:
	student(const char *h_name, bool h_sex, int h_age) {
		grades = new int(0);
		name = new char[strlen(h_name) + 1];
		strcpy_s(name, strlen(h_name) + 1, h_name);
		sex = h_sex;
		age = h_age;
	}

	void addGrd() {

		int *newGrd = new int[size + 1];

		for (int i = 0; i < size; i++)
		{
			newGrd[i] = grades[i];
		}

		cout << "Enter new grades: ";
		cin >> newGrd[size];

		delete[]grades;
		size++;
		grades = newGrd;
	}


	void info() {
		std::cout << "name: " << name << "\nsex: " << sex << "\nage: " << age << endl;
		cout << "grades: ";
		for (int i = 1; i < size; i++)
		{
			cout << grades[i] << " ";
		}
		cout << endl;
	}

	void set_name(const char *h_name) {
		delete[] name;
		name = new char[strlen(h_name) + 1];
		strcpy_s(name, strlen(h_name) + 1, h_name);
	}

	void set_sex(bool n_sex) {
		sex = n_sex;
	}

	void set_age(int n_age) {
		age = n_age;
	}

	char* get_name() {
		return name;
	}

	bool get_sex() {
		return sex;
	}

	int get_age() {
		return age;
	}

	~student() {
		delete[] name;
		delete[] grades;
	}
};


void f(int &x) {
	x++;
}


void main() {



	student s("Nana", 1, 35);
	s.info();
	int n;
	cout << "Entee 1 for add new grades, 0 to exit - ";
	while (true)
	{
		cin >> n;
		switch (n)
		{
		case 1:
			s.addGrd();
			s.info();
			break;
		}
		if (n == 0) break;

	}


	system("pause");
}