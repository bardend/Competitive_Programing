
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

const int maxn = 1e5+1;
vector<int>adj[maxn];
int main(){
    /*
     * Que pasa si analizamos el problema de atraz hacia delante
     * (estamos a 1 dia de terminar todo ) , (estamos a 2 dias .. ,
     * (estamos a m dias de terminar ).
     * nos daremos cuenta que es mas facil de lo que pensabamos
     */
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ii>a(n);
    for(int i = 0; i < n ; i++){
        int day,win;
        cin >> day >> win;
        adj[day].pb(win);
    }

    ll ans = 0ll;
    priority_queue<int>pq;

    for(int i = 1 ; i <= m ; i++){

        for(auto e:adj[i])
            pq.push(e);

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
