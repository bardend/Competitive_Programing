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

    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];

        int ok2 = 1;
        for(int i=0;i<5;i++){
            int l = (1<<i);
            if(l > n) break;
            int ok = 1;
            for(int j=1;j<l;j++)
                if(a[j] < a[j-1]) ok = 0;

            if(!ok) ok2 = 0;

            for(int j=0;j<l;j++)
                a[j] = -inf;
        }

        for(int i=1;i<n;i++)
            if(a[i] < a[i-1]) ok2 = 0;


        if(ok2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
