#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<stack>
using namespace std;

class Solution
{
private:


int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};


bool is_valid(int r, int c, vector<vector<char>> &grid)
{
    if (r >= grid.size() || r < 0) return false;
    if (c >= grid[0].size() || c < 0) return false;

    return true;
}
bool dfs(int r, int c, int pr, int pc, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    visited[r][c] = true;

    for (int i = 0; i < 4; i++)
    {
        int nr = dr[i] + r;
        int nc = dc[i] + c;

        if (!is_valid(nr,nc, grid)) continue;
        if (grid[nr][nc] != grid[r][c]) continue;;

        if (nr == pr && nc == pc) continue; // you visit the parent again

        if (visited[nr][nc]) return true; // detect the cycle

        if (dfs(nr, nc, r, c, grid, visited)) return true;
    }

    return false;
}

public:
    bool containsCycle(vector<vector<char>>& grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j])
                {
                    if (dfs(i,j,-1,-1, grid, visited))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;

    vector<vector<char>> g1 = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    cout << (s.containsCycle(g1) ? "true" : "false") << "\n"; // true

    vector<vector<char>> g2 = {{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}};
    cout << (s.containsCycle(g2) ? "true" : "false") << "\n"; // true

    vector<vector<char>> g3 = {{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    cout << (s.containsCycle(g3) ? "true" : "false") << "\n"; // false

}