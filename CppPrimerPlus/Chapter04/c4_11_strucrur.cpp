#include <iostream>

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

struct st1
{
    int a : 4;
    //float b : 4; // error: bit-field 'b' with non-integral type
    bool c : 1;
    char d[5];
};

struct st2
{
    int a;
    bool c;
    char d[5];
};

int main()
{
    using namespace std;
    inflatable guest = 
    {
        "Glorius Gloria",
        1.88,
        29.99
    };
    inflatable pal = 
    {
        "Audacious Arthur",
        3.12,
        32.99
    };
    cout <<"Expand your guest list with " << guest.name << " and " << pal.name << "!\n";
    cout << "You can have both for $" << guest.price + pal.price << "!\n";

    st1 s1;
    st2 s2;
    cout << "sizeof s1 " << sizeof(s1) << endl;
    cout << "sizeof s2 " << sizeof(s2) << endl;

    return 0;
}