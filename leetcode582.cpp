#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef unordered_map<int, vector<int>> GRAPH;

class Solution
{
private:

void add(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

void build_graph(GRAPH &graph, vector<int> &pid, vector<int> &ppid)
{
    for (int i = 0; i < pid.size(); i++)
    {
        add(graph, ppid[i], pid[i]);
    }
}

void dfs(GRAPH &graph, unordered_set<int> &visited, int node)
{
    visited.insert(node);

    for (int i : graph[node])
    {
        if (!visited.count(i))
        {
            dfs(graph, visited, i);
        }
    }
}

vector<int> reachability(GRAPH &graph, int kill)
{
    unordered_set<int> visited;
    dfs(graph, visited, kill);
    return vector<int>(visited.begin(), visited.end());    
}





public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        GRAPH graph;
        build_graph(graph, pid, ppid);
        return reachability(graph, kill);
    }    
};


/*
void add(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

void build_graph(GRAPH &graph, vector<int> &pid, vector<int> &ppid)
{
    for (int i = 0; i < ppid.size(); i++)
    {
        add(graph, ppid[i], pid[i]);
    }
}

void dfs(GRAPH &graph, unordered_set<int> &visited, int kill)
{
    visited.insert(kill);

    for (int i : graph[kill])
    {
        if(!visited.count(i))
        {
            dfs(graph, visited, i);
        }
    }
}

vector<int> reachability(GRAPH &graph, int kill)
{
    unordered_set<int> visited;
    dfs(graph, visited, kill);
    return vector<int>(visited.begin(), visited.end());
}
*/