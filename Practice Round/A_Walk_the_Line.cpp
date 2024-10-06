#include <bits/stdc++.h>

using namespace std;

// Macros
#define REP(i, j, n) for (int i = j; i < n; i++)
#define trav(i, a) for (auto i : a)
#define all(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second
#define GCD __gcd

// Type Names
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

// Global Variables
const ll MOD = 1e9 + 7;
// const ll MOD = 5988425999767823693;
// const ll MOD = 998244353;

// print vector X)
template <typename T>
void print_vector(vector<T> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
}

template <typename T>
void print_2d_vector(vector<vector<T>> a)
{
    int row = a.size();
    int col = a[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

long long binpow(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    if (a < 0)
        a += m;
    while (b)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}

void solve(int tc)
{
    ll n, k;
    cin >> n >> k;
    ll mn = 1e9 + 1;
    ll ph;
    for (int i = 0; i < n; i++)
    {
        cin >> ph;
        mn = min(ph, mn);
    }
    cout << "Case #" << tc << ": ";
    // cout << mn << "\n";
    if (n <= 2 && mn <= k)
    {
        cout << "YES\n";
    }
    else if ((2 * (n - 1) - 1) * mn <= k && n > 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("breedflip.in", "r", stdin);
    // freopen("breedflip.out", "w", stdout);
    // preprocess();
    int i = 1;
    int t = 1;
    cin >> t;
    for (i = 1; i <= t; i++)
        solve(i);
    return 0;
}