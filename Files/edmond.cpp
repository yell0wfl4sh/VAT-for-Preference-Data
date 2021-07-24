/*
            _ _  ___            __ _ _  _       _     
 _   _  ___| | |/ _ \__      __/ _| | || |  ___| |__  
| | | |/ _ \ | | | | \ \ /\ / / |_| | || |_/ __| '_ \ 
| |_| |  __/ | | |_| |\ V  V /|  _| |__   _\__ \ | | |
 \__, |\___|_|_|\___/  \_/\_/ |_| |_|  |_| |___/_| |_|
 |___/                 

*/

#include <bits/stdc++.h>
using namespace std;
#define sz(x) (ll)(x).size()
#define trav(x) for(auto it: x)
#define all(x) x.begin(), x.end()
#define stp fixed<<setprecision(20)
#define db(x) cout<<#x<<": "<<x<<endl
#define tc ll tt; cin>>tt; while(tt--)
#define For(i, st, en) for(ll i=st; i<en; i++)
#define rFor(i, st, en) for(ll i=st; i>=en; i--)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define printv(x) For(i, 0, sz(x)){cout<<x[i]<<" ";} cout<<endl;
#define print2v(x) For(i, 0, sz(x)){For(j, 0, sz(x[0])){cout<<x[i][j]<<" ";} cout<<endl;}
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvi;
typedef vector< pair<int, int> > vpi;
#define endl '\n'
#define MAXN 300005
#define MOD 1000000007
#define INF 1000000000000000007

void splitx(string s, char c, vector<string> &v){
    int i=0, j;
    while(i<sz(s)){
        j=i; string temp;
        while(j<sz(s) && s[j]!=c){temp+=s[j]; j++;}
        v.pb(temp); i=j+1;
    }
}

signed main(){
	fast
	

    return 0;
}
    

