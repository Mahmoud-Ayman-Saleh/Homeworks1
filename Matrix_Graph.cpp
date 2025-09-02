#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_direct(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = cost;
}


void add_undirect(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to] = cost;
    graph[to][from] = cost;
}

void print_graph(GRAPH &graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] > 0)
            {
                cout << "From " << i << " to " << j
				<< " the cost is " << graph[i][j] << "\n";
            }
        }
    }
}

int main()
{
    int nodes, edges; cin >> nodes >> edges;
    GRAPH graph(nodes, vector<int> (edges));
}
