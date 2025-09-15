#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forloop(i, a, b) for(ll i = a; i < b; i++)
#define rloop(i, a, b) for(ll i = b-1; i >= a; i--)
#define inp_ll(x) ll x; cin>>x
#define inp_ll2(x,y) ll x,y; cin>>x>>y
#define inp_ll3(x,y,z) ll x,y>>z
#define inp_string(x) string x; cin>>x
#define inp_arr1(n)  vector<ll> a(n,0); for(ll i = 0; i < n; i++){ cin>>a[i]; }
#define inp_arr2(n)  vector<ll> b(n,0); for(ll i = 0; i < n; i++){ cin>>b[i]; }
#define test ll t; cin >> t; while(t--) solve();
#define printyes cout<<"YES"<<endl
#define printno cout<<"NO"<<endl
#define vec vector<ll>

const int MOD = 998244353;

ll recurse(int i, int swapped, vector<ll> &a, vector<ll> &b, vector<vector<ll>> &dp, int n) {

    if (i == n-1) {
        return 1;
    }

    if (dp[i][swapped] != -1) {
        return dp[i][swapped];
    }

    ll olda = a[i];
    ll oldb = b[i];

    if (swapped) {
        olda = b[i];
        oldb = a[i];
    } 

    ll ans = 0;

    if (a[i+1] >= olda && b[i+1] >= oldb) {
        ans = (ans + recurse(i+1, 0, a, b, dp, n)) % MOD;
    }

    if (b[i+1] >= olda && a[i+1] >= oldb) {
        ans = (ans + recurse(i+1, 1, a, b, dp, n)) % MOD;
    }

    return dp[i][swapped] = ans;
}

void solve() {
    inp_ll(n);
    inp_arr1(n);
    inp_arr2(n);

    vector<vector<ll>> dp(n, vector<ll>(2, -1));

    ll ans = (recurse(0, 0, a, b, dp, n) + recurse(0, 1, a, b, dp, n)) % MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test;
    return 0;
}
