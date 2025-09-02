#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
private:
    bool possible(int x, int y)
    {
        if (pow(y, 2) <= x) return true;
        return false;
    }
public:
    int mySqrt(int x)
    {
        int start = 0, end = 1e9;
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(x, mid))
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