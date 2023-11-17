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

const int maxn = 52;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<pair<char,char>>v(maxn);
    for(int i=0;i<maxn;i++){
        string xd;
        cin>>xd;
        v[i].f = xd[0], v[i].s = xd[1];
    }
    auto edit = [&](vector<pair<char,char>>&v) -> int{
        int n = (int)v.size();
        for(int i=n-1;i>=3;i--) 
            if(v[i].f == v[i-3].f){
                v.erase(v.begin()+i);
                v.erase(v.begin()+i-1);
                v.erase(v.begin()+i-2);
                v.erase(v.begin()+i-3);
                return 1;
            }
        for(int i=n-1;i>=3;i--)
            if(v[i].s == v[i-3].s){
                v.erase(v.begin()+i);
                v.erase(v.begin()+i-3);
                return 1;
            }
        return 0;
    };
    vector<pair<char,char>>cur;
    for(int i=0;i<maxn;i++){
        cur.pb(v[i]);
        while(edit(cur)){
        }
    }
    cout<<(int)cur.size()<<" ";
    for(auto e:cur)cout<<e.f<<e.s<<" ";
    cout<<endl;
    return 0;
}
