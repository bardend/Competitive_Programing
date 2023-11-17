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

const int inf = 2e9;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int>a(n), b(m);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];
        sort(all(b));

        vector<int>res;
        vector<int>cur;
        int ind,mini,ii;
        ind = m - 1, mini = inf;

        for(int  i = 0; i < n; i++) {
            while(ind >= 0 and b[ind] >= a[i]) {
                res.pb(b[ind]);
                ind -= 1;
            }
            res.pb(a[i]);
            if(a[i] <= mini) {
                mini = a[i];
                ii = (int)res.size() - 1;
            }
        }
        for(int i = 0; i < (int)res.size(); i++){
            cout << res[i] << " ";
            if( i == ii){
                while(ind >= 0) {
                    cout << b[ind] << " ";
                    ind -= 1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}

