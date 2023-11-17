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
    for(int tt=1;tt<=t;tt++){
        ll n,k,mod,sum;
        cin>>n>>k>>mod;
        sum = 0ll;
        for(int i=0;i<n;i++){
            ll x;cin>>x;
            sum += x;
        }


        auto mul = [&](ll a, ll b) -> ll{
            return (a*b)%mod;
        };

        auto fstpw = [&](ll b, ll exp, auto && fstpw) -> ll{
            if(exp == 0) return 1ll;
            ll ret = fstpw(b, exp/2,fstpw);
            ret = mul(ret,ret);
            if(exp&1) ret = mul(ret, b);
            return ret;
        };
        //cout<<k<<" "<<n<<" "<<sum<<endl;
        //cout<<fstpw(n,k-1,fstpw)<<endl;
        cout<<"Case "<<tt<<": "<<mul(k,mul(fstpw(n,k-1,fstpw),sum))<<endl;
    }
    return 0;
}
