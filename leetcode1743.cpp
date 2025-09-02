#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef unordered_map<int, vector<int>> GRAPH;

class Solution
{
private:

    void add(GRAPH &graph, int from, int to)
    {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    void build_graph(GRAPH &graph, vector<vector<int>> &adjacentPairs)
    {
        for (auto &pair : adjacentPairs)
        {
            add(graph, pair[0], pair[1]);
        }
    }

    void dfs(GRAPH &graph, unordered_set<int> &visited, vector<int> &ans, int node)
    {
        visited.insert(node);
        ans.push_back(node);

        for (int i : graph[node])
        {
            if (!visited.count(i))
            {
                dfs(graph, visited, ans, i);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        GRAPH graph;
        build_graph(graph, adjacentPairs);

        vector<int> ans;
        unordered_set<int> visited;

        for (auto &node_adj : graph)
        {
            if (node_adj.second.size() == 1)
            {
                dfs(graph, visited, ans, node_adj.first);
                break;
            }
        }

        return ans;
    }
};

