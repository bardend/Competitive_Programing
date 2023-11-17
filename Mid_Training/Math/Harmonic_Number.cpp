
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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %d ms\n", d, (int)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

vector<ii>tmp;
int t;

void solve(){
    vector<double>ans(t);

    int ii = 0;

    double cur = 0;
    for(int i=1;i<=1e8;i++){
        cur += (1.0/i);
        while(ii<t and i == tmp[ii].f){
            ans[tmp[ii].s] = cur;
            ii++;
        }
    }
    std::cout << std::fixed << std::setprecision(10);
    for(int i=0;i<t;i++)
        cout<<"Case "<<i+1<<": "<<ans[i]<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //time__("programm time"){
    cin>>t;
    tmp.resize(t);
    for(int i=0;i<t;i++){
        cin>>tmp[i].f;
        tmp[i].s = i;
    }
    sort(all(tmp));
    solve();
    //}
    return 0;
}


