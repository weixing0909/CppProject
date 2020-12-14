#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time &t) const;
    void Show() const;
};

Time::Time()
{
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes = minutes % 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const 
{
    std::cout << hours << " hours, " << minutes << " minutes\n";
}

int main()
{
    using namespace std;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    cout << "total time = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "morefixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
    return 0;
}