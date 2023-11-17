#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

bool cmp(__int128 x, __int128 y) { return x > y; }


 
vector<int> minp, primes;
 
 
const int maxn = 1e5 + 1;
 
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
__int128 fst_pow(__int128 x, ll e){
    __int128 ret = 1;
    while(e){
        if(e&1) ret = ret * x ;
        x = x * x ;
        e >>= 1;
    }
    return ret;
}

ll aux = (1ll<<62) ;

int main(){
	//cout << setprecision(12) << fixed;
    
    sieve(maxn);
    __int128 inf = aux;
    inf *= 4;
    inf -= 1;

    vector<ll>comp;

    for(ll i=2;i<70;i++)
        if(minp[i] != i) 
            comp.pb(i);


    set<__int128>st;
    for(ll i=1;i<maxn;i++){
        __int128 b = i;
        for(ll e : comp){
            __int128 tmp = fst_pow(b, e);
            if(cmp(tmp,inf)) break;
            st.insert(tmp);
        }
    }


    for(auto e:st){
        //if(cmp(x,e)){
            print(e);
            cout<<endl;
        //}
    }

	return 0;
	// you should actually read the stuff at the bottom
}

