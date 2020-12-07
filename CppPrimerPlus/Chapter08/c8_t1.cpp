#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>
void f1(T a)
{
    cout << typeid(a).name() << endl;
    cout << a << endl;
}

template <class T>
void f1(T *a)
{
    cout << typeid(a).name() << endl;
    cout << a << endl << endl;
}

template <class T>
void f3(T *a[], int n)
{
    for(int i = 0; i < 3; i++) cout << *a[i] << endl;
    *a[0] +=  10;
}

int main()
{
    int a = 10;
    f1(a);
    f1(&a);

    double arr[] = {1.0, 2.0, 3.0};
    double *p[] = {arr, arr + 1, arr + 2};
    f3(p, 3);
    for(int i = 0; i < 3; i++) cout << *p[i] << endl;

    cout << "\n";

    double x = 1.0;
    decltype(x) y = x;
    decltype((x)) z = x;

    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    y = 2.0;
    z = 3.0;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}