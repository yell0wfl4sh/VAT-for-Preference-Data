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
vvi kick(MAXN);
unordered_set<int> st;
vi vis(MAXN, 0);
int N, n, m, tcnt;
vector< vpi > adj(MAXN);
vpi ord;
set<int> inchash;
vi orderofx;

//DSU
vi dsuparent(MAXN);

void initiliase(){
    For(i, 0, MAXN){
        dsuparent[i] = i;
    }
}

int rootx(int x){
    while(dsuparent[x]!=x){
        dsuparent[x] = dsuparent[dsuparent[x]];
        x = dsuparent[x];
    }
    return x;
}


void unionx(int x, int y){
    int rx = rootx(x);
    int ry = rootx(y);
    dsuparent[rx] = ry;
}

///
pii maxEdge(int x){
	int mi=-1, mv = -INF;
	int ei = -1;
	trav(incoming[x]){
		if(rootx(it.F)!=x && it.S.F > mv){
			mi = it.F;
			ei = it.S.S;
			mv = it.S.F;
		}
	}
	return {rootx(mi), ei};
}


void fillInc(int x, int oy){
    For(i, 0, n){
        if(rootx(i)==oy){          
            int y = i;  
            if(!present(incoming[x], y)) continue;
        	int eind = incoming[x][y].S;
        	int val = incoming[x][y].F;
            if(n==14){
                trace(x, y, eind, val);
            }
        	trav(incoming[x]){
        		if(present(st, rootx(it.F))){
                    continue;
        		}
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
    }
}



void solveCycle(int x, int y){
	int ry = rootx(y);
	int ty = ry;
    st.clear();
	while(ty!=x){
        vis[ty] = 2;
		st.insert(ty);
		ty = rootx(par[ty]);
	}
	st.insert(x);
    vis[x] = 2;
	int val, eind;
	ty = ry;
	while(ty!=x){
        if(n==14) trace(ty, rootx(par[ty]));
		fillInc(ty, rootx(par[ty]));
		ty = rootx(par[ty]);
	}
	fillInc(x, ry);
    ty = ry;
    while(ty!=x){
        unionx(ty, n);
        vis[ty] = 2;
        ty = rootx(par[ty]);
    }
    unionx(x, n);
}


void process(int x){
	if(sz(inchash)>=N) return;
    orderofx.pb(x);
	vis[x] = 1;
	pii p = maxEdge(x);
	int y = p.F;
    if(y<N) inchash.insert(y);
	int ed = p.S;
	best[x] = ed;
    trace(x, y, ed, vis[y], sz(inchash));
    // if(x!=11 && x!=4 && x!=3 && x!=13 && x!=6 && x!=14) return;
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
    unordered_set<int> st1;
    For(i, 0, N){
        st1.insert(best[i]);
    }

    // Make directed MST
    For(i, 0, N){
        trav(incoming[i]){
            if(present(st1, it.S.S)){
                adj[it.F].pb({i, it.S.F});
            }
        }
    }

    printMST();
}

vi ordervis(MAXN, 0);
vi rank_node;
void ordering(int x){
    trace(x);
    int rt=x;
    // if(rt==4) return ;
    priority_queue<pair<int, int> > pq;
    pq.push({0, rt});
    while(sz(pq)){
        pii p = pq.top();
        pq.pop();
        if(ordervis[p.S]) continue;
        ordervis[p.S] = 1;
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
	rFor(i, sz(orderofx)-1, 0){
		cout<<orderofx[i]<<" "<<best[orderofx[i]]<<endl;
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
    // #ifdef ROBOT
    //     freopen("/home/yell0wfl4sh/Competitive/input.txt", "r", stdin);
    //     freopen("/home/yell0wfl4sh/Competitive/output.txt", "w", stdout);
    // #endif
   //  vvi A{	{ -INF, 5, 1, 1 },
			// { -INF, -INF, 11, 4 },
			// { -INF, 10, -INF, 5 },
			// { -INF, 9, 8, -INF }};

    // vvi A{  { -INF, 8, 1, 1},
    //         { -INF, -INF, 5, 3},
    //         { -INF, 8, -INF, 2},50
    //         { -INF, 4, 7, -INF}};

    // vvi v{  { -INF, 51, 100, -INF},
    //         { 49, -INF, 51, 100},
    //         { 0, 49, -INF, 51},
    //         { -INF, 0, 49, -INF}};

    // vvi v{  { -INF, 55 , 65  , 70    , 75   ,95 },
    //         { 45 , -INF, 80  , 75    ,75    ,90 },
    //         { 35 , 20  , -INF, 75    , 60   ,80 },
    //         { 30 , 25  , 25  , -INF  , 30   ,45 },
    //         { 25 , 25  , 40  ,   70  , -INF ,70 },
    //         { 5  , 10  , 20  , 55    , 30   ,-INF}};

    // vvi v{  { 50 , 75 , 100 , 50  , 50   ,50 },
    //         { 25 , 50 , 75  , 50  , 50   ,50 },
    //         { 0  , 25 , 50  , 50  , 50   ,50 },
    //         { 50 , 50 , 50  , 50  , 75   ,100 },
    //         { 50 , 50 , 50  , 25  , 50   ,75 },
    //         { 50 , 50 , 50  , 0   , 25   ,50}};

    // vvi vx{ {0,  2,  11,  12,  6,  6,  13,  2,  7,  12,  6,  0,  0,  0},
    //         {0,  0,  1,   1,   2,  0,  1,   1,  0,  0,   0,  0,  0,  0},
    //         {9,  1,  0,   7,   7,  4,  16,  3,  9,  10,  2,  1,  2,  0},
    //         {8,  1,  14,  0,   9,  8,  10,  2,  9,  10,  3,  3,  0,  1},
    //         {12, 0,  12, 11,  0,  6,  11,  1,  10, 11,  4,  2,  1,   2},
    //         {4,  2,  8,   2,   4,  0,  5,   0,  4,  4,   0,  0,  0,  1},
    //         {8,  3,  5,   10,  9,  5,  0,   2,  6,  10,  4,  1,  1,  1},
    //         {3,  1,  1,   2,   3,  5,  2,   0,  0,  0,   0,  0,  0,  0},
    //         {8,  0,  6,   6,   6,  3,  10,  0,  0,  11,  2,  1,  1,  0},
    //         {7,  0,  6,   7,   5,  2,  12,  0,  6,  0,   4,  2,  1,  0},
    //         {5,  0,  7,   7,   7,  0,  6,   0,  7,  6,   0,  1,  0,  0},
    //         {5,  0,  4,   3,   3,  2,  5,   0,  4,  4,   3,  0,  0,  0},
    //         {2,  0,  0,   1,   1,  0,  0,   0,  1,  1,   1,  1,  0,  0},
    //         {2,  0,  2,   1,   0,  1,  1,   2,  0,  0,   0,  0,  0,  0}};


    //i loses to j
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

    print2v(vx);

    vvi v(13, vi(13, 0));
    // vector<vector<float> > v(14, vector<float>(14, 0));
    For(i, 0, 13){
        For(j, 0, 13){
            if(i==j){
                v[i][j] = .50;
            }else{
                int val = vx[i][j] + vx[j][i];
                if(val){
                    v[i][j] = (((float)vx[i][j]/(float)val)*100);
                }else{
                    v[i][j] = .50;
                }
            }
        }
    }

    // print2v(v);
    
    cout<<"START->"<<endl;
    int xxx = v.size();
    int yyy = v[0].size();

    vvi A(xxx, vi(yyy, 0));
    for(int i=0; i<xxx; i++){
        for(int j=0; j<yyy; j++){
            if(v[i][j] == 50){
                A[i][j] = -INF;
            }else{
                A[i][j] = v[i][j] / abs(50-v[i][j]);
            }
        }
    }

    // for(int i=0; i<13; i++){
    //     for(int j=0; j<13; j++){
    //         if(max(v[i][j], v[j][i])<50){
    //             // cout<<0<<" ";
    //         }else{
    //             float vxal = (float)(max(v[i][j], v[j][i])-50)/(float)100;
    //             cout<<vxal<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    // return 0;

    // print2v(v);
    // cout<<endl<<endl;

    For(i, 0, sz(A)){
        For(j, 0, sz(A[i])){
            if(A[i][j]==-INF){
                cout<<"-INF"<<" ";
                continue;
            }
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    n = sz(A);
    N = n;

    m=0;
    For(i, 0, n){
	    For(j, 0, n){
    		if(A[i][j]==-INF) continue;
    		incoming[j][i] = {A[i][j], m++};
    	}
    }

    // Make root to start process
    for(int i=0; i<n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(v[i][j]>v[j][i]) cnt++;
        }
        ord.pb({cnt, i});
    }
    sort(all(ord));
    // 

    initiliase();

    tcnt=0;
   	for(auto it: ord){
        // cout<<it.F<<" "<<it.S<<endl;
   		if(!vis[it.S]){
            trace(it.S);
   			process(it.S);
            break;
        }
   	}
    // return 0;


    // printGraph();
    printBest();
    // printKick();
    // For(i, 0, 6){
    // 	cout<<par[i]<<" ";
    // }
    // cout<<endl;

    rFor(ix, sz(orderofx)-1, 0){
    	int i = orderofx[ix];
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
    // ordering(11);
    ordering(12);
    cout<<endl<<endl;

    vi rank_node1{11, 10, 4, 12, 7, 3, 0, 1, 2, 8, 5, 6, 9};
    vector<vector<float> >  reordered(N, vector<float> (N, 0));
    rank_node.clear();
    rank_node = rank_node1;

    For(i, 0, N){
        For(j, 0, N){
            if(i==j){
                cout<<0<<" ";
                continue;
            }
            if(A[rank_node[i]][rank_node[j]]==-INF){
                reordered[i][j] = 0;
                cout<<0<<" ";
            }else if(A[rank_node[i]][rank_node[j]]==0){
                reordered[i][j] = 1;
                cout<<1<<" ";
            }else{
                reordered[i][j] = A[rank_node[i]][rank_node[j]];
                cout<<"1/"<<reordered[i][j]<<" ";
            }
        }
        cout<<";"<<endl;
    }

    // print2v(reordered);

    // end_routine()
    return 0;
}

