#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <set>

using namespace std;

class Solution
{
private:
    int ceil(int x, int y)
    {
        return (x + y - 1) / y;
    }

    int possible(vector<int>& nums, int div)
    {
        int sum = 0;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            sum += ceil(nums[i], div);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int start = 1, end = *max_element(nums.begin(), nums.end());
        int ans = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(nums, mid) <= threshold)
            {
                end = mid - 1;
                ans = mid;
            }
            else
            {
                start = mid+1;
            }
        }

        return ans;
    }
};

int main()
{
    set<int> s;
}