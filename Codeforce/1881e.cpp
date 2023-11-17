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

const int maxn = 2e5+1;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ifstream in("in.txt");
    ofstream out("found.txt");

    int t;

    in>>t;
    out<<t<<endl;

    while(t--){
        int n;

        in>>n;
        out<<n<<endl;

        vector<int>a(n);
        for(int i=0;i<n;i++){
            in>>a[i];
            out<<a[i]<<" ";
        }
        out<<endl;

        int qwe;
        in>>qwe;

        vector<int>dp(n+1,inf);
        dp[n] = 0;

        for(int i=n-1;i>=0;i--){

            // delete
            dp[i] = min(dp[i], 1+dp[i+1]);
            int nxt = i + a[i] + 1;
            // take
            if(nxt <=n )
                dp[i] = min(dp[i], dp[nxt]);
        }
        cout<<dp[0]<<endl;
        out<<dp[0]<<endl;
    }
    return 0;
}
