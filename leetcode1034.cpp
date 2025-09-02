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

    bool is_valid(int r, int c, vector<vector<int>> &matrix)
    {
        return r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size();
    }

    bool is_border(int r, int c, vector<vector<int>>& grid, int x)
    {
        // Check if the cell is on the boundary of the grid or has a neighbor with a different color
        if (r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1)
            return true;
        
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (!is_valid(nr, nc, grid) || grid[nr][nc] != x)
                return true;
        }

        return false;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>> &visited, int x, int color)
    {
        if (!is_valid(r, c, grid) || grid[r][c] != x || visited[r][c]) return;

        visited[r][c] = true;

        bool border = is_border(r, c, grid, x);

        for (int i = 0; i < 4; i++)
        {
            dfs(r + dr[i], c + dc[i], grid, visited, x, color);
        }

        if (border)
        {
            grid[r][c] = color;
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int x = grid[row][col];
        dfs(row, col, grid, visited, x, color);

        return grid;
    }
};
