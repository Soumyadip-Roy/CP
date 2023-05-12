//Code is like humour. When you have to explain it, it’s bad. //

//Author - royboylab

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define all(v) v.begin(),v.end()

template <class T> void coutfs(T x){for(auto i : x){cout<<i.first<<" "<<i.second<<endl;}}
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}

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
        vector<int> v(n);
        vector<int> a;

        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }

        a.push_back(v[0]);
        a.push_back(v[1]);
        int c = 0;
        int d = 0;
        for (int i = 1; i < n; i++)
        {   
            d+= abs(v[i]-v[i-1]);
            // cout<<d<<" "<<abs(a[c]-v[i])<<endl;
            if(d==abs(a[c]-v[i])){
                a.pop_back();
                a.push_back(v[i]);
            }
            else{
                a.push_back(v[i]);
                d=abs(v[i]-v[i-1]);
                c++;
            }
        }
        // coutele(a);
        if(a.size()==2 and a[0]==a[1])cout<<1<<endl;
        else cout<<a.size()<<endl;
    }
}