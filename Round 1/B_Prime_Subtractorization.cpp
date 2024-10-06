#include <bits/stdc++.h>
using namespace std;
#define int long long
void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<int> red_test_case(int &T, int &max_value)
{
    vector<int> cases(T);
    for (auto &val : cases)
    {
        cin >> val;
        max_value = max(max_value, val);
    }
    return cases;
}

vector<bool> generate_sieve(int limit)
{
    vector<bool> sieve(limit + 3, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= limit + 2; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= limit + 2; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

vector<int> cal(const vector<bool> &sieve, int max_val)
{
    vector<int> prefix(max_val + 1, 0);
    for (int i = 2; i <= max_val - 2; i++)
    {
        prefix[i] = prefix[i - 1] + (sieve[i] && sieve[i + 2] ? 1 : 0);
    }
    return prefix;
}

void pre(const vector<int> &cases, const vector<int> &prefix, int T)
{
    for (int t = 1; t <= T; t++)
    {
        int N = cases[t - 1];
        int twin = (N >= 5) ? prefix[N - 2] : 0;
        int result = twin + (twin >= 1 ? 1 : 0);
        cout << "Case #" << t << ": " << result << "\n";
    }
}

int32_t main()
{
    fast_io();

    int T;
    cin >> T;

    int max_value = 0;
    vector<int> test_cases = red_test_case(T, max_value);
    vector<bool> sieve = generate_sieve(max_value);
    vector<int> twin_prefix = cal(sieve, max_value);

    pre(test_cases, twin_prefix, T);

    return 0;
}