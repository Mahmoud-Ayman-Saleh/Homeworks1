#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int possible(vector<double> &area, double x);
double largest_area(vector<double> &radius, int people);

int main()
{
    IOS;
    int t; cin >> t;
    int n, x;
    while (t--)
    {
        cin >> n >> x;
        vector<double> radius(n);
        for (int i = 0; i < n; i++) cin >> radius[i];
        double ans = largest_area(radius, x+1);
        cout << fixed << setprecision(4) << ans << '\n';
    }
}

double largest_area(vector<double> &radius, int people)
{
    double start = 0, end = 0;
    vector<double> area(radius.size());

    for (int i = 0; i < radius.size(); i++)
    {
        area[i] = radius[i] * radius[i] * acos(-1.0);
        end = max(area[i], end);
    }

    for (int i = 0; i < 100; i++)
    {
        double mid = (start + end) / 2;
        if (possible(area, mid) >= people)
        {
            start = mid;
        }
        else end = mid;
    }

    return start;
}

int possible(vector<double> &area, double x)
{
    int can_eat = 0;

    for (int i = 0; i < area.size(); i++)
    {
        can_eat += (int) (area[i] / x);
    }
    return can_eat;
}