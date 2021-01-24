/*
 * author : rits1272
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(x) cerr << "[" << #x << ": " << x << "]";
#define println(x) cerr << "[" << #x << ": " << x << "]\n";
#define show(v) for(int i = 0; i < (int)v.size(); i++) cout << v[i] << (i == (int)v.size()-1 ? "\n" : " ");
#define deb(v) for(int i = 0; i < (int)v.size(); i++) {print(i) println(v[i])}
#define pb push_back
#define INF 1e18 + 5
const int MOD = 1e9 + 7;

const int N = 20;
int n, m;
vector<int> adj[N];
int dp[N][1<<N];

int dfs(int u, int mask){
	// all cities has been visited
	if(__builtin_popcount(mask) == n){
		return 1;
	}
	// if we arrive at last city and all cities are not visited
	else if(u == n-1){
		return 0;
	}
	if(dp[u][mask] != -1){
		return dp[u][mask];
	}
	int path = 0;
	for(int v: adj[u]){
		if(mask & (1 << v)){
			continue;
		}
		path = (path + dfs(v, mask | (1 << v)))%MOD;
	}
	return dp[u][mask] = path;
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		--a, --b;
		adj[a].pb(b);
	}
	int ans = dfs(0, 1);
	cout << ans << "\n";
	return 0; 
}

/*
 * Only write code when you are sure of the approach.
 * Do optimized thinking (Think which technique/observation can be used).
 * Do post analysis after the contest.
 * Upsolve the problems.
 * Learn a technique and solve some problems if its new to you.
 * DON'T GET STUCK ON ONE APPROACH
 */ 

