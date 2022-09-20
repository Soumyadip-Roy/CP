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
template <class T> void coutele(T x){for(auto i : x){cout<<i<<" ";}cout<<endl;}
template <class T> void finish(T x){if(x) cout<<"YES\n";else cout<<"NO\n";}

const int M = 1e9+7,N=1e6;

int binExp(int a , int b){
    int ans = 1;
    while(b){
        if(b&1) ans=(ans * a)%M;//ith bit set
        b>>=1;
        a=(a*a)%M;
    }
    return ans%M;
}

// nCr = n! / (n-r)! * r!
//n= 10^6 ,  k < n < 10^6
//q queries , q < 10^5

int fact [200009];

int ncr(int n,int r){
    int ans = fact[n];
    int den = (fact[n-r]*fact[r])%M;

    return ans/den;

}

signed main()
{
    fast
    fact[0]=1;
    for(int i = 1 ; i < 200009 ;i ++){
        fact[i] = (fact[i-1]*i)%M;
    }
    
    int T = 1;cin >> T;
    while (T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        

        vector<int> v(n+1,0);

        for(int i = 1 ;i<=n;i++){
            cin>>v[i];
        }

        sort(all(v));

        int ct = 0;

        int l = 1 , r = m;
        int ans = 0;
        int prvr = 1;
        while(r<=n and l<=n-m-1){
            
            while(v[r]-v[l]<=k and r<=n){
                r++;
            }
            ans+= ncr(r-l,m-1);
            ans-= ncr(prvr-l,m-1);
            prvr=r;
            while(v[r]-v[l]>k and l<r-m-1){
                l++;
            }
            while(l==r-m and v[r]-v[l]>k and r<=n){
                l++;r++;
            }
        }
        cout<<ans<<endl;







    }
}
