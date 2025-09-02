#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (k > 0)
        {
            if (nums[i] < 0)
            {
                nums[i] *= -1;
                k--;
            }
        }
    }

    sort(nums.begin(), nums.end());

    if (k > 0 && k % 2 == 1)
    {
        nums[0] *= -1;
    }

    for (int i = 0; i < n; i++)
    {
        ans += nums[i];
    }

    cout << ans << endl;
}
