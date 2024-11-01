#include <bits/stdc++.h>
using namespace std;
class Helpers
{
private:
    /* data */
public:
    Helpers(/* args */);
    ~Helpers();
    /**
     * @brief Prints elements of an integer vector to the console, separated by spaces.
     *
     * @param arr Reference to a vector of integers.
     *
     * @example
     *     vector<int> vec = {1, 2, 3};
     *     printArray(vec); // Output: 1 2 3
     */
     void printArray(vector<int> &arr)
    {
        for (const auto el : arr)
        {
            cout << el << " ";
        }
    }
};

Helpers::Helpers(/* args */)
{
}

Helpers::~Helpers()
{
}
