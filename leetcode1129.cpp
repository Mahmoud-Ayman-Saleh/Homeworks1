#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int OO = 1000000;
const int RED = 0;
const int BLUE = 1;

struct edge
{
    int to;
    int color;
};

typedef vector<vector<edge>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int color)
{
	graph[from].push_back( { to, color });
}


vector<int> bfs(GRAPH &graph, int start)
{
    int n = graph.size();
    vector<int> ans(n, -1);
    queue<edge> q;
    vector<vector<int>> len(n, vector<int> (2, OO));
    q.push({start, RED});
    q.push({start, BLUE});
    len[start][RED] = len[start][BLUE] = 0;
    ans[start] = 0;
    int x = 0;

    for (int sz = q.size(), level = 0; !q.empty(); level++, sz = q.size())
    {
        while (sz--)
        {
            int cur = q.front().to, color = q.front().color;
            q.pop();
            for (edge &e : graph[cur])
            {
                if (color != e.color && len[e.to][e.color] == OO)
                {
                    q.push(e);
                    len[e.to][e.color] = level+1;
                    if (ans[e.to] == -1)
                    {
                        ans[e.to] = level+1;
                        if (++x == ans.size()) return ans;
                    }
                }
            }
        }
    }

    return ans;
}



class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)
    {
        GRAPH graph(n);

        for (auto &p : redEdges)
        {
            add_directed_edge(graph, p[0], p[1], RED);
        }

        for (auto &p : blueEdges)
        {
            add_directed_edge(graph, p[0], p[1], BLUE);
        }

        return bfs(graph, 0);
    }
};
