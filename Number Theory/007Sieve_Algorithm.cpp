#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 100;

//q = 10 ^ 7 , N = 10^7;
signed main()
{
    int a, b, k;
    cin >> a >> b >> k;

    //Sieve Algorithm  --> N * log(log(N))

    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int ans = 0;
    int pct = 0;

    for (int i = a; i <= b; i++)
    {
        if (isPrime[i])
            pct++;
    }
    if (k > pct)
    {
        cout << -1;
        return 0;
    }

    else if (k == 1)
    {
        int prev = a - 1;
        int curr = 0;
        for (int i = a; i <= b; i++)
        {
            if (isPrime[i] or i == b)
            {
                curr = i;
                if (i == b)
                    curr++;
                ans = max(ans, curr - prev);
                prev = i;
            }
        }
    }
    else if (k > 1)
    {
        int ct = 0;
        int fp = 0;

        for (int i = a; i <= b; i++)
        {
            if (isPrime[i])
            {
                if (!ct)
                    fp = i;
                ct++;
            }
            if (ct == k)
            {
                ans = max(ans, i - (a - 1));
                break;
            }
        }
        int lp = 0;
        ct = 0;
        for (int i = b; i >= a; i--)
        {
            if (isPrime[i])
            {
                if (!ct)
                    lp = i;
                ct++;
            }
            if (ct == k)
            {
                ans = max(ans, b + 1 - i);
                break;
            }
        }
        int prev = a;
        for (int i = a + 1; i <= b; i++)
        {
            if (isPrime[i] or i == b)
            {
                ans = max(ans, i + 1 - prev);
                prev = i;
            }
        }
    }
    cout << ans;

    return 0;
}