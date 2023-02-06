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

template <class T>
void Sort(T arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        Swap(arr[j], arr[j + 1]);
      }
    }
  }
}
template <class T>
void display(T arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
int main()
{
  cout << "For Integers\n";
  cout << "Enter the number of integers\n";
  int n1;
  cin >> n1;
  int a1[n1];
  cout << "Enter the integers\n";
  for (int i = 0; i < n1; i++)
  {
    cin >> a1[i];
  }
  cout << "The integer array is\n";
  display(a1, n1);
  Sort(a1, n1);
  cout << "The sorted integer array is\n";
  display(a1, n1);
  cout << "For Short Values\n";
  cout << "Enter the number of Short values\n";
  int n2;
  cin >> n2;
  short a2[n2];
  cout << "Enter the short values\n";
  for (int i = 0; i < n2; i++)
  {
    cin >> a2[i];
  }
  cout << "The short value array is\n";
  display(a2, n2);
  Sort(a2, n2);
  cout << "The sorted short value array is\n";
  display(a2, n2);
  cout << "For Float\n";
  cout << "Enter the number of Float values\n";
  int n3;
  cin >> n3;
  float a3[n3];
  cout << "Enter the float values\n";
  for (int i = 0; i < n3; i++)
  {
    cin >> a3[i];
  }
  cout << "The floating value array is\n";
  display(a3, n3);
  Sort(a3, n3);
  cout << "The sorted floating value array is\n";
  display(a3, n3);
  cout << "For Double\n";
  cout << "Enter the number of Double values\n";
  int n4;
  cin >> n4;
  double a4[n4];
  cout << "Enter the Double Values\n";
  for (int i = 0; i < n4; i++)
  {
    cin >> a4[i];
  }
  cout << "The Double value array is\n";
  display(a4, n4);
  Sort(a4, n4);
  cout << "The sorted double value array is\n";
  display(a4, n4);
  /* The following Lines are giving error */
  // cout << "For struct\n";
  // cout << "Enter the number of Struct values\n";
  // int n5;
  // cin >> n5;
  // student a5[n5];
  // cout << "Enter the struct values name followed by roll\n";
  // for (int i = 0; i < n5; i++)
  // {
  //   cin >> a5[i].name;
  //   cin >> a5[i].roll;
  // }
  // cout << "The struct array is :\n";
  // display(a5, n5);
  // Sort(a5, n5);
  // cout << "The sorted struct array is:\n";
  // display(a5, n5);
}