#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define forloop(i, a, b) for(ll i = a; i < b; i++)
#define rloop(i, a, b) for(ll i = b-1; i >= a; i--)
#define inp_ll(x) ll x; cin>>x
#define inp_ll2(x,y) ll x,y; cin>>x>>y
#define inp_ll3(x,y,z) ll x,y,z; cin>>x>>y>>z
#define inp_string(x) string x; cin>>x
#define inp_arr1(n)  vector<ll> c(n,0); for(ll i = 0; i < n; i++){ cin>>c[i]; }
#define inp_arr2(n)  vector<ll> b(n,0); for(ll i = 0; i < n; i++){ cin>>b[i]; }
#define test ll t; cin >> t; while(t--) solve();
#define prllyes cout<<"YES"<<endl
#define prllno cout<<"NO"<<endl
#define vec vector<ll>

void sort_(vector<ll> &a){
    sort(a.begin(),a.end());
}

void solve() {
    inp_ll2(n,y);
    inp_arr1(n);
    
    set<ll> candidates;

    candidates.insert(2);
    
    for(ll i = 0; i < n; i++) {

        for(ll cost = 1; cost <= c[i]; cost++) {
            
            ll x_min = (c[i] + cost - 1) / cost;
            ll x_max;

            if(cost == 1) {
                x_max = c[i];
            } else {
                x_max = c[i] / (cost - 1);
            }
            
            if(x_min >= 2) {
                candidates.insert(x_min);
                if(x_max + 1 >= 2) {
                    candidates.insert(x_max + 1);
                }
            }
        }
    }
    
    ll max_c = *max_element(c.begin(), c.end());

    // for(ll x = 2; x <= min(max_c, 1000LL); x++) {
    //     candidates.insert(x);
    // }
    
    ll best = LLONG_MIN;
    
    for(ll x : candidates) {
        if(x <= 1) continue;
        
        map<ll, ll> available_tags;
        vector<ll> costs(n);
        ll total_sum = 0;
        
        for(ll i = 0; i < n; i++) {
            costs[i] = (c[i] + x - 1) / x; 
            total_sum += costs[i];
            available_tags[c[i]]++;
        }
        
        map<ll, ll> needed_tags;
        for(ll price : costs) {
            needed_tags[price]++;
        }
        
        ll tags_to_print = 0;
        for(auto& x: needed_tags) {
            ll price = x.first;
            ll need = x.second;
            ll available = available_tags[price];
            tags_to_print += max(0LL, need - available);
        }
        
        ll income = total_sum - tags_to_print * y;
        best = max(best, income);
    }
    
    cout << best << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test;

    return 0;
}