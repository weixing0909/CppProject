#include <iostream>

int main()
{
    using namespace std;
    cout << "The Amazing Acconuto will sum and average five numbers for you\n";;
    cout << "Please enter five values\n";
    double number;
    double sum;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }
    cout << "Five exquisite choices indeed!" << endl;
    cout << "They sum to " << sum << endl;
    cout << "and average to " << sum / 5 << ".\n";
    cout << "The Amazing Accounto bids you adieu!\n";
    return 0;
}