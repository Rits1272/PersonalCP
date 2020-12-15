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
const int N = 5000000 + 5;

vector<int> pf(N);

void sieves(){
	pf[1] = 1;
	for(int i = 2; i < N; i++){
		pf[i] = i;
	}
	for(int i = 4; i < N; i += 2){
		pf[i] = 2;
	}
	for(int i = 3; i < N; i++){
		if(pf[i] == i){
			for(int j = i*i; j < N; j += i){
				if(pf[j] == j){
					pf[j] = i;
				}
			}
		}
	}
}

int factors(int x){
	// Total prime factors including their exponent
	int res = 0;
	while(x > 1){
		x/=pf[x];
		++res;
	}
	return res;
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	sieves();
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

