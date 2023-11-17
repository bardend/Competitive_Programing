#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define f first 
#define s second 
#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int maxn = 1e6+5;
int cri[maxn];
vector<int>pr;
 
void init(){
    memset(cri,1,sizeof(cri));
    pr.pb(2);
    int i;
    for(i=4;i<maxn;i+=2) cri[i] = 0;
    for(i=3;i*i<maxn;i+=2){
        if(cri[i]){
            pr.pb(i);
            for(int j=i*i;j<maxn;j+=2*i)
                cri[j] = 0;
        } 
    }

    for(int ii=i;ii<maxn;ii++)
        if(cri[ii])
            pr.pb(ii);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();

    int t;cin>>t;
    for(int j=0;j<t;j++){
        ll a,b;
        cin>>a>>b;
        if(b >a/b){
            cout<<"Case "<<j+1<<":  0"<<endl;
            continue;
        }

        ll tmp = a;
        //ll ans = 1;
        vector<ii>arit;
        for(int i=0; i<(int)pr.size() and 1ll*pr[i]*pr[i]<=a; i++){
            int cnt = 0;
            while(tmp%pr[i] == 0){
                tmp /= pr[i];
                cnt++;
            }
            arit.pb({pr[i], cnt});
            //ans *= (cnt+1);
        }

        if(tmp > 1) arit.pb({tmp,1});//ans*=2;}

        ll ans = 0;
        auto back = [&](int pos, ll num, auto &&back) -> void{
            if(num >= a/num) return ;
            if(pos == (int)arit.size()) {
                if(num < b) return ;
                ans++;
                return;
            }
            for(int i=0;i<=arit[pos].s;i++){
                back(pos+1,num,back);
                num *= arit[pos].f;
            }
        };

        back(0,1,back);
        /*
        ans /= 2;
        for(int i=1;i<b;i++)
            if(a%i == 0) ans--;
        */
        cout<<"Case "<<j+1<<": "<<ans<<endl;
    }
    return 0;
}
