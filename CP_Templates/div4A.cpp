// Code is like humour. When you have to explain it, it’s bad. //

#include <bits/stdc++.h>
using namespace std;

#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long int
#define setbits(x) __builtin_popcount(x)
#define trzeros(x) __builtin_ctzll(x)
#define sp(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

bool sortbysec(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool rev(int a, int b) { return a > b; }
void PrintBinary(int x, int n = 31)
{
    for (int i = n; i >= 0; i--)
    {
        cout << ((x >> i) & 1);
    }
    cout << endl;
}

template <class T>
void coutfs(T x)
{
    for (auto i : x)
    {
        cout << i.first << " " << i.second << endl;
    }
}
template <class T>
void coutele(T x)
{
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << endl;
}
template <class T>
void finish(T x)
{
    if (x)
        cout << "YES\n";
    else
        cout << "NO\n";
}

const int M = 1e9 + 7, N = 1e6;

signed main()
{
    fast int T = 1;
    cin >> T;
    while (T--)

    {
        int n;
        cin >> n;
        int k;
        cin >> k;

        string s = to_string(n);

        int sum = 0;
        for (auto x : s)
        {
            sum += (x - '0');
        }
        reverse(all(s));
        int i = 1, ans = 0;
        int j = 0;
        while (sum > k)
        {
            ans += pow(10, i) - (s[j] - '0');
            sum -= (s[j] - '0' - 1);
            j++;
            i++;
        }
        cout << ans << endl;
    }
}
