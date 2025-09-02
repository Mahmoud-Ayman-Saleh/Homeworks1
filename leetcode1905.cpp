#include<iostream>
#include<vector>
using namespace std;



class Solution
{
private:
    bool is_sub_island;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(int r, int c, vector<vector<int>> &matrix)
    {
        if (r < 0 || r >= matrix.size()) return false;
        if (c < 0 || c >= matrix[0].size()) return false;
        return true;
    }

    void dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>> &visited)
    {
        if (!is_valid(r, c, grid2) || grid2[r][c] == 0 || visited[r][c]) return;
        if (grid2[r][c] == 1 && grid1[r][c] == 0)
        {
            is_sub_island = false;
            return;
        }
        
        visited[r][c] = true;

        for (int i = 0; i < 4; i++)
        {
            dfs(dr[i] + r, dc[i] + c, grid1, grid2, visited);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int rows = grid1.size();
        int cols = grid1[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols));
        int ans = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid2[i][j] == 1 && !visited[i][j])
                {
                    is_sub_island = true;
                    dfs(i, j, grid1, grid2, visited);
                    if (is_sub_island) ans++;
                }
            }
        }

        return ans;
    }
};

