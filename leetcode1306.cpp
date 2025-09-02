#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 10000000;


class Solution
{
private:
    bool is_valid(vector<int> &arr, int x)
    {
        return x >= 0 && x < arr.size();
    }

    void add(GRAPH &graph, int from, int to)
    {
        graph[from].push_back(to);
    }

    void build(GRAPH &graph, vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (is_valid(arr, arr[i] + i))
            {
                add(graph, i, arr[i] + i);
            }

            if (is_valid(arr, i - arr[i]))
            {
                add(graph, i, i - arr[i]);
            }
        }
    }

    bool bfs(GRAPH &graph, int start, vector<int> &arr)
    {
        vector<int> len(graph.size(), OO);
        queue<int> q;
        q.push(start);
        len[start] = 0;

        for (int level = 0, sz = 1; !q.empty(); level++, sz = q.size())
        {
            while (sz--)
            {
                int cur = q.front();
                q.pop();
                if (arr[cur] == 0) return true;
                for (int neighbour : graph[cur])
                {
                    if (len[neighbour] == OO)
                    {
                        q.push(neighbour);
                        len[neighbour] = level + 1;
                    }
                }
            }
            
        }

        return false;
    }
public:
    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        GRAPH graph(n);
        build(graph, arr);

        return bfs(graph, start, arr); 
    }
    
};