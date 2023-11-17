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

const int maxn =  2000;
int vis[maxn][maxn];

struct node{
    int x,y,k;
    bool operator<(const node &other) const{
        return other.k > k;
    }
};

int dx[] = {0,1};
int dy[] = {1,0};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<string>boar(n);
    for(int i=0;i<n;i++)
        cin>>boar[i];

    if(boar[0][0] != 'a' and k >0){
        boar[0][0] = 'a';
        k--;
    }
    priority_queue<node>q;
    q.push({0,0,k});

    char nxt = boar[0][0];
    auto valid =[&](int x, int y){
        return x>=0 and y>=0 and x<n and y<n ;
    };
    string ans = "";

    while(!q.empty()){
        priority_queue<node>q2;
        char bound = nxt;
        nxt = 'z';
        ans += bound;
        while(!q.empty()){
            auto v = q.top();
            q.pop();
            if(boar[v.x][v.y] > bound) continue;
            for(int i=0;i<2;i++){
                int nx,ny;
                nx = v.x + dx[i], ny = v.y + dy[i];
                if(valid(nx,ny) and !vis[nx][ny]){
                    node tmp;
                    vis[nx][ny] = 1;
                    if(boar[nx][ny] == 'a') 
                        tmp = {nx,ny,v.k};
                    else {
                        if(v.k > 0){
                            boar[nx][ny] = 'a';
                            tmp = {nx,ny,v.k-1};
                        }
                        else 
                            tmp = {nx,ny,v.k};
                    }
                    q2.push(tmp);
                    nxt = min(nxt, boar[nx][ny]);
                }
            }
        }
        q = q2;
    }
    cout<<ans<<endl;
    return 0;
}
