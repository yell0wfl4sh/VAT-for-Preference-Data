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
#define trav(x) for(auto& it: x)
#define all(x) x.begin(), x.end()
#define stp fixed<<setprecision(20)
#define tc ll tt; cin>>tt; while(tt--)
#define For(i, st, en) for(ll i=st; i<en; i++)
#define rFor(i, st, en) for(ll i=st; i>=en; i--)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define printv(x) For(i, 0, sz(x)){cout<<x[i]<<" ";} cout<<endl;
#define print2v(x) For(i, 0, sz(x)){For(j, 0, sz(x[i])){cout<<x[i][j]<<" ";} cout<<endl;}
#define ll long long
#define int long long
#define F first
#define S second
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
#define endl '\n'
#define MAXN 300005
#define MOD 1000000007
#define INF 1000000000000000007
#define bitc __builtin_popcountll

int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (double)(clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n";

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void splitx(string s, char c, vector<string> &v){
    int i=0, j;
    while(i<sz(s)){
        j=i; string temp;
        while(j<sz(s) && s[j]!=c){temp+=s[j]; j++;}
        v.pb(temp); i=j+1;
    }
}

vi dx{1, 0, -1, 0, 1, 1, -1, -1};
vi dy{0, 1, 0, -1, 1, -1, 1, -1};





signed main(){
    fast
    vvi vx  {{0, 2, 11, 12, 6, 6, 13, 2, 7, 12, 6, 0, 0},
             {2, 0, 3, 2, 2, 1, 2, 3, 0, 0, 0, 0, 0},
             {9, 1, 0, 7, 7, 4, 16, 3, 9, 10, 2, 1, 2},
             {8, 2, 14, 0, 9, 8, 10, 2, 9, 10, 3, 3, 0},
             {12, 2, 12, 11, 0, 6, 11, 1, 10, 11, 4, 2, 1},
             {4, 3, 8, 2, 4, 0, 5, 0, 4, 4, 0, 0, 0},
             {8, 4, 5, 10, 9, 5, 0, 2, 6, 10, 4, 1, 1},
             {3, 1, 1, 2, 3, 5, 2, 0, 0, 0, 0, 0, 0},
             {8, 0, 6, 6, 6, 3, 10, 0, 0, 11, 2, 1, 1},
             {7, 0, 6, 7, 5, 2, 12, 0, 6, 0, 4, 2, 1},
             {5, 0, 7, 7, 7, 0, 6, 0, 7, 6, 0, 1, 0},
             {5, 0, 4, 3, 3, 2, 5, 0, 4, 4, 3, 0, 0},
             {2, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}};
    
    For(i, 0, 13){
        For(j, i+1, 13){
            int temp = vx[j][i];
            vx[j][i] = vx[i][j];
            vx[i][j] = temp;
        }
    }


    For(i, 0, 13){
        For(j, 0, 13){
            cout<<vx[i][j]<<",";
        }
        cout<<endl;
    }

    map<float, int> mp;
    for(int i=0; i<13; i++){
        int w=0, t=0;
        for(int j=0; j<13; j++){
            w+=vx[i][j];
            t+=vx[i][j]+vx[j][i];
        }
        float val = (float)w/(float)t;
        mp[val]=i;
    }

    trav(mp){
        cout<<it.S<<" ";
    }
    cout<<endl;

    // end_routine()
    return 0;
}

