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
        int n;
        cin>>n;
        vector<string>cd(n);
        for(int i=0;i<n;i++)
            cin>>cd[i];

        vector<vector<vector<int>>>v(4, vector<vector<int>>(n,vector<int>(n)));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                v[0][i][j] = (cd[i][j] - 'a');

        auto rotate = [&](vector<vector<int>>v)->vector<vector<int>> {
            int n = (int)v.size();
            vector<vector<int>>ret(n,vector<int>(n));
            for(int col=0;col<n;col++)
                for(int row = n-1; row>=0; row--)
                    ret[col][(n-1)-row] = v[row][col];
            return ret;
        };
        for(int i=1;i<4;i++)
            v[i] = rotate(v[i-1]);

        int ans = 0;

        for(int i=0;i<(n/2);i++){
            int ini,fin;
            ini = i, fin = (n-1)-i;
            for(int j=ini;j<fin;j++){
                vector<int>tmp;
                for(int k=0;k<4;k++)
                    tmp.pb(v[k][i][j]);
                int mx = *max_element(all(tmp));
                int sum = accumulate(all(tmp),0);
                ans += 4*mx - sum;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
