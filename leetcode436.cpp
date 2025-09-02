#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals)
    {
        int n = (int) intervals.size();
        vector<vector<int>> startings;

        for (int i = 0; i < n; i++)
        {
            startings.push_back({intervals[i][0], i});
        }

        sort(startings.begin(), startings.end());

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++)
        {
            int val = intervals[i][1];
            auto it = lower_bound(startings.begin(), startings.end(), val);

            if (it != startings.end())
            {
                int idx = it - startings.begin();
                ans[i] = startings[idx][1];
            }
        }

        return ans;

        
    }
};

int main()
{

}