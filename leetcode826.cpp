#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        int n = difficulty.size();
        vector<pair<int, int>> job;
        for (int i = 0; i < n; ++i)
        {
            job.push_back({difficulty[i], profit[i]});
        }
        
        // Sort jobs by difficulty
        sort(job.begin(), job.end());
        
        // Preprocess to ensure we have maximum profit for each difficulty level
        for (int i = 1; i < job.size(); i++) {
            job[i].second = max(job[i].second, job[i-1].second);
        }

        int ans = 0;

        for (int i = 0; i < worker.size(); i++)
        {
            int maxProfit = 0;
            for (int j = 0; j < job.size(); j++)
            {
                if (job[j].first <= worker[i])
                {
                    maxProfit = job[j].second;
                }
                else
                {
                    break; // Since jobs are sorted, no need to check further
                }
            }
            ans += maxProfit;
        }
        return ans;
    }
};
