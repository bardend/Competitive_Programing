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
const int maxn = 1e5+1;
vector<ii>adj[maxn];
const int msk = 1<<7;
int dis[maxn][msk];
int vis[maxn][msk];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    vector<int>spc(n,0);
    for(int i=0;i<k;i++){
        int x;cin>>x;
        x--;
        spc[x] = 1;
    }
    memset(dis,-1,sizeof(dis));
    memset(vis,-1,sizeof(vis));
    queue<ii>q;
    for(int i=0;i<n;i++)
        if(spc[i]){
            q.push({i,0});
            dis[i][0] = 0;
            vis[i][0] = 1;
        }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<float>ans(n,-1);

    while(!q.empty()){
        auto v = q.front();
        q.pop();
        ans[v.f] = max(ans[v.f], (dis[v.f][v.s]>0 ? float(v.s)/float(dis[v.f][v.s]) : -1));
        for(auto e:adj[v.f]){
            ii op = {e.f, v.s^e.s};
            if(vis[op.f][op.s] == -1){
                vis[op.f][op.s] = 1;
                dis[op.f][op.s] = dis[v.f][v.s] + 1;
                q.push(op);
            }
        }
    }

    int qq;
    cin>>qq;
    while(qq--){
        int u;
        cin>>u;
        u--;
        if(ans[u] == -1) cout<<"unreachable"<<endl;
        else cout<<setprecision(10)<<ans[u]<<endl;
    }

    return 0;
}
