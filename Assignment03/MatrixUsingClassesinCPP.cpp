#include "Matrix.h"
#include <bits\stdc++.h>
using namespace std;
// data memebers to private and methods to public
int main()
{
  cout << "\t\tMatrix Class Simulation in C++\n";
  cout << "First Matrix\n";
  unsigned int r1, c1, r2, c2;
  cout << "Enter the number of rows\n";
  cin >> r1;
  cout << "Enter the number of columns\n";
  cin >> c1;
  vector<vector<double>> v1;
  cout << "Enter the numbers\n";
  for (int i = 0; i < r1; i++)
  {
    vector<double> v11;
    for (int j = 0; j < c1; j++)
    {
      double b1;
      cin >> b1;
      v11.push_back(b1);
    }
    v1.push_back(v11);
  }
  Matrix M1(r1, c1, v1);
  cout << "Second Matrix\n";
  cout << "Enter the number of rows\n";
  cin >> r2;
  cout << "Enter the number of columns\n";
  cin >> c2;
  vector<vector<double>> v2;
  cout << "Enter the numbers\n";
  for (int i = 0; i < r2; i++)
  {
    vector<double> v22;
    for (int j = 0; j < c2; j++)
    {
      double b2;
      cin >> b2;
      v22.push_back(b2);
    }
    v2.push_back(v22);
  }
  Matrix M2(r2, c2, v2);
  cout << "Matrix 1 is:\n";
  M1.print();
  cout << "Matrix 2 is:\n";
  M2.print();
  cout << "Transpose of Matrix 1 is:\n";
  Matrix M1t = M1.Transpose();
  M1t.print();
  cout << "Transpose of Matrix 2 is :\n";
  Matrix M2t = M2.Transpose();
  M2t.print();
  if (r1 == r2 && c1 == c2)
  {
    Matrix M3(r1, c1, 0);
    M3 = M1.Sum(M2);
    cout << "Sum Matrix is:\n";
    M3.print();
    Matrix M4(r1, c2, 0);
    M4 = M1.Subtract(M2);
    cout << "Difference Matrix is:\n";
    M4.print();
  }
  else
  {
    cout << "Matrices cannot be subtracted or added\n";
  }
  if (c1 == r2)
  {
    Matrix M5(r1, c2, 0);
    M5 = M1.Multiply(M2);
    cout << "The Product Matrix is:\n";
    M5.print();
  }
  else
  {
    cout << "Matrices cannot be multiplied\n";
  }
  if (M1 == M2)
  {
    cout << "The Matrices are equal\n";
  }
  else
  {
    cout << "The Matrices are not equal\n";
  }
  int sr, er, sc, ec;
  cout << "Submatrix of Matrix 1\n";
  cout << "Enter the start row of the sub-matrix in the given matrix\n";
  cin >> sr;
  cout << "Enter the end row of the sub-matrix in the given matrix\n";
  cin >> er;
  cout << "Enter the start column of the sub-matrix in the given matrix\n";
  cin >> sc;
  cout << "Enter the end column of the sub-matrix in the given matrix\n";
  cin >> ec;
  if (M1.check(sr, er, sc, ec))
  {
    Matrix ans = M1.subMatrix(sr, er, sc, ec);
    cout << "The Submatrix is:\n";
    ans.print();
  }
  else
  {
    cout << "The submatrix could not be formed\n";
  }
  double m1, m2;
  if (M1.compatible())
  {
    cout << "The determinant of matrix M1 is:\n"
         << M1.determinant(r1) << "\n";
  }
  else
  {
    cout << "The determinant of Matrix M1 cannot be found\n";
  }
  if (M2.compatible())
  {
    cout << "The determinant of Matrix M2 is:\n"
         << M2.determinant(r2) << "\n";
  }
  else
  {
    cout << "The determinant of Matrix M2 cannot be found\n";
  }
  return 0;
}