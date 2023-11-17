
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
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n),h(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>h[i];
        reverse(all(a));
        reverse(all(h));

        auto solve = [&](const vector<int>&v){
            int ok = 0;
            for(auto e:v) if(e<=k) ok = 1;
            if(!ok) return 0;

            int n = (int)v.size();
            int l,r,cur,ret;
            l = r = ret = cur = 0;
            while(l<n){
                while(r<n){
                    cur+=v[r];
                    if(cur>k)break;
                    r++;
                }
                ret = max(ret, r-l);
                if(r == n) return ret;
                while(l<n and cur>k){
                    cur-=v[l];
                    l++;
                }
                r++;
            }
            return ret;
        };


        int ans = 0;
        for(int i=0;i<n;){
            vector<int>tmp;
            int j = i;
            while(j<(n-1) and h[j+1]%h[j] == 0) j++;
            for(int ii=i;ii<=j;ii++)tmp.pb(a[ii]);
            ans = max(ans, solve(tmp));
            i = j+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
