#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define f first 
#define s second 
#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
 
 
vector<int> minp, primes;
 
constexpr int V = 1E6 + 5;
 
int cnt[V + 1];
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sieve(V);

    while(true){
        int x;
        cin>>x;
        if(x == 0)break;
        vector<pair<ll,int>>arit;
        int bs,ex;
        bs = minp[x], ex = 0;
        while(x!=1){
            if(minp[x] == bs) ex++;
            else {
                arit.pb({bs,ex});
                bs = minp[x], ex = 1;
            }
            x/=minp[x];
        }
        if(ex>0) arit.pb({bs,ex});

        auto fst_pow = [&](ll x, int y, auto &&fst_pow) ->ll{
            if(y == 0) return 1ll;
            ll ret = fst_pow(x,y/2,fst_pow);
            ret *= ret;
            if(y&1) ret *= x;
            return ret;
        };

        ll sum_d,num_d;
        sum_d = num_d = 1;
        for(auto e:arit){
            num_d *= (e.s+1);
            sum_d *= (fst_pow(e.f,e.s+1,fst_pow)-1) / (e.f-1);
        }
        cout<<(sum_d - num_d)<<endl;
    }
    return 0;
}
