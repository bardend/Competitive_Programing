
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

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(2*n);
        for(int i = 0 ; i < 2 * n;  i++)
            cin >> a[i];

        sort(all(a));
        vector<int>aa;
        vector<int>bb;

        for(int i = 0 ; i < n ; i++) aa.pb(a[i]);
        for(int i = n ; i < 2 * n ; i++) bb.pb(a[i]);

        vector<ii>res(n);
        int ans = 0;

        res[0] = {aa[0], bb[0]};
        for(int i = 1 ; i < n ; i++){
            ans += aa[i] - aa[i-1];
            ans += bb[i] - bb[i-1];
            res[i] = {aa[i], bb[i]};
        }
        cout << ans << endl;
        for(auto e : res )
            cout << e.f << " " << e.s << endl;
    }
    return 0;
}
