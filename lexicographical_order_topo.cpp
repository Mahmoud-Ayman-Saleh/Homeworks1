#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
}


vector<int> topsort(const GRAPH &adjList)
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

    priority_queue<int> ready;

    for (int i = 0; i < sz; i++)
    {
        if (indegree[i] == 0)
        {
            ready.push(i);
        }
    }

    vector<int> ans;

    while (!ready.empty())
    {
        int i = ready.top();
        ready.pop();
        ans.push_back(i);

        for (int j : adjList[i])
        {
            if (--indegree[j] == 0) ready.push(j);
        }
    }

    if (ans.size() != adjList.size())
    {
        ans.clear();
    }

    return ans;
}


int main() {
	// freopen("data.txt", "rt", stdin);
	int cases;
	cin >> cases;

	while (cases--) {
		int nodes, edges;
		cin >> nodes >> edges;

		GRAPH graph(nodes);

		for (int e = 0; e < edges; ++e) {
			int from, to;
			cin >> from >> to;
			add_directed_edge(graph, from, to);
		}
		vector<int> ordering = topsort(graph);

		if (ordering.empty())
			cout << "There is a cycle\n";
		else {
			for (int node : ordering)
				cout << node << " ";
			cout << "\n";
		}
	}
	return 0;
}