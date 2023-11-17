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

const int maxn = 3e5 +1;
vector<int>adj[maxn];
vector<int>c[maxn];

/* We fix the rows then a greedy idea would be you take the best
 * columns but we take into consideration if it shares an element
 */

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int h,w,m,maxi;
    maxi = 0;
    cin >> h >> w >> m;
    for(int i = 0; i < m; i++){
        int row,col;
        cin >> row >> col;
        adj[row].pb(col);
        c[col].pb(row);
        maxi = max(maxi, (int)c[col].size());
    }
    
    for(int i = 0; i < maxn; i++)
        sort(all(adj[i]));

    vector<int>bst;
    for(int i = 0; i < maxn; i++)
        if((int)c[i].size() == maxi) 
            bst.pb(i);

    int lbst = (int)bst.size();
    int ans = 0;

    for(int i = 0; i < maxn; i++) {

        int l = (int)adj[i].size();
        int ii ,ok;
        ii = 0, ok = 1;

        for(int j = 0; j < l; j++){

            while( j < l and ii < lbst and adj[i][j] < bst[ii] )
                j++;

            if(j == l) break;

            if( ii < lbst and bst[ii] == adj[i][j]) 
                ii += 1;
            else if ( ii < lbst) 
                ok = 0;
        }
        if( ii < lbst) ok = 0;
        ans = max(ans, l + maxi - ok);
    }
    cout << ans << endl;
    return 0;
}
