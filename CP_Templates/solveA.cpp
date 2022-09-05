#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5000;

//q = 10 ^ 7 , N = 10^7;
signed main()
{
    int n;
    cin >> n;

    //Sieve Algorithm  --> N * log(log(N))
    vector<bool> isPrime(N, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int ans = 0;

    for (int i = 6; i <= n; i++)
    {
        int k = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0 and isPrime[j])
                k++;
        }
        if (k == 2)
        {
            ans++;
        }
    }
    cout << ans;

    return 0;
}