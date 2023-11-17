
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
const int inf = 1e9+7;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int maxn = 3e5 ;
vector<ii>adj[maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,d;
    cin>>n>>k>>d;

    vector<int>col(n,-1);
    queue<int>q;
    for(int i=0;i<k;i++){
        int x;cin>>x;
        x--;
        col[x] = x;
        q.push(x);
    }

    for(int i=0;i<(n-1);i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }

    while(!q.empty()){
        auto v = q.front();
        q.pop();
        for(auto to:adj[v]){
            if(col[to.f] == -1){
                col[to.f] = col[v];
                q.push(to.f);
            }
        }
    }
    vector<int>vis(n,0);
    vector<int>ans;
    int cnt = 0;
    auto dfs = [&](int v, auto && dfs) ->void{
        vis[v]=  1;
        for(auto e:adj[v]){
            if(vis[e.f]) continue;
            if(col[e.f] != col[v]) {
                cnt++;
                ans.pb(e.s+1);
            }
            dfs(e.f,dfs);
        }
    };
    dfs(0,dfs);
    cout<<cnt<<endl;
    for(auto e:ans)
        cout<<e<<" ";
    return 0;
}
