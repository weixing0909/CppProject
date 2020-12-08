#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++)
        {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 10; i++)
    {
        cout << i << ", " << s.climbStairs(i) << endl;
    }
    return 0;
}