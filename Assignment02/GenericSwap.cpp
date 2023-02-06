#include <iostream>
using namespace std;

typedef struct student
{
  string name;
  int roll;
} student;
template <class T>
int Swap(T &x, T &y)
{
  T t;
  t = x;
  x = y;
  y = t;
  return 0;
}

int main()
{
  int a, b;
  short c, d;
  float e, f;
  double g, h;
  student s1, s2;
  cout << "For Integers\n";
  cin >> a >> b;
  cout << "Integers are : " << a << " " << b << "\n";
  Swap(a, b);
  cout << "Integers swapped are " << a << " " << b << "\n";
  cout << "For Short\n";
  cin >> c >> d;
  cout << "Short values are : " << c << " " << d << "\n";
  Swap(c, d);
  cout << "Short values swapped are " << c << " " << d << "\n";
  cout << "For Float\n";
  cin >> e >> f;
  cout << "Float values are : " << e << " " << f << "\n";
  Swap(e, f);
  cout << "Float values swapped are " << e << " " << f << "\n";
  cout << "For Double\n";
  cin >> g >> h;
  cout << "Double values are : " << g << " " << h << "\n";
  Swap(g, h);
  cout << "Double values swapped are " << g << " " << h << "\n";
  cout << "For struct values\n";
  cout << "Enter the First Student details\n";
  cout << "Enter name\n";
  string st, st1;
  cin >> st;
  cout << "Enter the roll\n";
  int r1, r2;
  cin >> r1;
  s1.name = st;
  s1.roll = r1;
  cout << "Enter the Second Student details\n";
  cout << "Enter the name\n";
  cin >> st1;
  cout << "Enter the roll\n";
  cin >> r2;
  s2.name = st1;
  s2.roll = r2;
  cout << "Students are\n";
  cout << "Name \t Roll\n"
       << s1.name << " \t " << s1.roll << "\n"
       << s2.name << " \t " << s2.roll << "\n";
  Swap(s1, s2);
  cout << "Swapped Data\n";
  cout << "Name \t\t Roll\n"
       << s1.name << " \t " << s1.roll << "\n"
       << s2.name << " \t " << s2.roll << "\n";
  return 0;
}
