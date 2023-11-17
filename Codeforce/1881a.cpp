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

const int maxn = 10;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x,y;
        cin>>x>>y;

        auto in = [&](string a, string b) -> bool{ // a in b
            int n = (int)a.size();
            int m = (int)b.size();
            for(int i=0;i<=(m-n);i++){
                string cd = b.substr(i,n);
                if(cd == a) return true;
            }
            return false;
        };

        if(in(y,x)) {
            cout<<"0"<<endl;
            continue;
        }
        
        int ok = 0;
        for(int i=1;i<maxn;i++){
            x+=x;
            if(in(y, x)) {
                cout<<i<<endl;
                ok = 1;
                break;
            }
            if(int(x.size()) > 2 * int(y.size()))
                break;
        }
        if(!ok) cout<<"-1"<<endl;
    }
    return 0;
}
