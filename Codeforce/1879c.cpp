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

const int maxn = 2e5+5;
const int mod = 998244353;

ll fac[maxn];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[1] = 1;
    for(int i=2;i<maxn;i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
    }

    int t;cin>>t;
    while(t--){
        string cd;
        int n;
        cin>>cd;
        n = (int)cd.size();

        vector<int>v;

        for(int i=0;i<n;){
            int j = i;
            while(j<n and cd[j] == cd[i])
                j++;
            v.pb(j-i);
            i = j;
        }

        ll ans,b;
        ans = 0, b= 1;

        for(auto e:v){
            ans += (e-1);
            b *= fac[e];
            b %= mod;
        }
        cout<<ans<<" "<<b<<endl;
    }
    return 0;
}










