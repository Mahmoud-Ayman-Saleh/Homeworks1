#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 10000000;  // A big value expressing infinity

void add_undirected_edge(GRAPH &graph, int from, int to) 
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool bfs_cycle(GRAPH &adjList, int start, vector<int> &len, vector<int> &parent) 
{
    queue<int> q;
    q.push(start);
    len[start] = 0;

    for (int level = 0, sz = 1; !q.empty(); ++level, sz = q.size())
    {
        while (sz--)
        {
            int cur = q.front();
            q.pop();

            for (int neighbour : adjList[cur])
            {
                if (neighbour == parent[cur])
                    continue;  // fake cycle

                if (len[neighbour] == OO)  // never visited
                {
                    q.push(neighbour);
                    len[neighbour] = level + 1;
                    parent[neighbour] = cur;
                } 
                else
                {
                    return true;  // cycle detected
                }
            }
        }
    }
    return false;
}

bool has_cycle(GRAPH &graph) 
{
    int nodes = graph.size();
    vector<int> len(nodes, OO);
    vector<int> parent(nodes, -1);  // to detect fake cycles

    for (int i = 0; i < nodes; ++i)  // handle separate CCs
    {
        
        if (i > 0 && len[i] == OO) return true; // beccause if the graph is 1 component this loops happen one time because node(0) reaches to all

        if (len[i] == OO && bfs_cycle(graph, i, len, parent))
            return true;
    }
    return false;
}

class Solution 
{
public:
    bool validTree(int nodes, vector<vector<int>> &edges) 
    {
        if ((int)edges.size() != nodes - 1)
            return false;  // tree must have n-1 edges. Otherwise, it has a cycle or is disconnected

        GRAPH graph(nodes);

        for (auto &edge : edges)
            add_undirected_edge(graph, edge[0], edge[1]);

        return !has_cycle(graph);
    }
};

