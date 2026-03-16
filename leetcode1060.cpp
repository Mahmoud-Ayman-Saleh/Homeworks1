#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution
{
private:
    int missing(int idx, vector<int> &nums)
    {
        return nums[idx] - nums[0] - idx;
    }
public:
    int missingElementBruteForce(vector<int>& nums, int k)
    {
        vector<int> ans;
        ans.push_back(0);
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = nums[i]+1; j < nums[i+1]; j++)
            {
                ans.push_back(j);
            }
        }
        int temp = nums[n-1];
        int t = k;

        while (t--)
        {
            ans.push_back(++temp);
        }

        return ans[k];
    }

    int missingElement(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > missing(n-1, nums))
        {
            return nums[n-1] + (k - missing(n-1, nums));
        }

        int left = 0, right = n-1, mid;

        while (left <= right)
        {
            mid = left + (right-left)/2;

            if (missing(mid, nums) < k) left = mid+1;
            else right = mid;
        }

        return nums[left-1]+k-missing(left-1,nums);
        
    }
};

int main()
{
    vector<int> nums = {1,2,4};
    int k = 3;
    Solution s;
    cout << s.missingElement(nums,k) << endl;
}