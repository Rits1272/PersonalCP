/*
 * author : rits1272
 */

#include <cinttypes>
#include <cstdlib>
#include<iostream>
#include <unordered_map>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<algorithm>
#include<cassert>
#include<stdlib.h>
#include<string>
using namespace std;

#define int long long
#define print(x) cerr << "[" << #x << ": " << x << "]";
#define println(x) cerr << "[" << #x << ": " << x << "]\n";
#define show(v) for(int i = 0; i < (int)v.size(); i++) cout << v[i] << (i == (int)v.size()-1 ? "\n" : " ");
#define deb(v) for(int i = 0; i < (int)v.size(); i++) {print(i) println(v[i])}
#define pb push_back
#define INF 1e18 + 5
//int dx[] = { -1, 1, 0, 0 }; 
//int dy[] = { 0, 0, 1, -1 }; 
 
const int MOD = 1e9 + 7;

void test_case(){

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifdef ONLINEJUDGE
       clock_t tStart = clock();
       freopen("in.txt","r",stdin);
       freopen("out.txt","w",stdout);
 	#endif
	int tt = 1; 
	cin >> tt;
	while(tt--){
	    test_case();
	}
	#ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  	#endif
	return 0; 
}

