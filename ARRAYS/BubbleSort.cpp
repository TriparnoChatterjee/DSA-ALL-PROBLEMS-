#include <bits/stdc++.h>
#include "../helpers.h"
using namespace std;
class Solution
{
public:
    void sort(vector<int> &arr)
    {
        int n = arr.size();
        for(int i = 0 ; i<n;i++){
            for(int j = 0; j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int>arr = {5,2,3,1,4};
    s.sort(arr);
    Helpers h;
    h.printArray(arr);
    return 0;
}