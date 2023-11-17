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

    auto sd = [&](string cd){
        int ret = 0;
        for(auto e : cd) 
            ret += (e - '0');
        return ret;
    };

    int n;
    cin >> n;
    vector<string>a(n);
    map<ii, int>frec;
    for(int i = 0 ; i < n ;i++){
        cin >> a[i];
        frec[{(int)a[i].size(), sd(a[i])}] += 1;
    }
    auto sear = [&](string cd, int fix, int op){
        if(op) reverse(all(cd));
        int n = (int)cd.size();
        int ret = 0;
        for(int i = 0 ; i < fix ; i++) ret += (cd[i]-'0');
        for(int i = fix ; i < n ; i++) ret -= (cd[i]-'0');
        return ret;
    };

    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        int num_d = (int)a[i].size();
        frec[{num_d, sd(a[i])}] -= 1;
        for(int j = 0 ; j < 6 ; j++){
            if( (j & 1) == (num_d & 1) and j <= num_d){
                ii wntR = {j, sear(a[i], (num_d + j ) / 2, 0)};
                ii wntL = {j, sear(a[i], (num_d + j ) / 2, 1)};

                ans += frec[wntR];
                if(j < num_d) ans += frec[wntL];
            }
        }
        ans += 1;
        frec[{num_d, sd(a[i])}] += 1;
    }
    cout << ans << endl;
    return 0;
}
