#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


class Solution
{
public:
    int largestPerimeter(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            {
                ans = max(ans, nums[i] + nums[i+1] + nums[i+2]);
            }
        }    

        return ans;
    }
};

int main()
{
    
    return 0;
}