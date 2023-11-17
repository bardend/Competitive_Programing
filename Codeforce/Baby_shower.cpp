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


const int maxn = 1000;
int dp[maxn][maxn];
int solve(const string  &cd, int i, int j){
    if(i>=j)return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int extra = inf;
    if(cd[i] == cd[j] ) extra = solve(cd,i+1,j-1);
    int op1 = solve(cd,i+1,j)+1;
    int op2 = solve(cd,i,j-1)+1;
    int op3 = solve(cd,i+1,j-1)+1;

    return dp[i][j] = min(op1,min(op2,min(extra,op3)));
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    for(int i=1;i<=tt;i++){
        string cd;
        cin>>cd;
        int n = (int)cd.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = -1;
        cout<<"Prueba "<<i<<": "<<solve(cd,0,n-1);
        if(i<tt)cout<<endl;
    }
    return 0;
}

