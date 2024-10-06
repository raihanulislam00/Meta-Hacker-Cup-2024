#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{

    int t;
    cin >> t;

    for (int case_num = 1; case_num <= t; case_num++)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        double temp1 = 0.0, temp2 = 1e9;
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            int d = i + 1;
            int A = v[i].first;
            int B = v[i].second;

            double M_i = (double)d / B;
            double Mi = (double)d / A;

            temp1 = max(temp1, M_i);
            temp2 = min(temp2, Mi);

            if (temp1 > temp2)
            {
                flag = false;
                break;
            }
        }

        cout << "Case #" << case_num << ": ";
        if (flag)
        {
            cout << fixed << setprecision(6) << temp1 << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
