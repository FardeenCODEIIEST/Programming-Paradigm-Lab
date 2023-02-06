#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
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
  Set(Set &);                   // Copy Constructor
  ~Set();                       // Destructor
  void add(int);                // Adding elements to the set
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
  float mean();                 // Mean
  float median();               // Median
  float variance();             // Variance
  float standardDeviation();    // Standard Deviation
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

Set::Set(Set &S)
{
  root = S.root;
  size = S.size;
}

Set::~Set()
{
  delete root;
}

void Set::add(int data)
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
      if ((n & (i << i)) == 0)
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

float Set::mean()
{
  int sum = 0;
  int *a = this->setToArray();
  for (int i = 0; i < this->size; i++)
  {
    sum += a[i];
  }
  float ans = sum / this->size;
  return ans;
}

float Set::median()
{
  int *a = this->setToArray();
  sort(a, a + this->size);
  if ((this->size) & 1)
  {
    return a[this->size / 2];
  }
  else
  {
    float res = 0.5 * (a[this->size / 2] + a[this->size / 2 - 1]);
    return res;
  }
}

float Set::variance()
{
  int *a = this->setToArray();
  float m = this->mean();
  int sum = 0;
  for (int i = 0; i < this->size; i++)
  {
    sum += (a[i] * a[i]);
  }
  float ren = sum / this->size;
  return ren - m * m;
}

float Set::standardDeviation()
{
  return sqrt(this->variance());
}
