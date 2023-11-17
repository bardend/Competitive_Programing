
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

const ll inf = 1e18;
const int maxn = 5001;
ll dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            dp[i][j] = -1;

    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);
    vector<ll>sum(n+1);

    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a.begin()+1,a.end());

    sum[0] = 0ll;
    for(int i=1;i<n;i++) sum[i] = sum[i-1] + (a[i+1]-a[i]);

    int r = (n-1)/k;

    int cnt ,cur;
    cnt = 0, cur = 1+r*k;

    while(cur<=n){
        cnt++;
        cur++;
    }

    pair<int,int>t1,t2;
    t1 = {cnt, r+1};
    t2 = {k-cnt, r};

    //cout<<t1.f<<" "<<t1.s<<endl;
    //cout<<t2.f<<" "<<t2.s<<endl;

    auto solve = [&](int pos, ii x, ii y, auto &&solve) -> ll {
        if(pos == 0){
            if(x.f == 0 and y.f == 0) return 0ll;
            return inf;
        }
        if(x.f<0 or y.f<0) return inf;
        if(dp[x.f][y.f] != -1) return dp[x.f][y.f] ;

        ll op1,op2;

        op1 = (sum[pos-1]-sum[pos-x.s]) + solve(pos-x.s, {x.f-1,x.s}, y, solve);
        op2 = (sum[pos-1]-sum[pos-y.s]) + solve(pos-y.s, x, {y.f-1,y.s}, solve);

        /*
        cout<<"==============================="<<endl;
        cout<<"pos :"<<pos<<endl;
        cout<<"op1 :"<<(sum[pos]-sum[pos-x.s])<<endl;
        cout<<"op2 :"<<(sum[pos]-sum[pos-y.s])<<endl;
        */

        return dp[x.f][y.f] = min(op1,op2);
    };

    cout<<solve(n,t1,t2,solve)<<endl;

    return 0;
}
