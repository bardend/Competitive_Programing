
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

const ll inf = 1e17;
const int maxn = 30;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;

    vector<ll>five;
    ll cur = 1;

    for(int i=0;i<maxn;i++){
        cur *= 5;
        if(cur>inf) break;
        five.pb(cur);
    }

    auto f = [&](ll x) -> ll{
        ll ret = 0;
        for(int i=0;i<(int)five.size();i++)
            ret += x/five[i];
        return ret ;
    };
            

    for(int tt=1;tt<=t;tt++){
        ll q;
        cin>>q;
        ll lo,hi,mi;
        lo = 1, hi = inf;
        while(lo<hi){
            mi = (hi-lo)/2 + lo;
            if(f(mi)>=q) hi = mi;
            else lo = mi+1;
        }
        cout<<"Case "<<tt<<": ";
        if(f(lo)==q) cout<<lo<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}
