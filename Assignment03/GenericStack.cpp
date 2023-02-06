#include <iostream>
using namespace std;

#define CAPACITY 20

typedef struct complex
{
  double real;
  double img;
} complex;

template <class T>
class MyStack
{
private:
  T *data;
  int top;
  int capacity;
  int size;

public:
  MyStack();
  MyStack(int);
  MyStack(MyStack &);
  ~MyStack();

  bool isFull();
  void Push(T);
  void Pop(T *, int *);
  int MaxSize();
  bool isEmpty();
  int CurrentSize();
  void Display(int, T);
  void display(int, complex);
};

template <class T>
MyStack<T>::MyStack()
{
  data = new T[CAPACITY];
  capacity = CAPACITY;
  size = 0;
  top = -1;
}

template <class T>
MyStack<T>::MyStack(int cap)
{
  data = new T[cap];
  capacity = cap;
  size = 0;
  top = -1;
}

template <class T>
MyStack<T>::MyStack(MyStack<T> &S)
{
  capacity = S.capacity;
  size = S.size;
  top = S.top;
  for (int i = 0; i < size; i++)
  {
    data[i] = S.data[i];
  }
}

template <class T>
MyStack<T>::~MyStack()
{
  delete[] data;
}

template <class T>
bool MyStack<T>::isFull()
{
  return (size == capacity);
}

template <class T>
bool MyStack<T>::isEmpty()
{
  return size == 0;
}

template <class T>
void MyStack<T>::Push(T a)
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

template <class T>
void MyStack<T>::Pop(T *a, int *flag)
{
  if (isEmpty())
  {
    *flag = 0;
    cout << "Stack is empty no element can be popped\n";
    return;
  }
  else
  {
    *flag = 1;
    size--;
    *a = data[top--];
    return;
  }
}
template <class T>
int MyStack<T>::MaxSize()
{
  return capacity;
}

template <class T>
int MyStack<T>::CurrentSize()
{
  return size;
}

template <class T>
void MyStack<T>::Display(int ch, T a)
{
  cout << "The Stack " << ch << " is:\n";
  for (int i = 0; i < size; i++)
  {
    cout << data[i] << "  ";
  }
  cout << "\n";
}

template <class T>
void MyStack<T>::display(int ch, complex a)
{
  cout << "The Stack " << ch << " is:\n";
  for (int i = 0; i < size; i++)
  {
    cout << data[i].real << "+" << data[i].img << "i"
         << "  ";
  }
  cout << "\n";
}

int main()
{
  int a;
  short b;
  float c;
  double d;
  complex e;
  cout << "\t\t\tStack Functionalities\n";
  cout << "Enter\n 0.Integer Stack\n 1.Short Stack\n 2.Float Stack\n 3.Double Stack\n 4.Complex stack\n";
  int choice;
  cin >> choice;
  if (choice == 0)
  {
    MyStack<int> S1;
    MyStack<int> S2(10);
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
        int m, f;
        S1.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S1.Display(1, a);
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
        int m, f;
        S2.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S2.Display(2, a);
      }
      else
      {
        cout << "Wrong choice\n";
      }
    }
    cout << "Demonstrating Copy Constructor\n";
    MyStack<int> S3 = S1;
    S3.Display(3, a);
    S2 = S1;
    S2.Display(2, a);
  }
  else if (choice == 1)
  {
    MyStack<short> S1;
    MyStack<short> S2(10);
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
        short d;
        cin >> d;
        S1.Push(d);
      }
      else if (d == 2)
      {
        short m;
        int f;
        S1.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S1.Display(1, b);
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
        short d;
        cin >> d;
        S2.Push(d);
      }
      else if (d == 2)
      {
        short m;
        int f;
        S2.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S2.Display(2, b);
      }
      else
      {
        cout << "Wrong choice\n";
      }
    }
    cout << "Demonstrating Copy Constructor\n";
    MyStack<short> S3 = S1;
    S3.Display(3, b);
    S2 = S1;
    S2.Display(2, b);
  }
  else if (choice == 2)
  {
    MyStack<float> S1;
    MyStack<float> S2(10);
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
        float d;
        cin >> d;
        S1.Push(d);
      }
      else if (d == 2)
      {
        float m;
        int f;
        S1.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S1.Display(1, c);
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
        float d;
        cin >> d;
        S2.Push(d);
      }
      else if (d == 2)
      {
        float m;
        int f;
        S2.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S2.Display(2, c);
      }
      else
      {
        cout << "Wrong choice\n";
      }
    }
    cout << "Demonstrating Copy Constructor\n";
    MyStack<float> S3 = S1;
    S3.Display(3, c);
    S2 = S1;
    S2.Display(2, c);
  }
  else if (choice == 3)
  {
    MyStack<double> S1;
    MyStack<double> S2(10);
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
        double d;
        cin >> d;
        S1.Push(d);
      }
      else if (d == 2)
      {
        double m;
        int f;
        S1.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S1.Display(1, d);
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
        double d;
        cin >> d;
        S2.Push(d);
      }
      else if (d == 2)
      {
        double m;
        int f;
        S2.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m << "\n";
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
        S2.Display(2, d);
      }
      else
      {
        cout << "Wrong choice\n";
      }
    }
    cout << "Demonstrating Copy Constructor\n";
    MyStack<double> S3 = S1;
    S3.Display(3, d);
    S2 = S1;
    S2.Display(2, d);
  }
  else if (choice == 4)
  {
    MyStack<complex> S1;
    MyStack<complex> S2(10);
    MyStack<complex> S3;
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
        complex cm;
        cout << "Enter the real part\n";
        double r;
        cin >> r;
        cout << "Enter the imaginary part\n";
        double i;
        cin >> i;
        cm.real = r;
        cm.img = i;
        S1.Push(cm);
      }
      else if (d == 2)
      {
        complex m;
        int f;
        S1.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m.real << "+" << m.img << "i "
               << "\n";
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
        S1.display(1, e);
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
        complex cm;
        cout << "Enter the real part\n";
        double r;
        cin >> r;
        cout << "Enter the imaginary part\n";
        double i;
        cin >> i;
        cm.real = r;
        cm.img = i;
        S2.Push(cm);
      }
      else if (d == 2)
      {
        complex m;
        int f;
        S2.Pop(&m, &f);
        if (f)
          cout << "The popped element is " << m.real << "+" << m.img << "i "
               << "\n";
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
        S2.display(2, e);
      }
      else
      {
        cout << "Wrong choice\n";
      }
    }
    cout << "Demonstrating Copy Constructor\n";
    S3 = S1;
    S3.display(3, e);
    S2 = S1;
    S2.display(2, e);
  }
  else
  {
    cout << "Wrong Choice\n";
  }
  return 0;
}