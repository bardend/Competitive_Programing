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

struct st{
    int v,ff,ss;
    bool operator<(const st& other)const{
        return ss > other.ss;
    }
};
const int maxn = 1e5 + 5;
vector<ii>adj[maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i += 1){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    priority_queue<st>pq;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto [v, ff, ss] = pq.top();
        pq.pop();
    }


    return 0;
}
