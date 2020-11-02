#include <iostream>
#include <climits>

#define ZERO 0

int main()
{
    using namespace std;
    short sam = SHRT_MAX;
    unsigned short sue = sam;
    cout << "Sam has " << sam << "dollars and Sue has " << sue << "dollars deposited." << endl;
    cout << "Add $1 to each account." << endl;
    sam = sam + 1;
    sue = sue + 1;
    cout << "Now Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Poor Sam!" << endl;

    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << "dollars and Sue has " << sue << "dollars deposited." << endl;
    cout << "Take $1 from each account." << endl;
    sam = sam - 1;
    sue = sue - 1;
    cout << "Now Sam has " << sam << " dollars and Sue has " << sue << " dollars deposited." << endl;
    cout << "Lucky Sue!" << endl;
    return 0;
}