#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        int ans = 0;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-2; i++)
        {
            int k = i + 2;
            if (nums[i] == 0) continue; // skip if there is a 0 because there is no triangle has 0
            for (int j = i+1; j < n-1; j++)
            {
                int first_idx = n; // because maybe the whole array can make a triangle with the two numbers
                auto it = lower_bound(nums.begin() + k, nums.end(), nums[i]+nums[j]);
                if (it != nums.end())
                {
                    first_idx = it - nums.begin();
                }
                ans += first_idx - j - 1;
            }
        }

        return ans;
    }
};