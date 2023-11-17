
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

const int inf = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>dg(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        dg[x]++;
        dg[y]++;
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)
        mp[dg[i]]++;


    int x,y;
    if((int)mp.size() <= 2){

        if((int)mp.size() == 1){
            for(auto e:mp) x = e.f, y = e.s;
            if(x == 2 and y == n) cout<<"ring topology"<<endl;
            else cout<<"unknown topology"<<endl;
        }
        else{
            int i =0;
            vector<ii>a(2);
            for(auto e:mp){
                a[i] = {e.f,e.s};
                i++;
            }

            if(a[0].f == 1 and a[0].s == 2 and a[1].f == 2 and a[1].s == n-2 ) cout<<"bus topology"<<endl;
            else if(a[0].f ==1 and a[0].s == n-1 and a[1].f == n-1 and a[1].s ==1) cout<<"star topology"<<endl;
            else cout<<"unknown topology"<<endl;
        }
    }
    else cout<<"unknown topology"<<endl;

    return 0;
}
