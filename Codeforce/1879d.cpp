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

const int maxn =  3e5;
const int maxbit = 30;
const int mod = 998244353;
ll a[maxn];
ll slon[2][maxbit];
ll sz[2][maxbit];

ll sub(ll x, ll y){return (x-y+mod)%mod;}
ll add(ll x, ll y){return (x+y)%mod;}
ll mul(ll x, ll y){x%=mod; y%=mod; return (((x*y)%mod)+mod)%mod;}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    memset(slon, 0, sizeof(slon));
    memset(sz, 0, sizeof(sz));

    for(int i = 0; i < n; i++) {
        for(int bt = 0; bt < maxbit; bt++) {
            int on = (a[i] >> bt) & 1;
            slon[on][bt] = add(slon[on][bt], i+1);
            sz[on][bt] += 1;
        }
    }

    ll ans = 0ll;
    int pre = 0;

    for(int i = 0; i < n; i++) {
        for(int bt = 0; bt < maxbit; bt++) {
            // to get 1 we need pre^1
            int wnt = (((pre >> bt) & 1 ) ^ 1);
            ll len = slon[wnt][bt] - i * sz[wnt][bt];
            ans = add(ans , mul(len, 1<<bt));
        }
        for(int bt = 0; bt < maxbit; bt++) {
            int on = (a[i] >> bt) & 1;
            slon[on][bt] = sub(slon[on][bt], i+1);
            sz[on][bt] -= 1;
        }
        pre ^= a[i];
    }
    cout << ans << endl;

    return 0;
}
