#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> weight, value;
const int MAX = 2000+1;
int memory[MAX][MAX];


int knapsack(int idx, int remain)
{

    if (idx == (int)weight.size()) return 0;

    auto &ans = memory[idx][remain];
    if (ans != -1)
    {
        return ans;
    }

    int leave = knapsack(idx + 1, remain);
    int pick = 0;

    if (remain >= weight[idx])
    {
        pick = value[idx] + knapsack(idx + 1, remain - weight[idx]);
    }
    ans = max(pick, leave);
    return ans;
}


int main()
{
    int max_weight; cin >> max_weight;
    int n; cin >> n;

    weight.resize(n);
    value.resize(n);

    memset(memory, -1, sizeof(memory));

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    cout << knapsack(0, max_weight) << endl;
}