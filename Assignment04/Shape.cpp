#include <iostream>
#include <iomanip>

#define PI 3.14159265359

using namespace std;

class Shape
{
public:
  virtual void readData() = 0;
  virtual double calcArea() = 0;
};

class Triangle : public Shape
{
  double base;
  double height;

public:
  Triangle() : base(0), height(0){};
  Triangle(const double, const double);
  void readData();
  double calcArea();
};

Triangle::Triangle(const double b, const double h)
{
  base = b;
  height = h;
}

void Triangle::readData()
{
  cout << "Enter the Base of the Triangle:\n";
  cin >> base;
  cout << "Enter the height of the Triangle:\n";
  cin >> height;
}

double Triangle::calcArea()
{
  return (0.5 * base * height);
}

class Rectangle : public Shape
{
  double length;
  double width;

public:
  Rectangle() : length(0), width(0){};
  Rectangle(const double, const double);
  void readData();
  double calcArea();
};

Rectangle::Rectangle(const double l, const double w)
{
  length = l;
  width = w;
}

void Rectangle::readData()
{
  cout << "Enter the length of the rectangle:\n";
  cin >> length;
  cout << "Enter the width of the rectangle:\n";
  cin >> width;
}

double Rectangle::calcArea()
{
  return length * width;
}

class Circle : public Shape
{
  double radius;

public:
  Circle() : radius(0){};
  Circle(const double);
  void readData();
  double calcArea();
};

Circle::Circle(const double r)
{
  radius = r;
}

void Circle::readData()
{
  cout << "Enter the radius of the circle:\n";
  cin >> radius;
}

double Circle::calcArea()
{
  return PI * radius * radius;
}

int main()
{
  double area = 0;
  cout << fixed << setprecision(6);
  cout << "\t\tShape Area in C++\n";
  Shape *pt;
  cout << "For Triangle\n";
  pt = new Triangle();
  pt->readData();
  area += pt->calcArea();
  cout << "The area of the triangle is:\n"
       << pt->calcArea() << "\n";
  pt = new Rectangle();
  cout << "For Rectangle\n";
  pt->readData();
  area += pt->calcArea();
  cout << "The area of the rectangle is:\n"
       << pt->calcArea() << "\n";
  pt = new Circle();
  cout << "For Circle\n";
  pt->readData();
  area += pt->calcArea();
  cout << "The area of the circle is:\n"
       << pt->calcArea() << "\n";
  cout << "Total area covered by these shapes is:\n"
       << area << "\n";
  free(pt);
  return 0;
}
