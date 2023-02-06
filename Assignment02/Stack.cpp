#include <iostream>
#include <set>
#include <stdlib.h>

using namespace std;

typedef struct MyStack
{
  int top;
  int *data;
  int size;
  int capacity;
} MyStack;

MyStack Initialise(int capacity)
{
  MyStack st;
  st.top = -1;
  st.capacity = capacity;
  st.size = 0;
  st.data = (int *)malloc(sizeof(int) * capacity);
  return st;
}

inline bool isFull(MyStack &st)
{
  return (st.size == st.capacity);
}

inline bool isEmpty(MyStack &st)
{
  return (st.size == 0);
}

int Push(MyStack &st, int d)
{
  if (isFull(st))
  {
    return 0;
  }
  else
  {
    st.data[++(st.top)] = d;
    st.size++;
    return 1;
  }
}

int Pop(MyStack &st, int *flag)
{
  if (isEmpty(st))
  {
    *flag = 0;
    return 0;
  }
  else
  {
    *flag = 1;
    st.size--;
    return (st.data[(st.top)--]);
  }
}

inline int GetMaxSize(MyStack &st)
{
  return st.capacity;
}

inline int CurrentSize(MyStack &st)
{
  return st.size;
}

inline void displayStack(MyStack &st)
{
  for (int i = st.size - 1; i >= 0; i--)
  {
    cout << st.data[i] << "\n";
  }
}
int main()
{
  cout << "\t\t\t Stack Functionalities in CPP\t\t\n";
  MyStack st1;
  MyStack st2;
  cout << "Enter the capacity of the first stack\n";
  int cap1, cap2;
  cin >> cap1;
  cout << "Enter the capacity of the second stack\n";
  cin >> cap2;
  st1 = Initialise(cap1);
  st2 = Initialise(cap2);
  cout << "Perform Basic Stack Functionalities\n";
  while (1)
  {
    cout << "Enter\n 0.To Terminate the process\n 1.Push element into the stack\n 2.Pop element from the stack\n 3.Get max Size of the stack\n 4.Get current size of the stack\n 5.Check for emptyness of the stack\n 6.Display Stack\n Further Enter\n a.For the First Stack\n b.For the Second Stack\n";
    int c;
    cin >> c;
    if (c == 0)
    {
      break;
    }
    else if (c == 1)
    {
      char ch;
      cin >> ch;
      int d;
      if (ch == 'a')
      {
        cout << "Enter the element to be pushed into the first stack\n";
        cin >> d;
        if (Push(st1, d) == 1)
        {
          cout << "Element has been pushed into the stack\n";
        }
        else
        {
          cout << "Stack is full cannot push element\n";
        }
      }
      else if (ch == 'b')
      {
        cout << "Enter the element to be pushed into the second stack\n";
        cin >> d;
        if (Push(st2, d) == 1)
        {
          cout << "Element has been pushed into the stack\n";
        }
        else
        {
          cout << "Stack is full cannot push element\n";
        }
      }
      else
      {
        cout << "Wrong Choice\n";
        continue;
      }
    }
    else if (c == 2)
    {
      char ch;
      cin >> ch;
      if (ch == 'a')
      {
        int p, flag;
        p = Pop(st1, &flag);
        if (flag)
        {
          cout << "Popped Element is " << p << "\n";
        }
        else
        {
          cout << "Stack1 is empty cannot pop elements\n";
        }
      }
      else if (ch == 'b')
      {
        int p, flag;
        p = Pop(st2, &flag);
        if (flag)
        {
          cout << "Popped Element is " << p << "\n";
        }
        else
        {
          cout << "Stack2 is empty cannot pop elements\n";
        }
      }
      else
      {
        cout << "Wrong Choice\n";
      }
    }
    else if (c == 3)
    {
      char ch;
      cin >> ch;
      if (ch == 'a')
      {
        cout << "Maximum Size of Stack 1 is " << GetMaxSize(st1) << "\n";
      }
      else if (ch == 'b')
      {
        cout << "Maximum Size of Stack 2 is " << GetMaxSize(st2) << "\n";
      }
      else
      {
        cout << "Wrong Choice\n";
      }
    }
    else if (c == 4)
    {
      char ch;
      cin >> ch;
      if (ch == 'a')
      {
        cout << "Current size of the Stack 1 is " << CurrentSize(st1) << "\n";
      }
      else if (ch == 'b')
      {
        cout << "Current size of the Stack 2 is " << CurrentSize(st2) << "\n";
      }
      else
      {
        cout << "Wrong Choice\n";
      }
    }
    else if (c == 5)
    {
      char ch;
      cin >> ch;
      if (ch == 'a')
      {
        if (isEmpty(st1))
        {
          cout << "Stack 1 is empty\n";
        }
        else
        {
          cout << "Stack 1 is not empty\n";
        }
      }
      else if (ch == 'b')
      {
        if (isEmpty(st2))
        {
          cout << "Stack 2 is empty\n";
        }
        else
        {
          cout << "Stack 2 is not empty\n";
        }
      }
      else
      {
        cout << "Wrong Choce\n";
      }
    }
    else if (c == 6)
    {
      char ch;
      cin >> ch;
      if (ch == 'a')
      {
        cout << "Stack 1:\n";
        displayStack(st1);
      }
      else if (ch == 'b')
      {
        cout << "Stack 2:\n";
        displayStack(st2);
      }
      else
      {
        cout << "Wrong Choice\n";
      }
    }
    else
    {
      cout << "Wrong Choice\n";
    }
  }
  return 0;
}