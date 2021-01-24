#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(x) cout << "[" << #x << ": " << x << "]";
#define println(x) cout << "[" << #x << ": " << x << "]\n";
#define pb push_back
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define INF 1e18 + 5
#define MOD 1e9 + 7

// This code assumes that the graph has euler path.

const int N = 2e5;
int n, m;
vector<int> adj[N];

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m;
    unordered_map<int,int> mp;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a, --b;
        mp[a]++;
        adj[a].pb(b);
        // mp[b]++;
        // adj[b].pb(a);
    }
    stack<int> s;
    int cv = 0;
    s.push(cv);
    vector<int> path;
    while(s.size()){
        if(mp[cv]){
            s.push(cv);
            int nv = adj[cv].back();
            adj[cv].pop_back();
            mp[cv]--;
            cv = nv;
        }
        else{
            path.pb(cv);
            cv = s.top();
            s.pop();
        }
    }
    reverse(path.begin(), path.end());
    for(int x: path){
        cout << x+1 << " ";
    }
	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " s" << '\n'; 
}

