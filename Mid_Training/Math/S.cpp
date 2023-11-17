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


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll a,b,c,n;
    while(cin>>a>>b>>c>>n){
        if(a==0 and b==0 and c==0 and n==0) break;
        n = (1ll<<n);
        ll x,y,fix,val;
        fix = ((b-a)%n+n)%n;
        val = extgcd(n,c,x,y);

        if(fix % val == 0){
            ll fact = fix / val ;
            x *= fact;
            y *= fact;

            // R  = (y % mod)
            ll mod = n/gcd(n,c);

            if(y>=0) y%=mod;
            else {
                ll tmp = abs(y/mod) + 1;
                y = (y + tmp*mod)%mod;
            }
            cout<<y<<'\n';
        }
        else cout<<"FOREVER"<<'\n';
    }
    return 0;
}

