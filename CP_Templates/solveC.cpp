// Code is like humour. When you have to explain it, it’s bad. //

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
#define all(v) v.begin(),v.end()
template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}

const int M = 1e9+7,N=1e6;

signed main()
{
    fast
    int T = 1;
    cin >> T;
    while (T--)
    {
        int n;cin>>n;
        map<int,int> pos;
        vector<pair<string,int>> a(n);
        vector<pair<int,int>> b(n);

        for(int i= 0 ; i < n ;i++){
            
            cin>>a[i].first;
            cin>>b[i].first;

            int id;
            cin>>id;
            pos[id]=i;
            a[i].second = id;
            b[i].second = id;
        }

        sort(all(a));
        sort(all(b));

        // coutfs(a);
        // cout<<endl;
        // coutfs(b);
        // cout<<endl;
        // coutfs(pos);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
           if(a[i].second == b[i].second and pos[a[i].second]==i){
               ans++;
            //    cout<<i;
           }
        }
        cout<<ans<<endl;
        

    }
}
