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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // Mt19937 random seed

long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng); // Random generator
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ofstream out("in.txt");
    int t;
    t = 100;
    out<<t<<endl;
    while(t--){
        int n = random(1,20);
        out<<n<<endl;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            int x = random(1,20);
            a[i] = x;
            out<<a[i]<<" ";
        }
        out<<endl;

        auto good = [&](int pos, const vector<ii> &v, auto && good) -> int{
            int end = (int)v.size();
            if(pos >= end){
                if(pos == end) return 1;
                return 0;
            }
            return good(pos + v[pos].f +1, v, good);
        };

        int ans = 0;
        for(int msk = 0;msk<(1<<n);msk++){
            vector<ii>tmp;
            for(int bit=0;bit<n;bit++){
                if((msk>>bit)&1){
                    tmp.pb({a[bit], bit});
                }
            }
            
            if((int)tmp.size()>0 and good(0, tmp, good))
                ans = max(ans, (int)tmp.size());
        }
        out<<n-ans<<endl;
    }
    return 0;
}
