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
	bool is_closed_island;


    bool is_valid(int r, int c, vector<vector<int>> &matrix)
    {
        if (r < 0 || r >= matrix.size()) return false;
        if (c < 0 || c >= matrix[0].size()) return false;
        return true;
    }

    bool is_zero_boundry(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        if (!visited[r][c] && grid[r][c] == 0 && (r == 0 || r == grid.size() -1 || c == 0 || c == grid[0].size() -1))
        {
            return true;
        }
        return false;
    }

    bool is_water(int r, int c, vector<vector<int>> &grid)
    {
        return grid[r][c] == 1;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>> &visited)
    {
        if (!is_valid(r, c, grid) || is_water(r,c, grid) || visited[r][c]) return;

        if (is_zero_boundry(r, c, grid, visited))
        {
            is_closed_island = false;
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
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
                {
                    is_closed_island = true;
                    dfs(i, j, grid, visited);
                    if (is_closed_island) ans++;
                }

                
            }
        }
        return ans;
    }
};

