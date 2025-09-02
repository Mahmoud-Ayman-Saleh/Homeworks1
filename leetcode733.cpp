#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution
{
private:
    bool is_valid(int r, int c, vector<vector<int>> &matrix)
    {
        if (r < 0 || r >= matrix.size()) return false;
        if (c < 0 || c >= matrix[0].size()) return false;
        return true;
    }


    void dfs(int r, int c, vector<vector<int>> &image, vector<vector<bool>> &visited, int oldColor, int newColor)
    {
        if (!is_valid(r, c, image) || visited[r][c] || image[r][c] != oldColor) return;

        visited[r][c] = true;
        image[r][c] = newColor;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            dfs(dr[i] + r, dc[i] + c, image, visited, oldColor, newColor);
        }
    }



public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
        dfs(sr, sc, image, visited, image[sr][sc], color);
        return image;
    }
};

