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