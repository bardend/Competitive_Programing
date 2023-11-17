
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


const int maxn = 1e5;

int dis[maxn][2]; // min dis par and impar
vector<int>adj[maxn];
vector<int> minp, primes;

 
constexpr int V = 1E7;
 
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    sieve(V);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    s--;t--;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(dis,-1,sizeof(dis));
    queue<ii>q;
    q.push({s,0});
    dis[s][0] = 0 ; // dis s par is 0

    while(!q.empty()){
        ii v = q.front();
        q.pop();
        for(auto e:adj[v.f]){
            if(dis[e][v.s^1] == -1){
                dis[e][v.s^1] = dis[v.f][v.s] + 1;
                q.push({e,v.s^1});
            }
        }
    }

    int mini = 1e9;
    for(auto e:primes){
        if(dis[t][0]!=-1 and e>= dis[t][0] and !((e-dis[t][0])&1)) mini = min(mini, e);
        if(dis[t][1]!=-1 and e>= dis[t][1] and !((e-dis[t][1])&1)) mini = min(mini, e);
    }

    if(mini == 1e9) cout<<"-1"<<endl;
    else cout<<mini<<endl;

    return 0;
}
