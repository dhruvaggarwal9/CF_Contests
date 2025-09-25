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
    inp_arr1(n);
    int zero = 0;
    int one = 0;
    int minus = 0;
    for(int i : a){
        if(i == -1){
            minus++;
        }
        if(i==0){
            zero++;
        }
        if(i==1){
            one++;
        }
    }

    int op = 0;
    if(one>0){
        op += 2*(minus%2!=0);
        op += zero;
    }
    else{
        op+=zero;
        op += 2*(minus%2!=0);
    }

    cout<<op<<endl;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    test;

    return 0;
}