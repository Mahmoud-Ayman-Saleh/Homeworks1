#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef vector<vector<int>> GRAPH;

class Solution
{
private:

void add(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void build_graph(GRAPH &graph, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        add(graph, edges[i][0], edges[i][1]);
    }
}

void dfs(GRAPH &graph, vector<bool> &visited, int node)
{
    visited[node] = true;
    for (int i : graph[node])
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
        }
    }

}


public:
    int countComponents(int nodes, vector<vector<int>> &edges)
    {
        GRAPH graph(nodes);
        build_graph(graph, edges);
        vector<bool> visited(nodes);
        int count = 0;
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(graph, visited, i);
            }
        }

        return count;
    }    
};