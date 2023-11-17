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

int respose(){ int x;cin>>x; return x;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    set<int>st;
    for(int i=1;i<=n;i++)st.insert(i);
    auto dfs = [&](int v, auto && dfs) -> int {
        int ok = 1;
        while(ok){
            if(!st.empty()){
                int val = *st.begin();
                cout<<"? "<<val<<" "<<v<<endl;
                int rpta = respose();
                if(rpta) {// sigo preguntando
                    st.erase(st.begin());
                    continue;
                }
                else {
                    if(st.count(v)) st.erase(v);
                    return dfs(val,dfs);
                    break;
                }
            }
            else return v;
        }
    };

    int target = dfs(1,dfs);

    int ok =1;
    for(int i=1;i<=target;i++){
        cout<<"? "<<target<<" "<<i<<endl;
        int rpta = respose();
        if(rpta == 1) ok = 0;
    }
    if(ok) cout<<"! "<<target<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
