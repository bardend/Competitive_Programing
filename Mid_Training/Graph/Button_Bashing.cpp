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

const int maxn = 10000;
const int lim = 3600;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int n,target;
        cin>>n>>target;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];

        vector<int>dp(maxn,-1);
        queue<ii>q;
        q.push({0,0});
        while(!q.empty()){
            auto v = q.front();
            q.pop();

            v.f = max(v.f, 0);
            v.f = min(v.f, lim);
            
            if(dp[v.f] != -1) continue;
            dp[v.f] = v.s;

            for(auto e:a)
                q.push({v.f+e, v.s+1});
        }

        int ans,dif;
        ans = -1;

        for(int i=target;i<maxn;i++){
            if(dp[i] != -1){
                ans = dp[i];
                dif = i-target;
                break;
            }
        }
        if(ans != -1)
            cout<<ans<<" "<<dif<<endl;
        else 
            cout<<"0 "<<target<<endl;
    }
    return 0;
}
