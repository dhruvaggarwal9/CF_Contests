#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forloop(i, a, b) for(ll i = a; i < b; i++)
#define rloop(i, a, b) for(ll i = b-1; i >= a; i--)
#define inp_ll(x) ll x; cin>>x
#define inp_ll2(x,y) ll x,y; cin>>x>>y
#define inp_ll3(x,y,z) ll x,y,z; cin>>x>>y>>z
#define inp_string(x) string x; cin>>x
#define inp_arr1(n)  vector<ll> a(n,0); for(ll i = 0; i < n; i++){ cin>>a[i]; }
#define inp_arr2(n)  vector<ll> b(n,0); for(ll i = 0; i < n; i++){ cin>>b[i]; }
#define test ll t; cin >> t; while(t--) solve();
#define printyes cout<<"YES"<<endl
#define printno cout<<"NO"<<endl
#define vec vector<ll>

void sort_(vector<ll> &a){
    sort(a.begin(),a.end());
}

ll calculatecost(const string &s, char ch) {
    ll n = s.size();
    vector<ll> pos;

    for (ll i = 0; i < n; i++) {
        if (s[i] == ch) {
            pos.push_back(i);
        }
    }

    ll k = pos.size();
    if (k <= 1) {
        return 0LL;
    }

    vector<ll> q(k);
    for (ll i = 0; i < k; i++) {
        q[i] = pos[i] - i;
    }

    ll med = q[k / 2];
    ll cost = 0;

    for (ll i = 0; i < k; i++) {
        ll diff = q[i] - med;
        if (diff < 0) {
            diff = -diff;
        }
        cost += diff;
    }

    return cost;
}

void solve() {
    inp_ll(n);
    inp_string(s);
    
    ll costA = calculatecost(s, 'a');
    ll costB = calculatecost(s, 'b');

    ll ans;
    if (costA < costB) {
        ans = costA;
    } else {
        ans = costB;
    }

    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test;
    return 0;
}
