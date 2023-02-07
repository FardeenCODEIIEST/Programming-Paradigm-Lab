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
  Matrix(unsigned int, unsigned int, double);                 // Assigning all elements to the double value
  Matrix(unsigned int, unsigned int, vector<vector<double>>); // parameterised
  Matrix Sum(Matrix &);
  Matrix Subtract(Matrix &);
  Matrix Multiply(Matrix &);
  bool operator==(Matrix &);
  Matrix Transpose();
  void print();
  unsigned int getRows();
  unsigned int getCols();
  Matrix subMatrix(int, int, int, int);
  bool check(int, int, int, int);
  bool compatible();
  Matrix sub_matrix(int, int, int);
  double determinant(int);
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
  }
  return product;
}

bool Matrix::operator==(Matrix &B)
{
  if (this->getRows() != B.getRows())
  {
    return false;
  }
  if (this->getCols() != B.getCols())
  {
    return false;
  }
  int n1 = this->getRows();
  int n2 = this->getCols();
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n2; j++)
    {
      if (this->matrix[i][j] != B.matrix[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

bool Matrix::check(int sr, int er, int sc, int ec)
{
  if (sr >= er)
  {
    return false;
  }
  if (sr < 0 && er >= this->row)
  {
    return false;
  }
  if (sc >= ec)
  {
    return false;
  }
  if (sc < 0 && ec >= this->col)
  {
    return false;
  }
  return true;
}

Matrix Matrix::subMatrix(int sr, int er, int sc, int ec)
{
  Matrix res(er - sr + 1, ec - sc + 1, 0);
  for (int i = sr; i <= er; i++)
  {
    for (int j = sc; j <= ec; j++)
    {
      res.matrix[i - sr][j - sc] = this->matrix[i][j];
    }
  }
  return res;
}

Matrix Matrix::sub_matrix(int p, int q, int n)
{
  int N = this->row;
  Matrix res(N, N, 0);
  int i = 0, j = 0;
  // filling the sub matrix
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < n; col++)
    {
      // skipping if the current row or column is not equal to the current
      // element row and column
      if (row != p && col != q)
      {
        res.matrix[i][j++] = this->matrix[row][col];
        if (j == n - 1)
        {
          j = 0;
          i++;
        }
      }
    }
  }
  return res;
}
double Matrix::determinant(int n)
{
  double determinant = 0;
  if (n == 1)
  {
    return this->matrix[0][0];
  }
  if (n == 2)
  {
    return (this->matrix[0][0] * this->matrix[1][1]) - (this->matrix[0][1] * this->matrix[1][0]);
  }
  int N = this->row;
  Matrix temp(N, N, 0);
  int sign = 1;
  for (int i = 0; i < n; i++)
  {
    temp = sub_matrix(0, i, n);
    determinant += sign * matrix[0][i] * temp.determinant(n - 1);
    sign = -sign;
  }
  return determinant;
}

bool Matrix::compatible()
{
  if (this->row == this->col)
  {
    return true;
  }
  return false;
}