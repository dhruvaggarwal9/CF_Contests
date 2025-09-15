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

void solve() {
    inp_ll(n);
    vector<int> vis(n+1,0);
    vector<int> a(n);
    for(int i = 0;i <n;i++){
        cin>>a[i];
        vis[a[i]] = 1;
    }
    int first = INT_MAX;
    int last = INT_MIN;
    for(int i = 1; i<=n ; i++){
        if(vis[i] == 0){
            first = min(first, i);
            last = max(last,i);
        }
    }

    for(int i = 0; i<n;i++){
        if(a[i] == 0){
            a[i] = last;
            break;
        }
    }
    for(int i = n-1; i>=0;i--){
        if(a[i] == 0){
            a[i] = first;
            break;
        }
    }

    int x = INT_MAX;
    bool found =  false;
    for(int i = 0; i<n; i++){
        if(a[i] != i+1){
            x = i;
            found = true;
            break;
        }
    }
    if(found == false){
        cout<<0<<endl;
        return;
    }

    int y;
    for(int i = n-1; i>=0; i--){
        if(a[i] != i+1){
            y = i;
            break;
        }
    }

    cout<<y-x+1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test;

    return 0;
}