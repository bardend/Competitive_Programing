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

const int maxn = 63;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    auto fb = [&](ll b, ll x) -> int { // base ^ ret <= x
        int ret = 1;
        for(int i=0;i<maxn;i++){
            if(ret > x) return i-1;
            ret *= b;
        }
        return ret;
    };
    auto f = [&](ll num) -> int{
        return fb(fb(2, num), num);
    };


    vector<ll>sum(maxn,0);

    for(int i=2;i<maxn;i++){
        ll val,lo,hi,mi,bound;
        lo = (1ll<<i), hi = (1ll<<(i+1)) - 1, val = f(1ll<<i);
        bound = hi;
        while(lo<hi){
            mi = (hi - lo + 1) / 2 + lo ;
            if(f(mi) == val) lo = mi;
            else hi = mi-1;
        }
        sum[i] = sum[i-1];
        sum[i] += (lo-(1ll<<i)+1)*val + (lo < bound ? (bound-lo) * (val+1) : 0ll);
    }

    for(int i=2;i<30;i++){
        ll cnt = 0;
        for(ll j = (1ll<<i); j < (1ll<<(i+1)); j++){
            cnt += f(j);
        }

        //i : 29
        //3642191566 3163273063

        if(cnt != sum[i]-sum[i-1]) {
            cout<<"i : "<<i<<endl;
            cout<<cnt<<" "<<sum[i]-sum[i-1]<<endl;
        }
        cout<<cnt<<endl;
    }
    /*
    auto solve = [&](ll num) ->ll{
        int i = fb(2, num);
        ll ret = 0;
        ret = sum[i-1];

        ll val,lo,hi,mi,bound;
        lo = (1ll<<i), hi = (1ll<<(i+1)) - 1, val = f(1ll<<i);
        bound = hi;
        while(lo<hi){
            mi = (hi - lo + 1) / 2 + lo ;
            if(f(mi) == val) lo = mi;
            else hi = mi-1;
        }
        ret += (min(num, lo) - (1ll<<i) + 1) * val ;
        ret += max(0ll, num-lo) * (val+1);
        return ret;
    };
    int q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<endl;
    }
    */
    return 0;
}
