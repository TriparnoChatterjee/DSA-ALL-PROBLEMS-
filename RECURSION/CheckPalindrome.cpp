#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkPlaindrome(string s, int i, int j)
    {
        if (i >= j)
            return true;
        if ((!isalpha(s[i]) && !isdigit(s[i])) || s[i] == ' ')
            return checkPlaindrome(s, i + 1, j);
        if ((!isalpha(s[j]) && !isdigit(s[j])) || s[j] == ' ')
            return checkPlaindrome(s, i, j - 1);
        if (tolower(s[i]) != tolower(s[j]))
            return false;

        return checkPlaindrome(s, i + 1, j - 1);
    }
};
int main()
{
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    if (s.checkPlaindrome(str, 0, str.length() - 1))
        cout << "yes";
    else
        cout << "no";
    return 0;
}
/*
- This will give memory error in Leetcode 
- can be done in a normal way but we are focusing on recursion
- this check the presence of all punctutations and digits

 */