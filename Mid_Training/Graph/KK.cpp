#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define f first
#define s second 
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll 
#define max_bit(A) 31-__builtin_clz(A)
 
//cout << setprecision(12) << fixed;
 
/*mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}*/

int dx[]={0,1,-1,0};int dy[]={1,0,0,-1}; //4 Direction
const int maxn = 1000;
const int inf = 1e9;
int dis[maxn][maxn][4];

struct node{
    int x,y,dir,time;
};

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<string>cd(n);
    for(int i=0;i<n;i++)
        cin>>cd[i];

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--;y1--;x2--;y2--;


    auto valid = [&](int x, int y){
        return (x>=0 and x<n and y>=0 and y<m and cd[x][y] == '.');
    };

    queue<node>q;
    memset(dis,-1,sizeof(dis));

    for(int i=0;i<4;i++)
        dis[x1][y1][i] = 0;

    for(int i=0;i<4;i++){
        int nx, ny;
        nx = x1 + dx[i], ny = y1 + dy[i];
        if(!valid(nx,ny)) continue;
        dis[nx][ny][i] =  1;
        node tmp= {nx,ny,i,k-1};
        q.push(tmp);
    }

    int nx,ny;

    while(!q.empty()){
        node v = q.front();
        q.pop();
        nx = v.x + dx[v.dir], ny = v.y + dy[v.dir];
       if(v.time>0 and valid(nx,ny) and (dis[nx][ny][v.dir] == -1 or dis[nx][ny][v.dir]>dis[v.x][v.y][v.dir])){
            dis[nx][ny][v.dir] = dis[v.x][v.y][v.dir];
            node tmp = {nx, ny, v.dir, v.time-1};
            q.push(tmp);
        }
        for(int i=0;i<4;i++){
            nx = v.x + dx[i], ny = v.y + dy[i];
            if(!valid(nx,ny))continue;
            if(dis[nx][ny][i] == -1){
                dis[nx][ny][i] = dis[v.x][v.y][v.dir] + 1;
                node tmp = {nx, ny, i, k-1};
                q.push(tmp);
            }
        }
    }

    int ans = inf;
    for(int i=0;i<4;i++)
        if(dis[x2][y2][i] != -1)
            ans = min(dis[x2][y2][i], ans);

    if(ans == inf) cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}
