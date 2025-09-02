#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

class Solution
{
private:
    bool possible(int n, long long row)
    {
        long long sum = (row *(row+1)) / 2;
        return n >= sum;
    }
public:
    int arrangeCoins(int n)
    {
        int start = 0, end = n;
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(n, mid))
            {
                start = mid + 1;
                ans = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans; 
    }
};