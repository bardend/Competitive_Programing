
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

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    auto solve = [&](vector<int>&a, vector<int>&b){

        int ii,jj,mini,maxi;
        mini = inf, maxi = -inf;
        for(int i=0;i<(int)a.size();i++)
            if(mini > a[i]){
                ii = i;
                mini = a[i];
            }
        for(int i=0;i<(int)b.size();i++)
            if(maxi < b[i]){
                jj = i;
                maxi = b[i];
            }

        if(mini < maxi){
            swap(a[ii], b[jj]);
        }
    };

    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<m;i++)cin>>b[i];

        if(k == 1) solve(a,b);
        else if(k == 2){
            solve(a,b);
            solve(b,a);
        }
        else if(k == 3){
            solve(a,b);
            solve(b,a);
            solve(a,b);
        }
        else if(k == 4){
            solve(a,b);
            solve(b,a);
            solve(a,b);
            solve(b,a);
        }
        else if(k >= 5){
            solve(a,b);
            solve(b,a);
            solve(a,b);
            solve(b,a);
            solve(a,b);
            int ok = 1;
            if(k == 5) ok = 0;
            if(ok){
                if(k%2 == 0) solve(b,a);
            }
        }

        ll sum = 0;
        for(auto e:a) sum += e;
        cout<<sum<<endl;
    }
    return 0;
}
