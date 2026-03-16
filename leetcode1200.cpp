#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>
using namespace std;


class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mn = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            mn = min(mn, arr[i+1]-arr[i]);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i+1] - arr[i] == mn)
            {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    Solution s;
    vector<vector<int>> ans = s.minimumAbsDifference(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}