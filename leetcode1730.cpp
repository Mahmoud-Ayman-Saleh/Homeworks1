#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int OO = 2147483647;	// A big value expressing infinity

// Delta for: up, right, down, left
int dr[4] { -1, 0, 1, 0 };
int dc[4] { 0, 1, 0, -1 };

bool isvalid(int r, int c, vector<vector<char>> &matrix)
{
	if (r < 0 || r >= (int) matrix.size())
		return false;
	if (c < 0 || c >= (int) matrix[0].size())
		return false;
	return true;
}

struct cell
{
	int r, c;
};

class Solution
{
private:

    int bfs(vector<vector<char>>& matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        queue<cell> q;
        bool flag = false;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '*')
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    flag = true;
                }
            }

            if (flag) break;
        }

        for (int levels = 0, sz = 1; !q.empty(); sz = q.size(), levels++)
        {
            while (sz--)
            {
                int r = q.front().r, c = q.front().c;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nr = dr[i] + r, nc = dc[i] + c;

                    if (!isvalid(nr, nc, matrix) || visited[nr][nc] || matrix[nr][nc] == 'X') continue;

                    if (matrix[nr][nc] == '#') return levels+1;

                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        return -1;
    }
public:
    int getFood(vector<vector<char>>& G)
    {
        return bfs(G);
    }
};

int main()
{
    Solution solution;

    vector<vector<char>> grid1 =
    {
        {'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', '*', 'O', 'O', 'O', 'X'},
        {'X', 'O', 'O', '#', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X'}
    };

    vector<vector<char>> grid2 =
    {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', '*', 'X', 'O', 'X'},
        {'X', 'O', 'X', '#', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    };

    vector<vector<char>> grid3 =
    {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'},
        {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
    };

    cout << "Example 1: " << solution.getFood(grid1) << endl;  // Output: 3
    cout << "Example 2: " << solution.getFood(grid2) << endl;  // Output: -1
    cout << "Example 3: " << solution.getFood(grid3) << endl;  // Output: 6

    return 0;
}