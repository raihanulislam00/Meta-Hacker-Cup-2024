#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

void fun1(int &T, vector<tuple<ll, ll, ll>> &test_cases)
{
    cin >> T;
    test_cases.resize(T);
    for (int i = 0; i < T; i++)
    {
        ll W, G, L;
        cin >> W >> G >> L;
        test_cases[i] = make_tuple(W, G, L);
    }
}

ll fun2(ll x)
{
    return (x % MOD + MOD) % MOD;
}

ll fun3(ll W, ll G, ll L)
{
    ll a = fun2(W - G);
    ll b = fun2(2 * fun2(L) + 1);
    return fun2(a * b);
}

ll fun4(ll W, ll G)
{
    return fun2(W - G);
}

ll fun5(ll W, ll G, ll L)
{
    if (L > 0)
    {
        return fun3(W, G, L);
    }
    else
    {
        return fun4(W, G);
    }
}

void fun6(int case_num, ll result)
{
    cout << "Case #" << case_num << ": " << result << "\n";
}

void fun7(const vector<tuple<ll, ll, ll>> &test_cases)
{
    for (int i = 0; i < test_cases.size(); i++)
    {
        ll W, G, L;
        tie(W, G, L) = test_cases[i];
        ll result = fun5(W, G, L);
        fun6(i + 1, result);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    vector<tuple<ll, ll, ll>> test_cases;

    fun1(T, test_cases);
    fun7(test_cases);

    return 0;
}
