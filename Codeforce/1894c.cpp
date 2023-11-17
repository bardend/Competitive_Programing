#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define f first 
#define s second 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

int mod ;
int sub(int x, int y) {
    return ((x-y) + mod ) % mod;
}
int add(int x, int y){
    return (x + y )% mod;
}

const int maxn = 2e5 + 1;
vector<int>adj[maxn];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
	int n,k;
	cin >> n >> k;
	mod = n;
	vector<int>a(n);
	for(int i = 0 ;i < n; i++){
	    cin >> a[i];
	    adj[i].clear();
	}
	vector<int>need(n,-1);
	for(int i = 0; i < n; i++){
	    if(a[i] > n) continue;
	    need[i] = sub(a[i]-1, add(i, a[i]));
	    adj[need[i]].pb(a[i]);
	}

	vector<int>vis(n,0);
	int ok = 0;

	auto dfs = [&](int rotate, int cnt, auto &&dfs)-> void{
	    if(cnt == k  or vis[rotate]) { ok = 1; return ;}
	    vis[rotate] = 1;
	    for(auto to : adj[rotate])
		dfs((rotate + to) % n, cnt + 1, dfs);
	};
	dfs(0, 0, dfs);
	
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
    }
    return 0;
}

