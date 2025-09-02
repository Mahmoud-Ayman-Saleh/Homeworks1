#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution
{
private:
    int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };
	bool is_touched_boundry;


    bool is_valid(int r, int c, vector<vector<int>> &matrix)
    {
        if (r < 0 || r >= matrix.size()) return false;
        if (c < 0 || c >= matrix[0].size()) return false;
        return true;
    }

    bool is_grid_boundry(int r, int c, vector<vector<int>>& grid)
    {
        if (r == 0 || r == grid.size() - 1) return true;
        if (c == 0 || c == grid[0].size() - 1) return true;
        return false;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>> &visited)
    {
        if (!is_valid(r, c, grid) || grid[r][c] == 1 || visited[r][c]) return;
        if (is_grid_boundry(r, c, grid))
        {
            is_touched_boundry = true;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++)
        {
            dfs(dr[i] + r, dc[i] + c, grid, visited);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size()));
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
                {
                    is_touched_boundry = false;
                    dfs(i, j, grid, visited);
                    if (!is_touched_boundry)
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

