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

const int maxn = 3000;
const int inf = 1e9+7;

vector<int>adj[maxn];
int vis[maxn][maxn];
int pre[maxn][maxn];
set<tuple<int,int,int>>st;


struct edge{
    int u,v,val;
    edge(int u, int v, int val) :   u(u), v(v), val(val){}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(vis,-1,sizeof(vis));
    memset(pre,-1,sizeof(pre));


    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;c--;
        st.insert(make_tuple(a,b,c));
    }
    edge init = edge(n,0,0);
    queue<edge>q;
    q.push(init);
    // v.f.f= now, v.f.s = pre, v.s = longitud
    //
    int ff,ss,ok;
    ok = 0;
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        //cout<<v.u<<" "<<v.v<<" "<<v.val<<endl;
        if(v.v == (n-1)){
            ff = v.v;
            ss = v.u;
            ok = 1;
            break;
        }
        for(auto e:adj[v.v]){
            if(st.count(make_tuple(v.u,v.v,e))) continue;
            if(vis[v.v][e] == -1){
                edge tmp = edge(v.v,e,v.val+1);
                q.push(tmp);
                pre[e][v.v] = v.u;
                vis[v.v][e] = 1;
            }
        }
    }
    if(!ok) {cout<<"-1"<<endl;return 0;}
    else if(n == 1){
        cout<<"0"<<endl;
        cout<<"1"<<endl;
        return 0;
    }

    vector<int>wlk;
    wlk.pb(ff);
    wlk.pb(ss);
    int tmp = pre[ff][ss];
    while(ss!= 0){
        wlk.pb(tmp);
        if(tmp == 0) break;
        ff = ss;
        ss = tmp;
        tmp = pre[ff][ss];
    }
    cout<<(int)wlk.size()-1<<endl;
    reverse(all(wlk));
    for(auto e:wlk) cout<<e+1<<" ";
    cout<<endl;
    return 0;
}
