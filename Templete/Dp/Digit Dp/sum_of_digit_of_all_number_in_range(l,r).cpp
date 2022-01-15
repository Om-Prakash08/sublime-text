// sum of digit occuring in all number in range[a,b]
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define int long long 
vector<int> num;
ll a, b;
ll DP[20][180][2];

long long  call(int pos, ll sum, int tight)
{
    if(pos == num.size())
        return sum ;
    if(DP[pos][sum][tight] != -1) 
        return DP[pos][sum][tight];
    int x = tight ? num[pos] : 9 ;
    ll res = 0 ;
    for(int i = 0; i <= x; i++)
    {
        if(i < num[pos] || tight == 0)
            res += call(pos + 1, sum + i, 0) ;
        else
            res += call(pos + 1, sum + i, 1) ;
    }
    return DP[pos][sum][tight] = res;
}

long long solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    return call(0, 0, 1);
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif
    cin >> a >> b ;
    long long res = solve(b) - solve(a-1);
    cout << res << endl;
    return 0;
}