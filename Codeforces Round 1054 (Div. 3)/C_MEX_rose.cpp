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
    inp_ll2(n,k);
    inp_arr1(n);

    //array should have 0,1,2,3.... k-1, k+1 , K+2...n;

    vector<int> present(n+1,0);
    for(int i : a){
        present[i] ++;
    }
    int op =0;
    for(int i = 0; i<k; i++){
        if(present[i] == 0){
            op++;
        }
    }
    int extra = present[k];
    if(extra > op){
        op+= extra - op;
    }

    cout<<op<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test;

    return 0;
}