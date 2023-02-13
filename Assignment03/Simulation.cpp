#include <bits\stdc++.h>

#define HEIGHT 162
#define WIDTH 139
#define PI 3.14159265359

using namespace std;

class Screen
{
protected:
  int height;
  int width;
  char screen[HEIGHT][WIDTH];

public:
  Screen();
  Screen(char);
  void empty();
  void show();
};

class Line : public Screen
{
private:
  int heigth, width;
  int x1, x2, y1, y2;

public:
  Line();
  Line drawLine(int, int, int, int);
};

class Ellipse : public Screen
{
private:
  int height, width;
  int r;
  int x, y;

public:
  Ellipse();
  Ellipse drawEllipse(int, int, int);
};

Ellipse::Ellipse()
{
  r = 0;
  x = 0;
  y = 0;
}

Ellipse Ellipse::drawEllipse(int x, int y, int r)
{
  Ellipse result;
  for (int i = 0; i <= 360; i++)
  {
    result.screen[(int)(r * sin(i * PI / 180)) + y][(int)(r * cos(i * PI / 180)) + x] = ' ';
  }
  return result;
}

Line::Line()
{
  x1 = 0;
  x2 = 0;
  y1 = 0;
  y2 = 0;
}

Line Line::drawLine(int a, int b, int c, int d)
{
  Line l1;
  if (a == c)
  {
    for (int i = b; i <= d; i++)
    {
      l1.screen[i][a] = ' ';
    }
    return l1;
  }
  if (b == d)
  {
    for (int i = a; i <= c; i++)
    {
      l1.screen[b][i] = ' ';
    }
    return l1;
  }
  int m = (d - b) / (c - a);
  if (m > 0)
  {
    if (c - a > 0)
    {
      for (int i = b, j = a; i >= 0, j <= c; i -= m, j++)
      {
        l1.screen[i][j] = ' ';
      }
    }
    else
    {
      for (int i = c, j = d; i <= a, j <= b; i += m, j++)
      {
        l1.screen[i][j] = ' ';
      }
    }
  }
  else
  {
    if (d - b < 0)
    {
      for (int i = b, j = a; i >= d, j <= c; i += m, j++)
      {
        l1.screen[i][j] = ' ';
      }
    }
    else
    {
      for (int i = d, j = c; i >= b, j <= a; j++, i += m)
      {
        l1.screen[i][j] = ' ';
      }
    }
  }
  return l1;
}

Screen::Screen()
{
  height = HEIGHT;
  width = WIDTH;
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      this->screen[i][j] = '#';
    }
  }
}

Screen::Screen(char ch)
{
  height = HEIGHT;
  width = WIDTH;
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      this->screen[i][j] = ch;
    }
  }
}

void Screen::empty()
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      screen[i][j] = ' ';
    }
  }
}

void Screen::show()
{
  for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      cout << this->screen[i][j];
    }
    cout << "\n";
  }
}

int main()
{
  cout << "\t\t Screen Simulation in C++\n";
  cout << "Enter the spanning character of the screen\n";
  char ch;
  cin >> ch;
  Screen S1(ch);
  cout << "The spanned screen is:\n";
  S1.show();
  Line l;
  Line res;
  cout << "Enter the x-coordinate of source followed by its y coordinate\n";
  int x1, y1;
  cin >> x1 >> y1;
  cout << "Enter the x-coordinate of destination followed by its y coordinate\n";
  int x2, y2;
  cin >> x2 >> y2;
  res = l.drawLine(x1, y1, x2, y2);
  res.show();
  cout << "Enter the radius of the circle\n";
  int radius;
  cin >> radius;
  cout << "Enter the x-coordinate followed by y-coordinate of the centre\n";
  int x3, y3;
  cin >> x3 >> y3;
  Ellipse C;
  Ellipse Cres = C.drawEllipse(x3, y3, radius);
  Cres.show();
  return 0;
}
