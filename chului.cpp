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
#define lb lower_bound
#define ub upper_bound
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

/*################################ ¯\_(ツ)_/¯ ################################*/

vector<map<int, pii> > incoming(MAXN);
vi best(MAXN, -1);
vi par(MAXN, -1);
vi ins(MAXN, -1);
vvi kick(MAXN);
unordered_set<int> st;
vi vis(MAXN, 0);
int N, n, m;
vector< vpi > adj(MAXN);

pii maxEdge(int x){
	int mi=-1, mv = -INF;
	int ei = -1;
	trav(incoming[x]){
		if(it.S.F > mv){
			mi = it.F;
			ei = it.S.S;
			mv = it.S.F;
		}
	}
	return {mi, ei};
}


void fillInc(int x, int y){
	int eind = incoming[x][y].S;
	int val = incoming[x][y].F;
	trav(incoming[x]){
		if(present(st, it.F)) continue;
		if(present(incoming[n], it.F)){
			if(incoming[n][it.F].F < it.S.F-val){
				incoming[n][it.F] = {it.S.F-val, it.S.S};
			} 
		}else{
			incoming[n][it.F] = {it.S.F-val, it.S.S};
		}
		kick[it.S.S].pb(eind);
	}
}



void solveCycle(int x, int y){
	int ry = ins[y];
	int ty = ry;
	while(ty!=x){
		st.insert(ty);
		ins[ty] = n;
		ty = par[ty];
	}
	ins[x] = n;
	st.insert(x);


	int val, eind;
	ty = ry;
	while(ty!=x){
		fillInc(ty, par[ty]);
		ty = par[ty];
	}
	fillInc(x, y);
}


void process(int x){
	if(x==0) return;
	vis[x] = 1;
	pii p = maxEdge(x);
	int y = p.F;
	int ed = p.S;
	best[x] = ed;
    if(vis[y]==1){
        solveCycle(x, y);
		process(n++);
	}else if(vis[y]==2){
        par[x]=y;
        vis[x]=2;
        return;
    }else{
		par[x] = y;
		process(y);		
	}
    vis[x]=2;
}

void printMST();

void make_spanning_tree(){
    unordered_set<int> st;
    For(i, 1, N){
        st.insert(best[i]);
    }

    // Make directed MST
    For(i, 0, N){
        trav(incoming[i]){
            if(present(st, it.S.S)){
                adj[it.F].pb({i, it.S.F});
            }
        }
    }

    printMST();
}


void ordering(){
    int rt=0;

    priority_queue<pair<int, int> > pq;
    vi rank_node;
    pq.push({0, rt});
    while(sz(pq)){
        pii p = pq.top();
        pq.pop();
        rank_node.pb(p.S);
        trav(adj[p.S]){
            pq.push({it.S, it.F});
        }
    }

    printv(rank_node);

}

////////PRINT///////
void printGraph(){
   	For(i, 0, n){
    	cout<<i<<" -> ";
    	trav(incoming[i]){
    		cout<<it.F<<":"<<it.S.F<<":"<<it.S.S<<" ";
    	}
    	cout<<endl;
	}
}

void printBest(){
	For(i, 0, n){
		cout<<best[i]<<endl;
	}
	cout<<endl;
}

void printKick(){
	For(i, 0, m){
		cout<<i<<"-> ";
		trav(kick[i]){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}

void printMST(){
    For(i, 0, N){
        cout<<i<<" -> ";
        For(j, 0, sz(adj[i])){
            cout<<adj[i][j].F<<":"<<adj[i][j].S<<" ";
        }
        cout<<endl;
    }
}
////////PRINT///////


signed main(){
    fast
   //  vvi A{	{ -INF, 5, 1, 1 },
			// { -INF, -INF, 11, 4 },
			// { -INF, 10, -INF, 5 },
			// { -INF, 9, 8, -INF }};

    vvi A{  { -INF, 8, 1, 1},
            { -INF, -INF, 5, 3},
            { -INF, 8, -INF, 2},50
            { -INF, 4, 7, -INF}};


    n = sz(A);
    N = n;
    m=0;
    For(i, 0, n){
	    For(j, 0, n){
    		if(A[i][j]==-INF) continue;
    		incoming[j][i] = {A[i][j], m++};
    	}
    }
   	For(i, 0, m){
   		ins[i]=i;
   	}

   	For(i, 1, N){
   		if(!vis[i])
   			process(i);
   	}
    printGraph();
    printBest();
    printKick();

    // updateKick();
    // For(i, 0, 6){
    // 	cout<<par[i]<<" ";
    // }
    // cout<<endl;

    // For(i, 0, m){
    // 	cout<<ins[i]<<" ";
    // }
    // cout<<endl;

    rFor(i, n-1, 1){
    	trav(kick[best[i]]){
    		For(j, 0, n){
    			if(best[j]==it){
    				best[j] = best[i];
    			}
    		}
    	}
    }

    printBest();

    make_spanning_tree();

    cout<<endl<<endl;
    ordering();


    // end_routine()
    return 0;
}

