#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;
const int OO = 10000000;

void add_undirected_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
	graph[to].push_back(from);
}

vector<int> BFS_V1(GRAPH &graph, int start)
{
    vector<int> len(graph.size(), OO);
    queue<int> q;
    q.push(start);
    len[start] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        int level = len[cur];
        q.pop();
        for (int neighbour : graph[cur])
        {

            if (len[neighbour] == OO)
            {
                q.push(neighbour);
                len[neighbour] = level + 1;
            }
        }
    }

    return len;
}