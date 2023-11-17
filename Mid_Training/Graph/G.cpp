
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

const int maxn = 1003;

int vis[maxn];
vector<ii>ans;
map<pair<int,int>,int>mp;
int n,m;

void dfs(int v){
    vis[v] = 1;
    for(int i=0;i<n;i++){
        if(i==v)continue;
        if(vis[i] or mp.find({v,i}) != mp.end()) continue;
        ans.pb({v,i});
        dfs(i);
    }
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        mp[{u,v}] = 1;
        mp[{v,u}] = 1;
    }
    dfs(0);
    cout<<(int)ans.size()<<endl;
    for(auto e:ans)
        cout<<e.f+1<<" "<<e.s+1<<endl;
    return 0;
}
