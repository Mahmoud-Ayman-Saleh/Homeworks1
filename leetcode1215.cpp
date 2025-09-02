#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define ll long long 



class Solution
{
private:

    bool in_range(ll num, ll start, ll end)
    {
        return num >= start && num <= end;
    }

    bool process(queue<ll> &q, vector<ll> &ans, ll low, ll high, ll num)
    {
        if (num > high) return false;
        if (in_range(num, low, high))
        {
            ans.push_back(num);
        }

        q.push(num);
        return true;
    }

public:
    vector<ll> countSteppingNumbers(ll low, ll high)
    {
        queue<ll> q;
        vector<ll> ans;
        if (low == 0)
        {
            ans.push_back(0);
        }

        for (int i = 0; i <= 9; i++)
        {
            q.push(i);

            if (in_range(i, low, high)) ans.push_back(i);
        }

        for (int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size())
        {
			while (sz--)
            {
                ll num = q.front();
                q.pop();

                int last_digit = num % 10;

                if (last_digit != 0 && !process(q, ans, low, high, num * 10 + (last_digit - 1)))
                {
                    break;
                }

                if (last_digit != 9 && !process(q, ans, low, high, num * 10 + (last_digit + 1)))
                {
                    break;
                }

            }
        }

        return ans;
    }
};

int main() {
	Solution s;
	vector<ll> result = s.countSteppingNumbers(0, 100);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }

	return 0;
}
