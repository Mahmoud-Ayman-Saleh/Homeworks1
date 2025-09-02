#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge
{
    int from, to, cost;
    edge(int from, int to, int cost)
    {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }

    bool operator < (const edge &e) const
    {
        return cost < e.cost;
    }

    void print()
    {
        cout<<"Edge ("<<from<<" "<<to<<" "<<cost<<")\n";
    }
};

typedef vector<edge> GRAPH;

void add(GRAPH &graph, int from, int to, int cost)
{
    edge eg(from, to, cost);
    graph.push_back(eg);
}

void print(GRAPH &graph)
{
    int edges = (int) graph.size();

    for (int i = 0; i < edges; i++)
    {
        graph[i].print();
    }
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	GRAPH graph;

	for (int e = 0; e < edges; ++e)
    {
		int from, to, cost;
		cin >> from >> to >> cost;
		add(graph, from, to, cost);
	}
	sort(graph.begin(), graph.end());
	print(graph);
	return 0;
}
