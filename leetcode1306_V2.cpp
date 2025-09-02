#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


class Solution
{

private:
    bool process(vector<int> &arr, vector<bool> &visited, queue<int> &q, int x)
    {
        int n = arr.size();
        if (x < 0 || x >= n || visited[x]) return false;
        if (arr[x] == 0) return true;
        visited[x] = true;
        q.push(x);
        return false;
    }

public:

    bool canReach(vector<int>& arr, int start)
    {
        if (arr[start] == 0) return true;
        int n = arr.size();
        vector<bool> visited(n);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        for (int sz = 1; !q.empty(); sz = q.size())
        {
            while (sz--)
            {
                int x = q.front();
                q.pop();
                if (process(arr, visited, q, x + arr[x]) || process(arr, visited, q, x - arr[x]))
                {
                    return true;
                }
            }
        }

        return false;
    }
};