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
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int inf = 1e9+7;
const int maxn = 300+1;
int boar[maxn][maxn];
vector<ii>adj[(maxn+1)*(maxn+1)];
int best[maxn][maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,m,p;
    cin>>n>>m>>p;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>boar[i][j];
            adj[boar[i][j]].pb({i,j});
        }
    }
    adj[0].pb({0,0});


    auto valid = [&](int x, int y) -> bool{
        return (x>=0 and y>=0 and x<n and y<m);
    };
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            best[i][j] = inf;

    for(int i=0;i<maxn;i++)
        best[i][i] = 0;

    for(int i=0;i<p;i++){

        int pre = i;
        vector<vector<int>>dis(n,vector<int>(m,-1));

        queue<ii>q;
        for(auto e:adj[i]){
            dis[e.f][e.s] = 0;
            q.push(e);
        }

        int ans = inf;
        int ok = 0;

        while(!q.empty()){
            auto v = q.front();
            if(boar[v.f][v.s] == pre+1){
                ans = dis[v.f][v.s];
                break;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int nx,ny;
                nx = v.f + dx[i], ny = v.s + dy[i];
                if(!valid(nx,ny))continue;
                if(dis[nx][ny] == -1){
                    if(boar[nx][ny] == pre+1){
                        ans = dis[v.f][v.s] + 1;
                        ok = 1;
                        break;
                    }
                    dis[nx][ny] = dis[v.f][v.s] + 1;
                    q.push({nx,ny});
                }
            }
            if(ok) break;
        }
        best[i][i+1] = ans;
    }
    for(int lon=1;lon<=p;lon++){
        for(int i=0;i<=p-lon;i++){
            int end = i+lon;
            for(int mid=i;mid<end;mid++){
                best[i][end] = min(best[i][end], best[i][mid] + best[mid][end]);
            }
        }
    }
    cout<<best[0][p]<<endl;
    return 0;

}
