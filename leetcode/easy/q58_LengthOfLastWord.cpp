#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1, sum = 0;
        while(s[i] == ' ') 
        {
            i--;
        }
        while(i-- >= 0) 
        {
            if(s[i] == ' ') return sum; else sum++;
            //i--;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    int length;
    string str = "Hello World";
    length = s.lengthOfLastWord(str);
    cout << "length = " << length << endl;
    return 0;
}