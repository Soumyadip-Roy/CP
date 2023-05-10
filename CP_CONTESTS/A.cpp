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
        int n,m;cin>>n>>m;
        
        int l=0,mid=0,r=0;

        set <int> v;
        for (int i = 0; i < n; i++)
        {
            int x; cin>>x;
            if (x == -1)
                l++;
            else if (x == -2)
                r++;
            else{
                v.insert(x);
                mid++;
            }
        }
        int ans = 0;
        int ctl = 0;
        int ctr = mid-1;

        for (auto p: v){
            int left = ctl;
            if (p - ctl >= l)
            {
                left += l;
            }
            else
            {
                left += (p - ctl);
            }
            ctl++;

            int right = ctr;
            if ((m - p - ctr) >= r)
            {
                right += r;
            }
            else
            {
                right += (m - p - ctr);
            }
            ctr--;

            ans = max(ans,left+right+1);
        }

        cout<<ans<<endl;
    }
}
