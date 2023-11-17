#include <iostream>
#include <vector>

using namespace std;
/*
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define f first 
#define s second 
#define endl '\n'
*/
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

// exist x,yがax+by=gcd(a,b)の解になる

ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

ll mod_inverse(ll a, ll m) {
	a %= m;
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

ll mod_pow(ll x, ll e, ll mod){
    if(x>=mod) x%=mod;
    ll ret = 1;
    while(e){
        if(e&1) ret = ret * x % mod;
        x = x * x % mod;
        e >>= 1;
    }
    return ret;
}
/*

vector<int> minp, primes;
 
 
 
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
*/
ll gcd(ll a, ll b) {
   return b==0?a:gcd(b, a%b);
}

ll mod(ll a,ll b){
    if(a>=0)
        return a%b;
    else
        return a%b+b;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;

    ll a = n-m;
    ll c = x-y;
    ll b = l;
    ll d = extgcd(a,b,x,y);

    if(c % d == 0){
        x *= (c/d);
        ll md = b/gcd(b,a);
        // x mod mod
        cout<<mod(x,md)<<'\n';
    }
    else cout<<"Impossible"<<'\n';
    return 0;
}
