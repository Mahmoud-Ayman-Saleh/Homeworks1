#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
}


int topsort(const GRAPH &adjList)
{
    int sz = adjList.size();
    vector<int> indegree(sz, 0);

    for (int i = 0; i < sz; i++)
    {
        for (int j : adjList[i])
        {
            indegree[j]++;
        }
    }

    queue<int> ready;

    for (int i = 0; i < sz; i++)
    {
        if (indegree[i] == 0)
        {
            ready.push(i);
        }
    }

    int levels = 0;
    int nodes = 0;
    while (!ready.empty())
    {
        int level_size = ready.size();
        while (level_size--)
        {
            int i = ready.front();
            ready.pop();
            nodes++;

            for (int j : adjList[i])
            {
                if (--indegree[j] == 0) ready.push(j);
            }
        }

        levels++;
        
    }

    if (nodes != adjList.size())
    {
        return -1;
    }

    return levels;
}
