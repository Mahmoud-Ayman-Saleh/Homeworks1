#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
	graph[from].push_back(to);
}




vector<int> topsort(GRAPH &adjList)
{
    int sz = adjList.size();
    vector<int> indegree(sz, 0);
    vector<int> ans;

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

    while (!ready.empty())
    {
        int i = ready.front();
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


class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        GRAPH graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            add_directed_edge(graph, prerequisites[i][1], prerequisites[i][0]);
        }
        vector<int> ans = topsort(graph);
        return ans.size() == numCourses;
    }
};

int main()
{
    Solution solution;

    // Test Case 1: Simple case with no cycles
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << (solution.canFinish(numCourses1, prerequisites1) ? "True" : "False") << endl;
    // Expected Output: True

    // Test Case 2: Simple cycle case
    int numCourses2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << (solution.canFinish(numCourses2, prerequisites2) ? "True" : "False") << endl;
    // Expected Output: False

    // Test Case 3: Larger acyclic graph
    int numCourses3 = 4;
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << (solution.canFinish(numCourses3, prerequisites3) ? "True" : "False") << endl;
    // Expected Output: True

    // Test Case 4: Larger graph with a cycle
    int numCourses4 = 4;
    vector<vector<int>> prerequisites4 = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};
    cout << (solution.canFinish(numCourses4, prerequisites4) ? "True" : "False") << endl;
    // Expected Output: False

    // Test Case 5: No prerequisites, all courses can be taken independently
    int numCourses5 = 3;
    vector<vector<int>> prerequisites5 = {};
    cout << (solution.canFinish(numCourses5, prerequisites5) ? "True" : "False") << endl;
    // Expected Output: True

    // Test Case 6: Single course, no prerequisites
    int numCourses6 = 1;
    vector<vector<int>> prerequisites6 = {};
    cout << (solution.canFinish(numCourses6, prerequisites6) ? "True" : "False") << endl;
    // Expected Output: True

    // Test Case 7: Complex acyclic graph
    int numCourses7 = 5;
    vector<vector<int>> prerequisites7 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}, {4, 3}};
    cout << (solution.canFinish(numCourses7, prerequisites7) ? "True" : "False") << endl;
    // Expected Output: True

    return 0;
}