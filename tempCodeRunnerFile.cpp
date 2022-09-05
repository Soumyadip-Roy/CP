#include <bits/stdc++.h>
using namespace std;

main()
{
    int n, t;
    cin >> n >> t;
    if (to_string(t).length() > n)
        cout << -1;
    else if(t%10 ==0 ){
        cout<<1;
        while(--n)cout<<0;
    }
    else
    {
        cout << t;
        while (--n)
            cout << 0;
    }
}
