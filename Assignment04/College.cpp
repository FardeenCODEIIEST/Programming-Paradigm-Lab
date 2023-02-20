#include <iostream>
#include <iomanip>
using namespace std;

/*
  Level 1: Person
  Level 2: Student , Staff
  Level 3: Professor, Clerk
*/

class Person
{
private:
  string name;
  int age;
  char gender;

public:
  Person();
  Person(const string, const int, const char);
  Person(const Person &);
  ~Person();
  void read();
  void display();
};

Person::Person()
{
  name = "";
  age = -1;
  gender = 'u';
}

Person::Person(const string s1, const int n, const char ch)
{
  name = s1;
  age = n;
  gender = ch;
}

Person::Person(const Person &P)
{
  name = P.name;
  age = P.age;
  gender = P.gender;
}

Person::~Person()
{
  name = "";
}

void Person::read()
{
  cout << "Enter the name:\n";
  cin >> name;
  cout << "Enter the age:\n";
  cin >> age;
  cout << "Enter the gender 'm' or 'f':\n";
  cin >> gender;
}

void Person::display()
{
  cout << "The name is:\n"
       << name << "\n";
  cout << "The age is:\n"
       << age << "\n";
  cout << "The gender is:\n"
       << gender << "\n";
}
