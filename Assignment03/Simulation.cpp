#include <iostream>
#include <vector>
using namespace std;

class Screen
{
private:
  int height;
  int width;
  vector<vector<char>> screen;

public:
  Screen(int, int);
  void empty();
};

class Line : public Screen
{
  Line(int, int);
};

class Circle : public Screen
{
  Circle(int, int);
};

class Rectangle : public Screen
{
  Rectangle(int, int);
};

Screen::Screen(int ht, int wd)
{
  height = ht;
  width = wd;
  for (int i = 0; i < ht; i++)
  {
    for (int j = 0; j < wd; j++)
    {
      screen[i].push_back(' ');
    }
  }
}

void Screen::empty()
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      screen[i][j]=' ';
    }
  }
}

Line::Line(int a,int b);