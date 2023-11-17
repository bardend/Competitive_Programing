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

const int maxn = 2e5;
vector<int>adj[maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<ll>a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            adj[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<ll>dp(n,0);
        vector<int>sz(n);
        auto dfs = [&](int v, int p, auto &&dfs) -> void {
            sz[v]  = 1;
            for(auto to : adj[v]){
                if( to == p ) continue;
                dfs(to, v, dfs);
                sz[v] += sz[to];
                dp[v] += dp[to] + (a[v] ^ a[to]) * sz [to];
            }
        };

        auto dfs2 = [&](int v, int p, auto &&dfs2) -> void {
            for(auto to : adj[v]){
                if( to == p) continue;
                ll cur = dp[v] - dp[to] - (a[v] ^ a[to]) * sz[to];
                dp[to] += cur + (a[v] ^ a[to]) * (sz[v] - sz[to]);
                sz[to] = sz[v];
                dfs2(to, v, dfs2);
            }
        };
        dfs(0, -1, dfs);
        dfs2(0, -1, dfs2);
        for(auto e: dp)  cout << e << " ";
        cout << endl;
    }
    return 0;
}
