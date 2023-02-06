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