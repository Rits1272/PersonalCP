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
const int N = 2e5 + 5;

vector<int> fact(N);

int power(int x, int y){
	int res = 1;
	x %= MOD;
	while(y > 0){
		if(y&1){
			res = (res * x) % MOD;
		}
		x = (x * x) % MOD;
		y >>= 1;
	}
	return res;
}

int modInverse(int n){
	return power(n, MOD-2);
}

int ncr(int n, int r){
	if(n < r){
		return 0;
	}
	if(r == 0){
		return 1;
	}
	return ((fact[n] * modInverse(fact[r])) % MOD * modInverse(fact[n-r]))%MOD;
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	fact[0] = 1;
	for(int i = 1; i < N; i++){
		fact[i] = (fact[i-1] * i) % MOD;
	}
	//cout << ncr(5,2);
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

