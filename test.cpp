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
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        if (m*k > bloomDay.size()) return -1;
        int flowers = m * k;

        sort(bloomDay.begin(), bloomDay.end());

        int left = 0, right = bloomDay.size() - 1;
        int ans = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (mid+1 >= flowers)
            {
                right = mid-1;
                ans = bloomDay[mid];
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
};


int main()
{
    vector<int> arr = {7,7,7,7,12,7,7};
    int m = 2, k = 3;
    Solution s;
    cout << s.minDays(arr,m,k) << endl;
}

