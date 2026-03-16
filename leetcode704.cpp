#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target)
            {
                left = mid+1;
            }
            else right = mid-1;
        }

        return -1;
    } 
};

int main()
{
    vector<int> nums = {1,2,3,5,6,7};

    Solution s;

    cout << s.search(nums, 1) << endl;
    
    return 0;
}