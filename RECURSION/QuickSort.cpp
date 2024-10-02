#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int getPartitionIndex(vector<int>&arr,int low,int high){
        int pivotIndex=low;
        int pivot = arr[low];
        while(low<=high){
            if(arr[low]<=pivot){
                low++;
            }
            else{
               //search for the first lower element from right 
               while(low<=high){
                if(arr[high]<arr[low])
                    break;
                else
                    high--;
               }
               swap(arr[low],arr[high]);
            }
        }
        swap(arr[pivotIndex],arr[high-1]);
    }
    void quickSort(vector<int>&arr,int low, int high){
        if(low>high)
            return;
        while(low<=high){
            int k = getPartitionIndex(arr,low,high);
            quickSort(arr,low,k-1);
            quickSort(arr,k+1,high);
        }
    }
};
int main()
{
    Solution s;
    vector<int>arr= {2,3,5,1,4};
    s.quickSort(arr,0,arr.size());
    for(const auto el : arr)    cout<<el<<" ";
    return 0;
}