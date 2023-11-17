
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

const int maxn = 31;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;

    while(t--){
        int n,m,num,den;
        cin>>n>>m;
        num = n%m;
        den = m;

        int nor = __gcd(num,den);
        num /= nor;
        den /= nor;

        cout<<num<<" "<<den<<endl;

        int j,ones ;
        ones = 0;

        for(int i=0;i<maxn;i++)
            if((den>>i)&1){ ones++; j=i;}

        if(ones>1){cout<<"-1"<<endl; continue;}

        ll acum,ans;
        int need,ii;
        acum = ans = 0ll;
        ii = 0;

        for(int i=j;i>0;i--,ii++){
            if((num>>ii)&1){
                need = (m-acum+1)/2;
                ans += 1ll*need*i; 
                acum += need;
                cout<<need<<" "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
