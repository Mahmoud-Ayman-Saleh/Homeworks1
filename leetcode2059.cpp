#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution
{
private:
    bool process(vector<int> &nums, vector<bool> &visited, queue<int> &q, int x, int goal)
    {
        if (x < 0 || x > 1000 || visited[x]) return false;

        visited[x] = true;
        
        for (int i = 0; i < nums.size(); i++)
        {
            int op1 = x + nums[i];
            int op2 = x - nums[i];
            int op3 = x ^ nums[i];
            
            if (op1 == goal || op2 == goal || op3 == goal)
            {
                return true;
            }
            
            if (op1 >= 0 && op1 <= 1000 && !visited[op1]) {
                q.push(op1);
            }

            if (op2 >= 0 && op2 <= 1000 && !visited[op2]) {
                q.push(op2);
            }

            if (op3 >= 0 && op3 <= 1000 && !visited[op3]) {
                q.push(op3);
            }
        }

        
        return false;
    }
public:
    int minimumOperations(vector<int>& nums, int start, int goal)
    {
        if (start == goal) return 0;
        vector<bool> visited(1001);
        queue<int> q;
        q.push(start);

        int levels = 0;

        while (!q.empty())
        {
            int sz = q.size();
            levels++;
            while (sz--)
            {
                int x = q.front();
                q.pop();

                if (process(nums, visited, q, x, goal))
                {
                    return levels;
                }
            }
        }

        return -1;
    }
};