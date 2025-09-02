#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;
typedef vector<vector<int>> GRAPH;
const int OO = 1e8;

class Solution
{
private:

    void add(GRAPH &graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);

    }

    bool bfs_cycle(GRAPH &graph, int start, vector<int> &visited, vector<int> &parent)
    {
        queue<int> q;
        q.push(start);
        visited[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int i : graph[node])
            {

                if (parent[node] == i) continue;

                if (visited[i] == OO)
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = node;
                }

                else
                {
                    return true;
                }
            }
        }

        return false;
        
    }


    bool has_cycle(GRAPH &graph)
    {
        int nodes = graph.size();
        vector<int> visited(nodes, OO);
        vector<int> parent(nodes, -1);

        for (int i = 0; i < nodes; i++)
        {
            if (i > 0 && visited[i] == OO) return true;
            if (visited[i] == OO && bfs_cycle(graph, i, visited, parent)) return true;
        }
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (n - 1 != edges.size()) return false;

        GRAPH graph(n);
        for (auto &edge : edges)
        {
            add(graph, edge[0], edge[1]);
        }

        return !has_cycle(graph);

    }
};
    
    