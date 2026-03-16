#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution
{
private:

    bool possible(vector<int>& houses, vector<int>& heaters, int r)
    {
        int j = 0;
        for (int i = 0; i < heaters.size(); i++)
        {
            int left = heaters[i] - r, right = heaters[i] + r;

            while (j < houses.size() && left <= houses[j] && right >= houses[j]) j++;
        }
        return j == houses.size();
    }
public:

    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int start = 0, end = 1e9, r = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(houses, heaters, mid))
            {
                end = mid - 1;
                r = mid;
            }
            else start = mid + 1;
        }
        return r;
        
    }
};
