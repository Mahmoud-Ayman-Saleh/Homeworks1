#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution
{
private:
    int possible(int x, int m, int n)
    {
        int total = 0;
        for (int i = 1; i <= m; i++)
        {
            total += min(x / i, n);
        }
        return total;
    }
public:
    int findKthNumber(int m, int n, int k)
    {
        int start = 1, end = m*n, ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (possible(mid, m, n) < k) start = mid + 1;
            else
            {
                end = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.findKthNumber(3,3,5) << endl;
    
    return 0;
}