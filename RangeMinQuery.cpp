/*
 * author : rits1272
 */

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(x) cerr << "[" << #x << ": " << x << "]";
#define println(x) cerr << "[" << #x << ": " << x << "]\n";
#define show(v) for(int i = 0; i < (int)v.size(); i++) cout << v[i] << (i == (int)v.size() ? "\n" : " ");
#define deb(v) for(int i = 0; i < (int)v.size(); i++) {print(i) println(v[i])}
#define pb push_back
#define INF 1e18 + 5
const int MOD = 1e9 + 7;

void build(vector<int> &tree, vector<int> &a, int v, int tl, int tr){
	if(tl > tr){
		return;
	}	
	if(tl == tr){
		tree[v] = a[tl];
	}
	else{
		int tm = (tl + tr)/2;
		build(tree, a, 2*v, tl, tm);
		build(tree, a, 2*v+1, tm+1, tr);
		tree[v] = min(tree[2*v], tree[2*v+1]);	
	}
}

int query(vector<int> &tree, int v, int tl, int tr, int ql, int qr){
	if(ql > tr || tl > qr){
		return INT_MAX;
	}
	if(tl >= ql && tr <= qr){
		return tree[v];
	}
	int tm = (tl + tr)/2;
	return min(query(tree, 2*v, tl, tm, ql, qr), query(tree, 2*v+1, tm+1, tr, ql, qr));
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> tree(4*n+1);
	build(tree, a, 1, 0, n-1);
	//cout << query(tree, 1, 0, n-1, 4, n-1) << "\n";
	return 0; 
}
