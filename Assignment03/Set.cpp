#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

// Doing the set containing only integers
// BST Approach
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

public:
  void inorder(Node *t)
  {
    if (t == NULL)
    {
      return;
    }
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
  }

  // Uniqueness

  int present(Node *head, int d)
  {
    if (head == NULL)
    {
      return 0;
    }
    int x = head->data == d ? 1 : 0;
    return x | present(head->left, d) | present(head->right, d);
  }

  Node *insert(Node *head, int d)
  {
    if (head == NULL)
    {
      Node *temp = new Node;
      temp->data = d;
      temp->left = temp->right = NULL;
      return temp;
    }
    if (d < head->data)
    {
      head->left = insert(head->left, d);
      return head;
    }
    else if (d > head->data)
    {
      head->right = insert(head->right, d);
      return head;
    }
    else
    {
      return head;
    }
  }
} Node;

class Set
{
private:
  Node *root;
  int size;

public:
  Set();                        // default constructor
  Set(int);                     // Parameterised Constructor
  Set(const Set &);             // Copy Constructor
  ~Set();                       // Destructor
  void add(const int);          // Adding elements to the set
  bool contains(int);           // Checking for element in set
  Set unionSet(Set &);          // Union of sets
  Set intersectionSet(Set &);   // Intersection of Sets
  Set complementSet(Set &);     // Complement of set
  Set operator-(Set &);         // Set Difference
  bool operator==(Set &);       // Check for equality of sets
  int *setToArray();            // Gives an array of the set elements
  void cartesianProduct(Set &); // Cartesian Product of Sets
  void displayPowerSet();       // Power set of a set
  void display();               // Display the set
  double mean();                // Mean
  double median();              // Median
  double variance();            // Variance
  double standardDeviation();   // Standard Deviation
};

Set::Set()
{
  root = NULL;
  size = 0;
}

Set::Set(int cap)
{
  root = NULL;
  size = cap;
}

Set::Set(const Set &S)
{
  root = S.root;
  size = S.size;
}

Set::~Set()
{
  delete root;
}

void Set::add(const int data) // The data must be set to const otherwise compiler throws lvalue to rvalue ref. error
{
  if (!root->present(root, data))
  {
    root = root->insert(root, data);
    size++;
  }
}

bool Set::contains(int data)
{
  return root->present(root, data) ? true : false;
}

Set Set::unionSet(Set &S)
{
  Set res;
  if (root == NULL)
  {
    return S;
  }
  if (S.root == NULL)
  {
    return *this;
  }
  stack<Node *> nodeStack;
  nodeStack.push(this->root);
  while (!nodeStack.empty())
  {
    Node *node;
    node = nodeStack.top();
    nodeStack.pop();
    res.add(node->data);

    if (node->right)
    {
      nodeStack.push(node->right);
    }
    if (node->left)
    {
      nodeStack.push(node->left);
    }
  }
  stack<Node *> nodeStack2;
  nodeStack2.push(S.root);
  while (!nodeStack2.empty())
  {
    Node *node;
    node = nodeStack2.top();
    nodeStack2.pop();
    res.add(node->data);
    if (node->left)
    {
      nodeStack2.push(node->left);
    }
    if (node->right)
    {
      nodeStack2.push(node->right);
    }
  }
  return res;
}

Set Set::intersectionSet(Set &S)
{
  Set res;
  stack<Node *> nodeStack;
  nodeStack.push(root);
  while (!nodeStack.empty())
  {
    Node *node;
    node = nodeStack.top();
    nodeStack.pop();
    if (S.contains(node->data))
    {
      res.add(node->data);
    }
    if (node->right)
    {
      nodeStack.push(node->right);
    }
    if (node->left)
    {
      nodeStack.push(node->left);
    }
  }
  return res;
}

Set Set::complementSet(Set &U)
{
  return (U - *this);
}

Set Set::operator-(Set &S)
{
  Set res;
  stack<Node *> nodeStack;
  nodeStack.push(this->root);
  while (!nodeStack.empty())
  {
    Node *node;
    node = nodeStack.top();
    nodeStack.pop();
    if (!S.contains(node->data))
    {
      res.add(node->data);
    }
    if (node->right)
    {
      nodeStack.push(node->right);
    }
    if (node->left)
    {
      nodeStack.push(node->left);
    }
  }
  return res;
}

bool Set::operator==(Set &S)
{
  if (this->size != S.size)
  {
    return false;
  }
  stack<Node *> nodeStack;
  nodeStack.push(this->root);
  while (!nodeStack.empty())
  {
    Node *node;
    node = nodeStack.top();
    nodeStack.pop();
    if (!S.contains(node->data))
    {
      return false;
    }
    if (node->right)
    {
      nodeStack.push(node->right);
    }
    if (node->left)
    {
      nodeStack.push(node->left);
    }
  }
  return true;
}

int *Set::setToArray()
{
  int *a = new int[size];
  int i = 0;
  stack<Node *> nodeStack;
  nodeStack.push(this->root);
  while (!nodeStack.empty())
  {
    Node *node;
    node = nodeStack.top();
    nodeStack.pop();
    a[i++] = node->data;
    if (node->right)
    {
      nodeStack.push(node->right);
    }
    if (node->left)
    {
      nodeStack.push(node->left);
    }
  }
  return a;
}

void Set::cartesianProduct(Set &S)
{
  int i, j, n = S.size;
  int *a = this->setToArray();
  int *b = S.setToArray();
  i = 0;
  cout << "The Cartesian product is:\n";
  cout << "{ ";
  for (i = 0; i < this->size; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "(" << a[i] << "," << b[j] << ") ";
    }
  }
  cout << "}\n";
}

void Set::displayPowerSet()
{
  int n = 1 << (this->size);
  int *a = this->setToArray();
  int i;
  while (n--)
  {
    cout << "{ ";
    for (int i = 0; i < this->size; i++)
    {
      // Backtracking the elements
      if ((n & (1 << i)) == 0)
      {
        cout << a[i] << " ";
      }
    }
    cout << "}\n";
  }
}

void Set::display()
{
  int *a = this->setToArray();
  cout << "{ ";
  for (int i = 0; i < this->size; i++)
  {
    cout << a[i] << " ";
  }
  cout << "}\n";
}

double Set::mean()
{
  double sum = 0;
  int *a = this->setToArray();
  for (int i = 0; i < this->size; i++)
  {
    sum += a[i];
  }
  double ans = sum / (this->size);
  return ans;
}

double Set::median()
{
  int *a = this->setToArray();
  sort(a, a + this->size);
  if ((this->size) & 1)
  {
    return a[this->size / 2];
  }
  else
  {
    double res = 0.5 * ((double)a[this->size / 2] + (double)a[this->size / 2 - 1]);
    return res;
  }
}

double Set::variance()
{
  int *a = this->setToArray();
  double m = this->mean();
  double sum = 0;
  for (int i = 0; i < this->size; i++)
  {
    sum += (a[i] * a[i]);
  }
  double ren = sum / this->size;
  return ren - m * m;
}

double Set::standardDeviation()
{
  return sqrt(this->variance());
}

int main()
{
  cout << "\t\tSet Implementation\n";
  cout << "Enter the total number of elements in the Universal Set\n";
  int cap;
  cin >> cap;
  cout << "The Universal Set will consist of integers from 0 to " << cap - 1 << "\n";
  Set U;
  for (int i = 0; i < cap; i++)
  {
    U.add(i);
  }
  cout << "For Set 1\n";
  Set S1;
  cout << "Enter the elements to be added in the Set 1, enter -1 to stop the process\n";
  while (1)
  {
    int d;
    cin >> d;
    if (d >= cap)
    {
      cout << "Not Possible\n";
      exit(0);
    }
    if (d == -1)
    {
      break;
    }
    S1.add(d);
  }
  cout << "For Set 2\n";
  Set S2;
  cout << "Enter the elements to be added in the Set 2, enter -1 to stop the process\n";
  while (1)
  {
    int d;
    cin >> d;
    if (d >= cap)
    {
      cout << "Not Possible\n";
      exit(0);
    }
    if (d == -1)
    {
      break;
    }
    S2.add(d);
  }
  cout << "Set S1 is:\n";
  S1.display();
  cout << "The Complement of Set S1 is:\n";
  Set S11 = S1.complementSet(U);
  S11.display();
  cout << "Set S2 is:\n";
  S2.display();
  cout << "The complement of Set S2 is:\n";
  Set S22 = S2.complementSet(U);
  S22.display();
  cout << "The Union of the Sets is:\n";
  Set Uni = S1.unionSet(S2);
  Uni.display();
  cout << "The Intersection of the Sets is:\n";
  Set Inter = S1.intersectionSet(S2);
  Inter.display();
  cout << "The Set Difference S1-S2 is:\n";
  Set S1_2 = S1 - S2;
  S1_2.display();
  cout << "The Set Difference S2-S1 is:\n";
  Set S2_1 = S2 - S1;
  S2_1.display();
  if (S1 == S2)
  {
    cout << "The Sets S1 and S2 are equal\n";
  }
  else
  {
    cout << "The Sets S1 and S2 are not equal\n";
  }
  cout << "The Cartesian product of Set S1 and S2 (S1xS2) is:\n";
  S1.cartesianProduct(S2);
  cout << "The Cartesian product of Set S1 and S2 (S2xS1) is:\n";
  S2.cartesianProduct(S1);
  cout << "The Power Set of Set S1 is:\n";
  S1.displayPowerSet();
  cout << "The Power Set of Set S2 is:\n";
  S2.displayPowerSet();
  cout << "Set by definition of our BST implementation will be distinct\n";
  cout << fixed << setprecision(5);
  cout << "The mean of Set S1 is:\n"
       << S1.mean() << "\n";
  cout << "The median of Set S1 is:\n"
       << S1.median() << "\n";
  cout << "The variance of Set S1 is:\n"
       << S1.variance() << "\n";
  cout << "The Standard Deviation of Set S1 is:\n"
       << S1.standardDeviation() << "\n";
  cout << "The mean of Set S2 is:\n"
       << S2.mean() << "\n";
  cout << "The median of Set S2 is:\n"
       << S2.median() << "\n";
  cout << "The variance of Set S2 is:\n"
       << S2.variance() << "\n";
  cout << "The Standard Deviation of Set S2 is:\n"
       << S2.standardDeviation() << "\n";
  return 0;
}