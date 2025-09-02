#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef vector<unordered_set<int>> GRAPH;

void add_edge(int from, int to, GRAPH &graph)
{
    graph[from].insert(to);
}

void print_graph(GRAPH &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "Node " << i << " has neighbors: ";
        for (int j : graph[i])
        {
            cout << j << " ";
        }

        cout << "\n";
    }
}
