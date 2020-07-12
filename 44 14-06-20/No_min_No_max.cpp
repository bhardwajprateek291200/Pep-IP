#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff                  first
#define ss                  second
#define int                 long long
#define pb                  push_back
#define mp                  make_pair
#define pii                 pair<int,int>
#define vi                  vector<int>
#define mii                 map<int,int>
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int,vi,greater<int> >
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define mod                 1000000007
#define inf                 1e18
#define ps(x,y)             fixed<<setprecision(y)<<x
#define mk(arr,n,type)      type *arr=new type[n]()
#define del(arr)            delete [] arr
#define mkm(arr,n,m,type)   type** arr = new type*[n]; for(int i=0;i<n;i++)arr[i]=new int[m]()
#define delm(arr,n,m)       for(int i=0;i<n;i++)delete [] arr[i]; delete [] arr;
#define w(x)                int x; cin>>x; while(x--)
#define pw(b,p)             pow(b,p) + 0.1
#define fastio              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define db1(x)              cout<<#x<<"="<<x<<'\n'
#define db2(x,y)            cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z)          cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n)            for(int i=0;i<(n);++i)
#define repA(i,a,n)         for(int i=a;i<=(n);++i)
#define repD(i,a,n)         for(int i=a;i>=(n);--i)
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve() {
	int n, k;
	cin >> n >> k;
	mk(arr, n, int);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int32_t main()
{
	// c_p_c();
	fastio;
	int t = 1;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		cout << "test case # " << T << endl;
		// clock_t z = clock();
		solve();
		// cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
	}
	return 0;
}