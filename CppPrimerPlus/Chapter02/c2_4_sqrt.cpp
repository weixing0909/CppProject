#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    
    double area;
    cout << "Enter the floor area, in sqyare feet, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side
         << " feet to the side." << endl;
    cout << "How fancinating!" << endl;
    return 0;
}