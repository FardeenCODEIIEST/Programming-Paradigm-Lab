#include <iostream>
using namespace std;

#define CAPACITY 20
class MyStack
{
private:
  int *data;
  int top;
  int capacity;
  int size;

public:
  MyStack();
  MyStack(int);
  MyStack(MyStack &);
  ~MyStack();

  bool isFull();
  void Push(int);
  int Pop();
  int MaxSize();
  bool isEmpty();
  int CurrentSize();
  void Display(int);
};

MyStack::MyStack()
{
  data = new int[CAPACITY];
  capacity = CAPACITY;
  size = 0;
  top = -1;
}

MyStack::MyStack(int cap)
{
  data = new int[cap];
  capacity = cap;
  size = 0;
  top = -1;
}

MyStack::MyStack(MyStack &S)
{
  capacity = S.capacity;
  size = S.size;
  top = S.top;
  for (int i = 0; i < size; i++)
  {
    data[i] = S.data[i];
  }
}

MyStack::~MyStack()
{
  delete[] data;
}

bool MyStack::isFull()
{
  return (size == capacity);
}

bool MyStack::isEmpty()
{
  return size == 0;
}

void MyStack::Push(int a)
{
  if (isFull())
  {
    cout << "Stack is full element cannot be pushed\n";
  }
  else
  {
    data[++top] = a;
    size++;
    cout << "Element has been inserted successfully\n";
  }
}

int MyStack::Pop()
{
  if (isEmpty())
  {
    cout << "Stack is empty no element can be popped\n";
    return -1;
  }
  else
  {
    size--;
    return data[top--];
  }
}

int MyStack::MaxSize()
{
  return capacity;
}

int MyStack::CurrentSize()
{
  return size;
}

void MyStack::Display(int ch)
{
  cout << "The Stack " << ch << " is:\n";
  for (int i = 0; i < size; i++)
  {
    cout << data[i] << " ";
  }
  cout << "\n";
}

int main()
{
  cout << "\t\t\tStack Functionalities\n";
  MyStack S1;
  MyStack S2(10);
  cout << "\tFor Stack 1\n";
  while (1)
  {
    cout << "Enter\n 0.To Terminate\n 1.Push elements\n 2.Pop elements\n 3.Get MaxSize\n 4.Get CurrentSize\n 5.Check for emptyness\n 6.Display the stack\n";
    int d;
    cin >> d;
    if (d == 0)
    {
      break;
    }
    else if (d == 1)
    {
      cout << "Enter the element\n";
      int d;
      cin >> d;
      S1.Push(d);
    }
    else if (d == 2)
    {
      cout << "The popped element is " << S1.Pop() << "\n";
    }
    else if (d == 3)
    {
      cout << "The MaxSize of the Stack " << S1.MaxSize() << "\n";
    }
    else if (d == 4)
    {
      cout << "The CurrentSize of the Stack " << S1.CurrentSize() << "\n";
    }
    else if (d == 5)
    {
      if (S1.isEmpty())
      {
        cout << "The Stack is Empty\n";
      }
      else
      {
        cout << "The Stack is not empty\n";
      }
    }
    else if (d == 6)
    {
      S1.Display(1);
    }
    else
    {
      cout << "Wrong choice\n";
    }
  }
  cout << "\tFor Stack 2\n";
  while (1)
  {
    cout << "Enter\n 0.To Terminate\n 1.Push elements\n 2.Pop elements\n 3.Get MaxSize\n 4.Get CurrentSize\n 5.Check for emptyness\n 6.Display the stack\n";
    int d;
    cin >> d;
    if (d == 0)
    {
      break;
    }
    else if (d == 1)
    {
      cout << "Enter the element\n";
      int d;
      cin >> d;
      S2.Push(d);
    }
    else if (d == 2)
    {
      cout << "The popped element is " << S2.Pop() << "\n";
    }
    else if (d == 3)
    {
      cout << "The MaxSize of the Stack " << S2.MaxSize() << "\n";
    }
    else if (d == 4)
    {
      cout << "The CurrentSize of the Stack " << S2.CurrentSize() << "\n";
    }
    else if (d == 5)
    {
      if (S2.isEmpty())
      {
        cout << "The Stack is Empty\n";
      }
      else
      {
        cout << "The Stack is not empty\n";
      }
    }
    else if (d == 6)
    {
      S2.Display(2);
    }
    else
    {
      cout << "Wrong choice\n";
    }
  }
  cout << "Demonstrating Copy Constructor\n";
  MyStack S3 = S1;
  S3.Display(3);
  S2 = S1;
  S2.Display(2);
  return 0;
}