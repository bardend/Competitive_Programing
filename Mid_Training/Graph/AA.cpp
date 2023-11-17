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
const int maxn = 105;
vector<int>adj[maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,k;
        cin>>u>>k;
        for(int j=0;j<k;j++){
            int x;cin>>x;
            adj[u].pb(x);
        }
    }

    vector<int>dis(n+1, -1);
    queue<ii>q;
    q.push({1,0});
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        if(dis[v.f] != -1) continue;
        dis[v.f] = v.s;
        for(auto e:adj[v.f]){
            q.push({e,v.s+1});
        }
    }
    for(int i=1;i<=n;i++) cout<<i<<" "<<dis[i]<<endl;
    return 0;
}
