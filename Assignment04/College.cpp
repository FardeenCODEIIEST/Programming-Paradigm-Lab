#include <iostream>
#include <iomanip>
using namespace std;

/*
  Hierarchy levels
  Level 1:- Person
  level 2:- Academic,Staff
  level 3:-[Student],[Professor],[Clerk]
*/

class Person
{
  string Name;
  int Age;
  char Gender;
  string RegNo;

public:
  Person() : Name(""), Age(-1), Gender('u'), RegNo("000000"){};
  Person(const string, const int, const char, const string);
  Person(const Person &);
  void read();
  void display();
};

Person::Person(const string s1, const int n, const char ch, const string s2)
{
  Name = s1;
  Age = n;
  Gender = ch;
  RegNo = s2;
}

Person::Person(const Person &P)
{
  Name = P.Name;
  Age = P.Age;
  Gender = P.Gender;
  RegNo = P.RegNo;
}

void Person::read()
{
  cout << "Enter the First Name only:\n";
  cin >> Name;
  cout << "Enter the age:\n";
  cin >> Age;
  cout << "Enter the gender:\n";
  cin >> Gender;
  cout << "Enter the Registration Number:\n";
  cin >> RegNo;
}

void Person::display()
{
  cout << "The First Name is:\n"
       << Name << "\n";
  cout << "The Age is:\n"
       << Age << "\n";
  cout << "The Gender is:\n"
       << Gender << "\n";
  cout << "The Registration Number is:\n"
       << RegNo << "\n";
}

class Academic : virtual public Person
{
  string dept;

public:
  Academic() : dept(""){};
  Academic(const string, const int, const char, const string, const string);
  void read();
  void display();
  string department();
  void readDepartment();
};

Academic::Academic(const string s1, const int n, const char ch, const string s2, const string s3) : Person(s1, n, ch, s2)
{
  dept = s3;
}

void Academic::readDepartment()
{
  cout << "Enter the name of the department\n";
  cin >> dept;
}

string Academic::department()
{
  return dept;
}

void Academic::read()
{
  Person::read();
  readDepartment();
}

void Academic::display()
{
  Person::display();
  cout << "The department is:\n"
       << department() << "\n";
}

class Staff : virtual public Person
{
  double salary;

public:
  Staff() : salary(0.00){};
  Staff(const string, const int, const char, const string, const double);
  void read();
  void display();
  void readSalary();
  double Salary();
};

Staff::Staff(const string s1, const int n, const char ch, const string s2, const double sal) : Person(s1, n, ch, s2)
{
  salary = sal;
}

void Staff::readSalary()
{
  cout << "Enter the Salary:\n";
  cin >> salary;
}

double Staff::Salary()
{
  return salary;
}

void Staff::read()
{
  Person::read();
  readSalary();
}

void Staff::display()
{
  Person::display();
  cout << "The Salary is:\n"
       << Salary() << "\n";
}

class Student : public Academic
{
  int year;

public:
  Student() : year(0){};
  Student(const string, const int, const char, const string, const string, const int);
  void read();
  void display();
  void Year();
  int displayyear();
};

Student::Student(const string s1, const int n, const char ch, const string s2, const string s3, const int y) : Academic(s1, n, ch, s2, s3), Person(s1, n, ch, s2)
{
  year = y;
}

int Student::displayyear()
{
  return year;
}

void Student::Year()
{
  cout << "Enter the year:\n";
  cin >> year;
}

void Student::read()
{
  Academic::read();
  Year();
}

void Student::display()
{
  Academic::display();
  cout << "The Year is:\n"
       << displayyear() << "\n";
}

class Professor : public Staff, public Academic
{
  string CoureLoad;

public:
  Professor() : CoureLoad(""){};
  Professor(const string, const int, const char, const string, const string, const double, const string);
  void read();
  void display();
  string course();
  void readCourse();
};

Professor::Professor(const string s1, const int n, const char ch, const string s2, const string s3, const double sal, const string s4) : Academic(s1, n, ch, s2, s3), Staff(s1, n, ch, s2, sal), Person(s1, n, ch, s2)
{
  CoureLoad = s4;
}

string Professor::course()
{
  return CoureLoad;
}

void Professor::readCourse()
{
  cout << "Enter the Course Load\n";
  cin >> CoureLoad;
}

void Professor::read()
{
  Person::read();
  Academic::readDepartment();
  Staff::readSalary();
  readCourse();
}

void Professor::display()
{
  Person::display();
  cout << "The Department is:\n"
       << Academic::department() << "\n";
  cout << "The Salary is:\n"
       << Staff::Salary() << "\n";
  cout << "The Course Load is:\n"
       << course() << "\n";
}

class Clerk : public Staff
{
  string WorkLoad;

public:
  Clerk() : WorkLoad(""){};
  Clerk(const string, const int, const char, const string, const double, const string);
  void read();
  void display();
  string workload();
  void work();
};

Clerk::Clerk(const string s1, const int n, const char ch, const string s2, const double sal, const string s3) : Staff(s1, n, ch, s2, sal), Person(s1, n, ch, s2)
{
  WorkLoad = s3;
}

string Clerk::workload()
{
  return WorkLoad;
}

void Clerk::work()
{
  cout << "Enter the WorkLoad:\n";
  cin >> WorkLoad;
}

void Clerk::read()
{
  Staff::read();
  work();
}

void Clerk::display()
{
  Staff::display();
  cout << "The Workload is:\n"
       << workload() << "\n";
}

int main()
{
  cout << fixed << setprecision(6);
  cout << "\t\tSimulation of College level Design in C++\n";
  Student S1;
  cout << "Enter Student Details\n";
  S1.read();
  cout << "The Student Details are:\n";
  S1.display();
  Professor P1;
  cout << "Enter Professor Details\n";
  P1.read();
  cout << "The Professor Details are:\n";
  P1.display();
  Clerk C1;
  cout << "Enter the Clerk Details:\n";
  C1.read();
  cout << "The Clerk details are:\n";
  C1.display();
  return 0;
}
