#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Node
{
  int coeff;
  int exp;
  struct Node *next;
} Node;

class Poly
{
private:
  Node *head;

public:
  Poly();
  ~Poly();
  void createPoly(int, int);
  void display(int);
  Poly addPoly(Poly &);
};

Poly::Poly()
{
  head = NULL;
}

Poly::~Poly()
{
  delete head;
}

void Poly::createPoly(int coeff, int exp)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->coeff = coeff;
  temp->exp = exp;
  if (head == NULL)
  {
    temp->next = temp;
    head = temp;
    return;
  }
  else if (temp->exp > head->exp)
  {
    Node *t = head;
    do
    {
      t = t->next;
    } while (t->next != head);
    temp->next = t->next;
    t->next = temp;
    head = temp;
    return;
  }
  else
  {
    Node *t = head;
    do
    {
      if (t->next == head || t->exp < temp->exp)
        break;
      else if (t->next->exp < temp->exp)
        break;
      t = t->next;
    } while (t != head);
    temp->next = t->next;
    t->next = temp;
  }
  return;
}

void Poly::display(int rep)
{
  if (head == NULL)
  {
    printf("There is nothing to display\n");
  }
  else
  {
    printf("The Polynomial %d is:\n", rep);
    Node *t = head;
    printf("%dx^%d ", t->coeff, t->exp);
    t = t->next;
    while (t != head)
    {
      if (t->exp == 0)
      {
        printf("+ %d", t->coeff);
        break;
      }
      printf("+ %dx^%d ", t->coeff, t->exp);
      t = t->next;
    }
    printf("\n");
  }
}

Poly Poly::addPoly(Poly &B)
{
  Poly add;
  Node *t1 = this->head;
  Node *t2 = B.head;
  int c1 = 0, c2 = 0;
  if (this->head == NULL && B.head != NULL)
  {
    add.head = B.head;
    return add;
  }
  else if (this->head != NULL && B.head == NULL)
  {
    add.head = this->head;
    return add;
  }
  else if (this->head == NULL && B.head == NULL)
  {
    add.head == NULL;
    return add;
  }
  int e, d;
  do
  {
    if (t1->exp < t2->exp)
    {
      d = t2->coeff;
      e = t2->exp;
      add.createPoly(d, e);
      t2 = t2->next;
      c2++;
    }
    else if (t1->exp > t2->exp)
    {
      d = t1->coeff;
      e = t1->exp;
      add.createPoly(d, e);
      t1 = t1->next;
      c1++;
    }
    else
    {
      e = t1->exp;
      d = t1->coeff + t2->coeff;
      add.createPoly(d, e);
      t1 = t1->next;
      t2 = t2->next;
      c1++;
      c2++;
    }
  } while (t1 != this->head || t2 != B.head);
  if (t1 != this->head || c1 == 0)
  {
    do
    {
      d = t1->coeff;
      e = t1->exp;
      add.createPoly(d, e);
      t1 = t1->next;
    } while (t1 != this->head);
  }
  if (t2 != B.head || c2 == 0)
  {
    do
    {
      d = t2->coeff;
      e = t2->exp;
      add.createPoly(d, e);
      t2 = t2->next;
    } while (t2 != B.head);
  }
  return add;
}

int main()
{
  Poly poly1, poly2;
  cout << "\t\t Polynomial Addition\n";
  cout << "For Polynomial 1\n";
  cout << "Enter the total number of terms in polynomial 1\n";
  int n1;
  cin >> n1;
  int c1, e1;
  for (int i = 1; i <= n1; i++)
  {
    cout << "Enter the coefficient value\n";
    cin >> c1;
    cout << "Enter the exponent value\n";
    cin >> e1;
    poly1.createPoly(c1, e1);
  }
  cout << "For Polynomial 2\n";
  cout << "Enter the total number of terms in polynomial 2\n";
  int n2;
  cin >> n2;
  int c2, e2;
  for (int i = 1; i <= n2; i++)
  {
    cout << "Enter the coefficient value\n";
    cin >> c2;
    cout << "Enter the exponent value\n";
    cin >> e2;
    poly2.createPoly(c2, e2);
  }
  poly1.display(1);
  poly2.display(2);
  Poly poly3 = poly1.addPoly(poly2);
  cout << "The sum of the polynomials is\n";
  poly3.display(3);
  return 0;
}