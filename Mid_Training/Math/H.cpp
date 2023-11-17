
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
 
 
vector<int> minp, primes;
 
constexpr int V = 1E7+1;
 
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
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        ll n;cin>>n;
        ll ret = 1;
        for(auto e:primes){
            if(e >n) break;
            int cnt = 0;
            while(n%e == 0){
                n/=e;
                cnt++;
            }
            ret *= (2*cnt+1);
        }
        if(n>1) ret *= (2*1 +1);
        cout<<"Case "<<(i+1)<<": "<<(ret)/2+1<<endl;
    }
    return 0;
}
