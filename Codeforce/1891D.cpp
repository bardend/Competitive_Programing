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
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
const int maxn = 60;
const int mod = 1e9+7;
ll add(ll a, ll b){return (a+b)%mod;}
ll mul(ll a, ll b){a%=mod; b%=mod;return (((a*b)%mod)+mod)%mod;}
ll sub(ll a, ll b){a%=mod; b%=mod;return ((a-b)+mod)%mod;}

struct st{
    ll l,r,log;
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    auto floor = [&](ll b, ll num){
        ll cur = 1;
        int ret = 0;
        while(cur <= num / b){
            cur *= b;
            ret++;
        }
        return ret;
    };

    vector<st>v;
    for(int i = 2; i < maxn; i++)
        v.pb({1ll<<i, (1ll<<(i+1))-1, i});

    vector<st>fix;

    for(auto [l, r, log] : v){
        ll L,R,val;
        L = l, R = r, val = floor(log, l);
        while(L<=R){
            ll lo,hi,mi,pre;
            lo = pre = L, hi = R, val = floor(log, lo);
            while(lo<hi){
                mi = lo + (hi - lo + 1) / 2 ;
                if(floor(log, mi) == val) lo = mi;
                else hi = mi-1;
            }
            fix.pb({pre, lo, val});
            L = lo+1;
        }
    } 
    /*
    for(auto [l, r, log] : fix)
        cout<<l<<" "<<r<<" "<<log<<endl;
        */
    
    auto solve = [&](ll num){
        if(num<4) return 0ll;
        ll ret = 0;
        for(auto [l,r,log] : fix){
            ret = add(ret, mul((max(0ll, min(r, num) - l + 1)) , log));
        }
        return ret;
    };

    int t;
    cin>>t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        cout << sub(solve(r), solve(l-1)) << endl;
    }
    return 0;
}
