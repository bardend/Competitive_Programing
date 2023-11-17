
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

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){

        int n,q;
        cin>>n>>q;
        vector<ll>a(n);
        vector<int>v(q);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<q;i++)cin>>v[i];
        vector<int>aux;
        int mini = v[0];
        aux.pb(mini);
        for(int i=1;i<q;i++){
            if(v[i] < mini){
                mini = v[i];
                aux.pb(mini);
            }
        }
        for(auto e:aux){
            for(int i=0;i<n;i++){
                int tmp = 0;
                int xx = a[i];
                while(xx % 2 == 0){
                    tmp++;
                    xx /= 2;
                }
                if(tmp >=e)
                    a[i] += (1<<(e-1));
            }

        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;

    }
    return 0;
}
