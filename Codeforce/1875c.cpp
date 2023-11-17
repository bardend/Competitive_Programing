
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

const int maxbit = 31;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){

        int n,m;
        cin>>n>>m;

        int num,den,g;
        num = n%m, den = m;
        g = __gcd(num,den);
        num/=g, den/=g;

        if(__builtin_popcount(den) != 1) {cout<<"-1"<<endl; continue;}

        int j;
        for(int i=0;i<maxbit;i++)
            if(((den>>i)&1)) j = i;

        //cout<<"j "<<j<<endl;

        ll ans = 0ll;
        for(int i=0;i<=j;i++){

            if((num>>i)&1){

                int nodos = m/(1<<(j-i));

                ans += 1ll*nodos*((1<<(j-i))-1);
                
                //cout<<nodos<<" "<<i<<" "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
