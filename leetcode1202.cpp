#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


typedef vector<vector<int>> GRAPH;

void add_undirected_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
	graph[to].push_back(from);
}

// Coding tip: Keep your functions standard for reusability
void dfs(GRAPH &graph, int node, vector<bool> &visited, vector<int> &cc_nodes)
{
	visited[node] = true;
	cc_nodes.push_back(node);

	for (int neighbour : graph[node])
    {
		if (!visited[neighbour])
			dfs(graph, neighbour, visited, cc_nodes);
	}
}

class Solution {
public:

	string smallestStringWithSwaps(string str, vector<vector<int>> &pairs)
    {
		int nodes = str.size();
		GRAPH graph(nodes);

		// Build graph edges
		for (int i = 0; i < (int) pairs.size(); ++i)
			add_undirected_edge(graph, pairs[i][0], pairs[i][1]);

		vector<bool> visited(nodes);

		// Without sorting, total O(E+V). Be careful to not get TLE
		for (int i = 0; i < nodes; i++)
        {
            if (!visited[i])
            {
                vector<int> cc_nodes;
                dfs(graph, i, visited, cc_nodes);

                string cc_letters;
                for (int j = 0; j < cc_nodes.size(); j++)
                {
                    cc_letters += str[cc_nodes[j]];
                }

                sort(cc_nodes.begin(), cc_nodes.end());
                sort(cc_letters.begin(), cc_letters.end());

                for (int j = 0; j < cc_nodes.size(); j++)
                {
                    str[cc_nodes[j]] = cc_letters[j];
                }
            }
        }
		return str;
	}
};
