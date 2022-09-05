// Code is like humour. When you have to explain it, it’s bad. //

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define setbits(x) __builtin_popcount(x)
#define trzeros(x) __builtin_ctzll(x)
#define sp(n) fixed << setprecision(n)
#define all(v) v.begin(),v.end()

int gcd(int a, int b){return (b == 0) ? a : gcd(b, a % b);}
int max(int a, int b){if (a > b)return a;else return b;}
int min(int a, int b){if (a < b)return a;else return b;}

bool sortbysec(pair<int, int> a, pair<int, int> b){return a.second < b.second;}
bool rev(int a,int b){return a>b;}
void PrintBinary(int x,int n=31){for(int i = n; i >=0; i--){cout<<((x >> i) & 1);}cout<<endl;}

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}}
template <class T> void finish(T x){if(x) cout<<"YES\n";else cout<<"NO\n";}

const int M = 1e9+7,N=1e6;



// int vis[N];
// int level[N];

// void bfs(int source)
// {
//     queue<int> q;
//     q.push(source);
//     vis[source] = 1;

//     while (!q.empty())
//     {
//         int vertex = q.front();
//         cout << vertex << " ";
//         q.pop();
//         for (auto child : graph[vertex])
//         {
//             if (!vis[child])
//             {
//                 q.push(child);
//                 vis[child] = 1;
//                 level[child] = level[vertex] + 1;
//             }
//         }
//     }
// }

signed main()
{
    fast
    int T = 1;cin >> T;
    while (T--)
    {
        
    }
}
