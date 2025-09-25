#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define forloop(i, a, b) for(ll i = a; i < b; i++)
#define rloop(i, a, b) for(ll i = b-1; i >= a; i--)
#define inp_ll(x) ll x; cin>>x
#define inp_ll2(x,y) ll x,y; cin>>x>>y
#define inp_ll4(x,y,z,l) ll x,y,z,l; cin>>x>>y>>z>>l
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

ll count(const vector<ll>& a, int k, int limit) {
    int n = a.size();
    
    unordered_map<ll, int> freq;

    int left = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        
        while (freq.size() > k) {
            freq[a[left]]--;

            if (freq[a[left]] == 0) {
                freq.erase(a[left]);
            }
            left++;
        }

        int length = i - left + 1;
        
        while (length > limit) {
            freq[a[left]]--;

            if (freq[a[left]] == 0) {
                freq.erase(a[left]);
            }

            left++;
            length = i - left + 1;
        }
        ans += length;
    }

    return ans;
}

void solve() {
    inp_ll4(n,k,l,r);
    inp_arr1(n);

    ll sizek = (count(a, k, r) - count(a, k, l - 1));
    ll sizeo = (count(a, k - 1, r) - count(a, k - 1, l - 1));

    cout << sizek - sizeo << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test;

    return 0;
}