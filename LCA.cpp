#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(x) cout << "[" << #x << ": " << x << "]";
#define println(x) cout << "[" << #x << ": " << x << "]\n";
#define show(v) for(int i = 0; i < (int)v.size(); i++) cout << v[i] << " ";
#define deb(v) for(int i = 0; i < (int)v.size(); i++) {print(i) println(v[i])}
#define pb push_back
#define INF 1e18 + 5
//int dx[] = { -1, 1, 0, 0 }; 
//int dy[] = { 0, 0, 1, -1 }; 

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int M = 20;
int n;
int level[M], lca[N][M+1];
vector<int> adj[N];

void dfs(int u, int lvl, int p){
	level[u] = lvl;
	lca[u][0] = p;
	for(int v: adj[u]){
		if(v != p){
			dfs(v, lvl+1, u);
		}
	}
}

int getLCA(int u, int v){
	if(level[v] < level[u]){
		swap(u, v);
	}
	int d = level[v] - level[u];
	while(d > 0){
		int i = log2(d);
		v = lca[v][i];
		d -= (1 << i);
	}
	if(u == v){
		return u;
	}
	for(int i = M; i >= 0; i--){
		if(lca[u][i] != -1 && (lca[u][i] != lca[v][i])){
			u = lca[u][i];
			v = lca[v][i];
		}
	}
	return lca[u][0];
}

int dist(int u, int v){
	int LCA = getLCA(u, v);
	return level[u] + level[v] - 2*level[LCA];
}

void reset(){
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= M; j++){
			lca[i][j] = -1;
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0, 0, -1);
	for(int i = 1; i <= M; i++){
		for(int j = 0; j < N; j++){
			if(lca[j][i-1] != -1){
				int p = lca[j][i-1];
				lca[j][i] = lca[p][i-1];
			}
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int tt = 1;
	cin >> tt;
	while(tt--){
		solve();
		reset();
	}
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " s" << '\n';
	return 0; 
}

/*
 * Techniques to look for: DP, Prefix sums, Graph, Sieve method, Binary Search, observation based?
 	Brute force?
 	DP (bitmasking with smaller constraints?)
 	Binary search
 	Two pointers
 	Prefix/suffix sums
 	Graph
 	Sieve method
 	Observation based aka adhoc
 */ 
