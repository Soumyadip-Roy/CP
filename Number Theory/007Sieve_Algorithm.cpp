#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e9;


//q = 10 ^ 7 , N = 10^7;
signed main(){
    int q ; cin>>q;
    //Sieve Algorithm  --> N * log(log(N))
    vector <bool> isPrime(N,true);
    isPrime[0]=isPrime[1]=false;
    for (int i = 2; i < N; i++)
    {
        if(isPrime[i]==true){
            for(int j = 2*i ; j<N ;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i = 1 ; i < 100 ;i++){
        if(isPrime[i]==1)cout<<i<<" ";
    }
    while(q--){
        int num ;cin>>num;
        if(isPrime[num]==1)cout<<num<<" : PRIME\n";
        else cout<<num<<" : NOT PRIME\n";
    }
    return 0;
}