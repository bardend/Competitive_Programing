
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

const int maxn = 51;
vector<int>adj[maxn];
vector<int>adj2[maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){

        for(int i=0;i<maxn;i++)adj[i].clear();
        for(int i=0;i<maxn;i++)adj2[i].clear();

        int n;cin>>n;

        vector<int>frec(maxn,0);

        for(int i=0;i<n;i++){
            int ci;cin>>ci;
            for(int j=0;j<ci;j++){
                int num;cin>>num;
                frec[num]++;
                adj[num].pb(i);
                adj2[i].pb(num);
            }
        }
        int tot = 0;
        for(int i=0;i<maxn;i++) 
            if(frec[i]>0) tot++;

        int ans = 0;

        auto solve = [&](vector<int> a){
            int era = 0;
            for(int i=0;i<maxn;i++)
                if(frec[i]>0 and a[i] ==0) era++;
            if(era == 0) return 0;
            return tot-era;
        };

        for(int num_e =1;num_e<maxn;num_e++){

            for(int num=0;num<maxn;num++){

                if((int)adj[num].size() == num_e){

                    vector<int>tmp = adj[num];
                    vector<int>tmpf = frec;

                    for(auto e:tmp){
                        for(auto del:adj2[e]){
                            tmpf[del]--;
                        }
                    }

                    ans = max(ans, solve(tmpf));
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}










