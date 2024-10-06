#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(int i)
{
    int n;
    double p;
    cin >> n >> p;

    double a = pow(p / 100.0, static_cast<double>(n - 1) / n) * 100;

    double ans = a - p;

    cout << "Case #" << i << ": " << fixed << setprecision(9) << ans << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solve(i);
    }
    return 0;
}
