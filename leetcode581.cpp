#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> sorted_arr = nums;
        sort(sorted_arr.begin(), sorted_arr.end());

        int right = n - 1;
        int left = 0;

        while (nums[right] == sorted_arr[right] && right > left)
        {
            right--;
        }

        while (nums[left] == sorted_arr[left] && right > left)
        {
            left++;
        }

        if (left == right) return 0;
        return right-left+1;

    }

     int findUnsortedSubarray2(vector<int>& nums)
     {
        int mx_sofar = INT_MIN, mn_sofar = INT_MAX;
        int left = -1, right = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            mx_sofar = max(nums[i], mx_sofar);
            if (nums[i] < mx_sofar)
            {
                right = i;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            mn_sofar = min(nums[i], mn_sofar);
            if (nums[i] > mn_sofar)
            {
                left = i;
            }
        }

        if (right == -1) return 0;
        return right - left + 1;
     }
};

int main()
{
    vector<int> nums = {1};
    Solution s;
    cout << s.findUnsortedSubarray(nums) << endl;


}