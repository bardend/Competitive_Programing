#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define f first 
#define s second 
#define bpc(x) __builtin_popcount(x)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


/* Idea greedy es ordenar y empezar por el menor 
	m1 * d +  m2 * (d-1)  <= m2 * d + m1 * (d-1) <-> m1 <= m2
	Idea greedy , simulo con bit mask y me doy cuenta que siempre se arma un patron  : ) 
*/

const ll mod = 1e9 + 7;
ll add(ll x, ll y){return (x+y)%mod;}
ll mul(ll x, ll y){x%=mod; y%=mod; return (((x*y)%mod)+mod)%mod;}
ll mod_pow(ll x, ll e){
	if(e <= 0) return 1;
    if(x>=mod) x%=mod;
    ll ret = 1;
    while(e){
        if(e&1) ret = ret * x % mod;
        x = x * x % mod;
        e >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    
    vector<ll>a(n);
    for(int i = 0; i < n; i++) 
    	cin >> a[i];
    sort(all(a));
   
    /*
    vector<int>cnt(n, 0);

    for(int msk = 0; msk < (1 << n); msk++) {
    	int val = bpc(msk);
    	for(int i = 0; i < n ; i++) {
    		if( (msk >> i) & 1) {
    			cnt[i] += val;
    			val--;
    		}
    	}
    }
    for(int i = 0; i < n; i++)
    	cout << cnt[i] << " ";
    */

    ll ini,stp;
    //ini = 1 << (n-1) , stp = 1 << (n-2) ;
    ini = mod_pow(2, n-1), stp = mod_pow(2, n-2);
    vector<ll>b(n);
    b[n-1] = ini;
    for(int i = n - 2; i >= 0; i--)
    	b[i] = add(b[i+1] , stp);

    ll ans = 0;
    for(int i = 0; i < n; i++)
    	ans = add(ans, mul(a[i] , b[i]));
	
	ans = mul(ans, mod_pow(2, n));
    cout << ans << endl;
    return 0;
}


