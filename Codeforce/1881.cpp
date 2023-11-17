
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
    auto is = [&](string x, string y){
        int n,m;
        n = (int)x.size();
        m = (int)y.size();
        if((int)y.size() >(int)x.size()) return 0;
        // y in x


        for(int i=0;i<=(n-m);i++){
            string cur = x.substr(i,m);
            if(cur == y) return 1;
        }
        return 0;
    };

    while(t--){

        int n,m;
        string x,target;
        cin>>n>>m>>x>>target;
        int ok = 0;
        for(int i=0;i<10;i++){
            if(is(x,target)) {
                cout<<i<<endl;
                ok = 1;
                break;
            }
            x = x + x;
        }
        if(!ok) cout<<"-1"<<endl;
    }
    return 0;
}
