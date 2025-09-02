#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> dist(n);
    vector<int> speed(n);
    vector<double> time(n);

    for (int i = 0; i < n; i++) cin >> dist[i];
    for (int i = 0; i < n; i++) cin >> speed[i];

    for (int i = 0; i < n; i++)
    {
        time[i] = (double) dist[i] / (double)speed[i];
    }

    sort(time.begin(), time.end());

    int ans = 0;

    for (int i = 0; i < n && i < time[i]; i++)
    {
        ans++;
    }

    cout << ans << endl;

}