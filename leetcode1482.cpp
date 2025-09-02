// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
using namespace std;

/*
 * If waiting D days gives us at least X bouquets
 * Then waiting D+1 days also gives us at least X bouquets
 * Hence monotonic increasing function
 *
 * Then just binary search on the days
 *
 * possible() is direct
 * 	Given days, find groups of consecutive flowers that bloom. We need m of them
 */

class Solution
{
private:
    bool possible(vector<int>& bloomDay, int total_bouquets, int flowers_per_bouquet, int waiting_days)
    {
        int adj_flowers = 0, bouquets = 0;
        for (int i = 0; i < (int) bloomDay.size(); i++)
        {
            if (bloomDay[i] <= waiting_days)
            {
                adj_flowers++;
                
                if (adj_flowers >= flowers_per_bouquet)
                {
                    bouquets++;
                    adj_flowers = 0;
                }

                if (bouquets == total_bouquets)
                {
                    return true;
                }
            }
            else
            {
                adj_flowers = 0;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        

        int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(bloomDay, m, k, mid))
            {
                ans =  mid;
                end = mid-1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};