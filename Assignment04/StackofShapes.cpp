#include <iostream>
#include <iomanip>

#define PI 3.14159265359
#define MAX 40

using namespace std;

class Shape
{
public:
  virtual void readData() = 0;
  virtual double calcArea() = 0;
  virtual void display() = 0;
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
  void display();
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

void Triangle::display()
{
  cout << "Triangle:\n"
       << "Base:\n"
       << base << "\nHeight:\n"
       << height << "\nArea:\n"
       << calcArea() << "\n";
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
  void display();
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

void Rectangle::display()
{
  cout << "Rectangle\n"
       << "Length:\n"
       << length << "\nWidth:\n"
       << width << "\nArea:\n"
       << calcArea() << "\n";
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
  void display();
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

void Circle::display()
{
  cout << "Circle\n"
       << "Radius:\n"
       << radius << "\nArea:\n"
       << calcArea() << "\n";
}

double Circle::calcArea()
{
  return PI * radius * radius;
}

class ShapeStack
{
  Shape *shp[MAX]; // Array of pointers to objects
  int top;
  int size;
  double totalarea;

public:
  ShapeStack() : size(0), top(-1), totalarea(0)
  {
    for (int i = 0; i < MAX; i++)
    {
      shp[i] = NULL;
    }
  }; // Stack is already created
  void push();
  void pop();
  void displayParticular(const int);
  void displayShapes();
  double TotalAreaCovered();
};

void ShapeStack::push()
{
  if (size == MAX)
  {
    cout << "Stack Overflow\n";
    return;
  }
  char ch;
  cout << "Enter\na.Triangle\nb.Rectangle\nc.Circle\n";
  cin >> ch;
  top++;
  if (ch == 'a')
  {
    shp[top] = new Triangle;
    shp[top]->readData();
    totalarea += shp[top]->calcArea();
    size++;
  }
  else if (ch == 'b')
  {
    shp[top] = new Rectangle;
    shp[top]->readData();
    totalarea += shp[top]->calcArea();
    size++;
  }
  else if (ch == 'c')
  {
    shp[top] = new Circle;
    shp[top]->readData();
    totalarea += shp[top]->calcArea();
    size++;
  }
  else
  {
    cout << "Wrong choice\n";
    return;
  }
  cout << "Shape has been pushed successfully\n";
}

void ShapeStack::pop()
{
  if (size == 0)
  {
    cout << "Stack Underflow\n";
    return;
  }
  cout << "The top element in the stack is:\n";
  shp[top]->display();
  totalarea -= shp[top]->calcArea();
  delete shp[top];
  shp[top] = NULL;
  cout << "Shape has been popped successfully\n";
  top--;
  size--;
}

void ShapeStack::displayParticular(const int p)
{
  if (p >= MAX || p < 0)
  {
    cout << "OutofBounds Error\n";
  }
  else if (shp[p] == NULL)
  {
    cout << "No Shape is there in this position\n";
  }
  else
  {
    shp[p]->display();
  }
}

void ShapeStack::displayShapes()
{
  for (int i = top; i >= 0; i--)
  {
    shp[i]->display();
    if (i != 0)
      cout << "-----------------------------------------------------------\n";
  }
}

double ShapeStack::TotalAreaCovered()
{
  return totalarea;
}

int main()
{
  cout << fixed << setprecision(6);
  cout << "\t\tShape Stack in C++\n";
  ShapeStack St;
  cout << "Max Capacity of the stack is 40\n";
  while (1)
  {
    cout << "Enter\n0.To terminate\n1.Push Shapes\n2.Pop Shapes\n3.Display Shape at Particular location\n4.Total Area covered by all the shapes\n5.Display all Shapes\n";
    int ch;
    cin >> ch;
    if (ch == 0)
    {
      cout << "Goodbye\n";
      break;
    }
    else if (ch == 1)
    {
      St.push();
    }
    else if (ch == 2)
    {
      St.pop();
    }
    else if (ch == 3)
    {
      int pos;
      cout << "Enter the position of the shape assume 0 based indexing\n";
      cin >> pos;
      St.displayParticular(pos);
    }
    else if (ch == 4)
    {
      cout << "Total Area covered is:\n"
           << St.TotalAreaCovered() << "\n";
    }
    else if (ch == 5)
    {
      cout << "All the shapes are\n";
      St.displayShapes();
    }
    else
    {
      cout << "Wrong choice try again\n";
    }
  }
  return 0;
}