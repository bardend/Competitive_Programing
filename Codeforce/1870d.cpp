
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

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        priority_queue<ii>pq;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            pq.push({-x,i});
        }
        cin>>k;
        int bound = -1;
        vector<ii>v;
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            if(e.s > bound){
                v.pb({-e.f, e.s});
                bound = e.s;
            }
        }
        vector<int>pre(n+1,0);

        pre[v[0].s] = k/v[0].f;
        k = k%v[0].f;

        int nl = (int)v.size();
        for(int i=0;i<(nl-1);i++){
            int best = min(pre[v[i].s], k/(v[i+1].f-v[i].f));
            pre[v[i].s] -= best;
            pre[v[i+1].s] += best;
            k -= (best*(v[i+1].f-v[i].f));
        }

        for(int i=n-1;i>=0;i--) pre[i] += pre[i+1];
        for(int i=0;i<n;i++) cout<<pre[i]<<" ";
        cout<<endl;
    }
    return 0;
}
