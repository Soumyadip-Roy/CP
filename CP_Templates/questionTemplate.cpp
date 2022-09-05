//Code is like humor. When you have to explain it, it’s bad.

#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n";
#define int long long

#define inf LLONG_MAX
#define setbits(x) __builtin_popcount(x)
#define trzeros(x) __builtin_ctzll(x)
#define sp(n) fixed << setprecision(n)

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

#define all(v) v.begin(), v.end()

const int N = 2e5;

vector<vector<int>> tree;
vector<int> vis(N, 0);
vector<unordered_set<int>> ans;
unordered_set<int> path;

void dfs(int vertex /*,vector<int> tree[], vector<int> &vis,vector<vector<int>> &ans,vector<int> &path*/, int par = 0)
{

    //after entering the vertex
    if (!vis[vertex])
    {
        path.insert(vertex);
    }
    vis[vertex] = 1;

    for (int child : tree[vertex])
    {

        //before entering the child
        if (tree[vertex].size() == 1 and child == par)
        {
            ans.push_back(path);
            path.clear();
            return;
        }
        if (vis[child])
            continue;
        dfs(child, /*tree,vis,ans,path,*/ vertex);

        //after exiting ther child node
    }

    //before exiting the vertex
}

signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while (T--)
    {

        int n;
        cin >> n;

        tree.clear();
        tree.resize(n + 1);
        vis.clear();
        vis.resize(n + 1);
        ans.clear();

        int par;

        for (int i = 1; i <= n; i++)
        {
            int p;
            cin >> p;
            if (i == p)
            {
                par = p;
            }
            else
            {
                tree[i].push_back(p);
                tree[p].push_back(i);
            }
        }

        dfs(par /*,tree,vis,ans,path*/);
        if (n == 1)
            cout << "1\n1\n1\n";
        if (n - 1)
            cout << ans.size() << endl;
        for (auto x : ans)
        {
            cout << x.size() << endl;
            for (auto i : x)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
