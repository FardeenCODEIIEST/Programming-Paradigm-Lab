#include <bits\stdc++.h>
using namespace std;
// data memebers to private and methods to public
class Matrix
{
private:
  unsigned int row;
  unsigned int col;
  vector<vector<double>> matrix;

public:
  Matrix(unsigned int, unsigned int, double);                 // default constructor(row,col,initial value)
  Matrix(unsigned int, unsigned int, vector<vector<double>>); // parameterised
  Matrix Sum(Matrix &);
  Matrix Subtract(Matrix &);
  Matrix Multiply(Matrix &);
  Matrix Transpose();
  void print();
  unsigned int getRows();
  unsigned int getCols();
};

// Constructor for any arbitrary matrix

Matrix::Matrix(unsigned int rowSize, unsigned int colSize, double initial)
{
  row = rowSize;
  col = colSize;
  // resize() function use to set the size of the vector
  matrix.resize(rowSize);
  for (unsigned int i = 0; i < matrix.size(); i++)
  {
    matrix[i].resize(colSize, initial);
  }
}

// Constructor for user defined matrix
// Return Type  Class_Name Function_Name()
Matrix::Matrix(unsigned int x, unsigned int y, vector<vector<double>> v)
{
  row = x;
  col = y;
  matrix.resize(x);
  for (unsigned int i = 0; i < matrix.size(); i++)
  {
    matrix[i].resize(y);
  }
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      this->matrix[i][j] = v[i][j];
    }
  }
}

Matrix Matrix::Transpose()
{
  int r = row;
  int c = col;
  Matrix t(c, r, 0.0);
  for (int i = 0; i < col; i++)
  {
    for (int j = 0; j < row; j++)
    {
      t.matrix[i][j] = this->matrix[j][i];
    }
  }
  return t;
}
Matrix Matrix::Sum(Matrix &B)
{
  Matrix sum(row, col, 0.0);
  for (unsigned int i = 0; i < row; i++)
  {
    for (unsigned int j = 0; j < col; j++)
    {
      sum.matrix[i][j] = this->matrix[i][j] + B.matrix[i][j];
    }
  }
  return sum;
}

void Matrix::print()
{
  cout << "The Matrix is \n";
  for (unsigned int i = 0; i < row; i++)
  {
    for (unsigned int j = 0; j < col; j++)
    {
      cout << " " << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

Matrix Matrix::Subtract(Matrix &B)
{
  Matrix diff(row, col, 0.0);
  for (unsigned int i = 0; i < row; i++)
  {
    for (unsigned int j = 0; j < col; j++)
    {
      diff.matrix[i][j] = this->matrix[i][j] - B.matrix[i][j];
    }
  }
  return diff;
}
unsigned int Matrix::getRows()
{
  return this->row;
}
unsigned int Matrix::getCols()
{
  return this->col;
}
Matrix Matrix::Multiply(Matrix &B)
{
  Matrix product(row, B.getCols(), 0.0);
  if (col == B.getRows())
  {
    for (unsigned int i = 0; i < row; i++)
    {
      for (unsigned int j = 0; j < B.getCols(); j++)
      {
        double temp = 0.0;
        for (unsigned int k = 0; k < col; k++)
        {
          temp += matrix[i][k] * B.matrix[k][j];
        }
        product.matrix[i][j] = temp;
      }
    }
    return product;
  }
}
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
  return 0;
}