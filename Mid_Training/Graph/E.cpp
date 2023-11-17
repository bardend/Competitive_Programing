
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

const int maxn = 4001;
const int inf = 1e9;
vector<int>adj[maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m;
    cin>>n>>m;
    map<pair<int,int>,int>mp;
    vector<int>dg(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        dg[a]++;
        dg[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
        mp[{a,b}] = mp[{b,a}] = 1;
    }

    int ans = inf;

    for(int i=0;i<n;i++){
        for(auto e1:adj[i]){
            for(auto e2:adj[i]){
                if(mp.find({e1,e2}) != mp.end()){
                    ans = min(ans, dg[i] + dg[e1] + dg[e2] - 6);
                }
            }
        }
    }
    if(ans != inf) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
