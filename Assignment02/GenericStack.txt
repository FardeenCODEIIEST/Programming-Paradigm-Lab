#include <iostream>
using namespace std;

struct Complex
{
    double real;
    double imaginary;
};

template <typename T>
struct Stack
{
    int top;
    int cap;
    T *p;
};

typedef Stack<int> intStack;
typedef Stack<short> shortStack;
typedef Stack<float> floatStack;
typedef Stack<double> doubleStack;
typedef Stack<Complex> complexStack;

template <typename T>
Stack<T> createStack(int n, T flag)
{
    Stack<T> s;
    s.top = -1;
    s.cap = n;
    s.p = new T[n];
    return s;
}

template <typename T>
void freeStack(T *s)
{
    s->top = -1;
    s->cap = -1;
    delete[] s->p;
}

template <typename T>
bool isStackFull(T *s)
{
    if (s->top == s->cap - 1)
        return 1;
    return 0;
}

template <typename T>
bool isStackEmpty(T *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

template <typename T>
void maxSize(T *s)
{
    cout << "\nCapacity: " << s->cap << '\n';
}

template <typename T>
void currentSize(T *s)
{
    cout << "\nCurrent size: " << s->top + 1 << '\n';
}

template <typename T, typename U>
void pushStack(T *s, U p)
{
    if (isStackFull(s))
    {
        printf("\nStack is already full!!\n");
        return;
    }
    s->top++;
    s->p[s->top] = p;
}

template <typename T>
void popStack(T *s)
{
    if (isStackEmpty(s))
    {
        cout << "\nNothing to pop!!\n";
        return;
    }
    cout << "\nPopped value: " << s->p[s->top] << '\n';
    s->top--;
}

void popStack(complexStack *s)
{
    if (isStackEmpty(s))
    {
        cout << "\nNothing to pop!!\n";
        return;
    }
    Complex c = s->p[s->top];
    cout << '(' << c.real << ") + (" << c.imaginary << "j )"
         << "\n";
    s->top--;
}

template <typename T>
void display(T *s)
{
    if (isStackEmpty(s))
    {
        cout << "\nNothing to display!!\n\n";
        return;
    }
    int n = s->top;
    cout << '\n';
    for (int i = 0; i <= n; i++)
        cout << s->p[i] << ' ';
    cout << "\n";
}

void display(complexStack *s)
{
    if (isStackEmpty(s))
    {
        cout << "\nNothing to display!!\n";
        return;
    }
    int n = s->top;
    cout << '\n';
    for (int i = 0; i <= n; i++)
    {
        cout << '(' << s->p[i].real << ") + (" << s->p[i].imaginary << ")j\n";
    }
}

template <typename T, typename t>
void loop(int op, t p, T *s, bool *flag)
{
    cout << "Your response: ";
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "\nEnter the element you want to push: ";
        cin >> p;
        pushStack(s, p);
        break;
    case 2:
        popStack(s);
        break;
    case 3:
        maxSize(s);
        break;
    case 4:
        currentSize(s);
        break;
    case 0:
        *flag = false;
        break;
    case 5:
        display(s);
        break;
    default:
        *flag = false;
    }
}

void loop(int op, Complex p, complexStack *s, bool *flag)
{
    cout << "Your response: ";
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "\nEnter the real part: ";
        cin >> p.real;
        cout << "Enter the complex part: ";
        cin >> p.imaginary;
        pushStack(s, p);
        break;
    case 2:
        popStack(s);
        break;
    case 3:
        maxSize(s);
        break;
    case 4:
        currentSize(s);
        break;
    case 0:
        *flag = false;
        break;
    case 5:
        display(s);
        break;
    default:
        *flag = false;
    }
}

int i;
short s;
float f;
double d;
Complex c;

int main()
{
    int n, typ = 1;
    string tmp1 = "\nEnter 1: Integer stack\nEnter 2: Short stack\nEnter 3: Float stack\nEnter 4: Double stack\nEnter 5: Struct (complex number) stack\n\n";
    cout << tmp1 << "Your response: ";
    cin >> typ;
    cout << "\nEnter the size of your Stack: ";
    cin >> n;
    intStack is;
    shortStack ss;
    floatStack fs;
    doubleStack ds;
    complexStack cs;

    switch (typ)
    {
    case 1:
        is = createStack(n, n);
        break;
    case 2:
        ss = createStack(n, s);
        break;
    case 3:
        fs = createStack(n, f);
        break;
    case 4:
        ds = createStack(n, d);
        break;
    case 5:
        cs = createStack(n, c);
        break;
    default:
        is = createStack(n, n);
    }

    string tmp = "\nEnter 1: To push\nEnter 2: To pop\nEnter 3: Capacity\nEnter 4: Current size\nEnter 5: Display the Stack\nEnter 0: Exit\n\n";
    int op, p;
    bool flag = true;
    while (flag)
    {
        cout << tmp;
        if (typ == 1)
            loop<intStack, int>(op, i, &is, &flag);
        else if (typ == 2)
            loop<shortStack, short>(op, i, &ss, &flag);
        else if (typ == 3)
            loop<floatStack, float>(op, f, &fs, &flag);
        else if (typ == 4)
            loop<doubleStack, double>(op, d, &ds, &flag);
        else
            loop(op, c, &cs, &flag);
    }

    freeStack(&is);
    freeStack(&ss);
    freeStack(&fs);
    freeStack(&ds);
    freeStack(&cs);

    return 0;
}