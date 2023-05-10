//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

int max(int a, int b){if (a > b)return a;else return b;}
int min(int a, int b){if (a < b)return a;else return b;}

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

const int M = 1e9+7,N=1e6;

signed main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T = 1;cin >> T;
    while (T--)
    {
        int n;cin>>n;
        int m;cin>>m;

        vector<vector<int>> v(m,vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < m ; j++){
                int a;cin>>a;
                v[j][i]=a;
            }
        }

        int ans = 0;
        for(auto x : v){

            sort(all(x));
            reverse(all(x));    
            int res = 0;
            int i = n-1;
            int j = 0;

            for(auto p : x){
                res += (p*i)-(p*j);
                i--;j++;
            }
            ans+=res;
        }
        cout<<ans<<endl;
    }
}
