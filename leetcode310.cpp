#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
    graph[to].push_back(from);
}

vector<int> solve(GRAPH &graph)
{
    int n = graph.size();
    if (n == 1) return {0};
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            indegree[graph[i][j]]++;
        }
    }

    queue<int> ready;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 1)
        {
            ready.push(i);
        }
    }

    while (n > 2)
    {
        int leaf_nodes = ready.size();
        n = n - leaf_nodes;
        while (leaf_nodes--)
        {
            int i = ready.front();
            ready.pop();

            for (int j : graph[i])
            {
                if (--indegree[j] == 1)
                {
                    ready.push(j);
                }
            }
        }
    }

    vector<int> ans;
    while(!ready.empty())
    {
        ans.push_back(ready.front());
        ready.pop();
    }

    return ans;
}

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        GRAPH graph(n);
        for (auto &p : edges)
        {
            add_undirected_edge(graph, p[0], p[1]);
        }

        return solve(graph);
    }
};


int main()
{
    Solution solution;
    
    // Example 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> result1 = solution.findMinHeightTrees(n1, edges1);
    cout << "Example 1 Output: ";
    for (int node : result1)
    {
        cout << node << " ";
    }
    cout << endl;

    // Example 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> result2 = solution.findMinHeightTrees(n2, edges2);
    cout << "Example 2 Output: ";
    for (int node : result2)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
