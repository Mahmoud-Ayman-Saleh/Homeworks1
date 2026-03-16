#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        const int SHIFT = 50000; // that's because count sort doesn't work for negative numbers
        for (int i = 0; i < nums.size(); i++) nums[i] += SHIFT;
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[mx])
            {
                mx = i;
            }
        }
        int max_element = nums[mx];

        vector<int> freq(max_element+1);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        int idx = 0;
        for (int i = 0; i < freq.size(); i++)
        {
            for (int j = 0; j < freq[i]; j++)
            {
                nums[idx] = i - SHIFT;
                idx++;
            }
        }

        return nums;
    }
};