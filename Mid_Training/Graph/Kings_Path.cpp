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
const int inf = 1e9;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
const int maxn = 1e5+2;
int main(){
   	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int x0,y0,x1,y1,n;
    cin>>x0>>y0>>x1>>y1>>n;

    map<int,int>mp;
    set<ii>st;

    for(int i=0;i<n;i++){
        int r,a,b;
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++)
            st.insert({r,j});
    }

    auto valid = [&](int x, int y) ->bool{
        int ok = (x>0 and y>0 and x<=inf and y<=inf);
        if(ok)
            return st.count({x,y});
        return false;
    };

    queue<pair<ii,int>>q;
    q.push({{x0,y0},0});

    map<ll,int>vis;
    vis[1ll*x0*inf+y0] = 1;

    int ans =-1;
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        if(v.f.f == x1 and v.f.s == y1){
            ans = v.s;
            break;
        }

        for(int i=0;i<8;i++){
            int nx,ny;
            nx = v.f.f + dx[i], ny = v.f.s + dy[i];
            if(valid(nx,ny) and !vis.count(1ll*nx*inf+ny)){
                vis[1ll*nx*inf+ny] = 1;
                q.push({{nx,ny},v.s+1});
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
