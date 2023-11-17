
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

const int maxn = 2e5+5;
ll dp[maxn][2];
const ll inf = 1e18;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    int t;cin>>t;
    while(t--){

        int n;cin>>n;
        vector<ll>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];

        for(int i=1;i<=n+1;i++)
            dp[i][0] = dp[i][1] = -inf;

        dp[n+1][0] = 0ll;

        for(int i=n;i>=1;i--){
            for(int j=0;j<2;j++) 
                dp[i][j] = dp[i+1][j];

            if(i%2 == 1)
                dp[i][0] = max(dp[i][0], max(dp[i+1][0], dp[i+1][1])+a[i]);
            else {
                dp[i][1] = max(dp[i][1], max(dp[i+1][0], dp[i+1][1])+a[i]);
                dp[i][0] = max(dp[i][0], dp[i+1][1]);
            }
        }
        cout<<max(0ll, dp[1][0])<<endl;
    }
    return 0;
}
