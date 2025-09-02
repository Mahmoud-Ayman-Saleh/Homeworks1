#include<iostream>
#include<vector>
using namespace std;

struct edge
{
    int to, cost;
};

typedef vector<vector<edge>> GRAPH;

void add_direct(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
}

void add_undirect(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
}

void print_graph(GRAPH &graph)
{
    int n = graph.size();

    for (int i = 0; i < n; i++)
    {
        if (!graph[i].empty())
        {
            cout << "Node " << i << " has neighbors: ";
            for (int j = 0; j < graph[i].size(); j++)
            {
                cout << graph[i][j].to << " and the cost is " << graph[i][j].cost << " ";
            }
        }

        else
        {
            cout << "This node " << i << " has no neighbors\n";
        }
        cout << endl;
    }
}

int main()
{
    int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph(nodes);	// observe: empty lists

	for (int e = 0; e < edges; ++e) {
		int from, to, cost;
		cin >> from >> to >> cost;
		add_direct(graph, from, to, cost);
	}
	print_graph(graph);
}


