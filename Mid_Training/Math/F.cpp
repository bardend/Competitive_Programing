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
const int maxn = 1e7+5;
int cri[maxn];
vector<int>pr;
 
void init(){
    for(int i=0;i<maxn;i++)cri[i] = 1;
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
    const int maxm = 1e6+5;
    for(int tt=0;tt<t;tt++){
        int n;
        cin>>n;

        int cnt = 0;
        for(int i=0;i<min(maxm,(int)pr.size());i++){
            int want = n-pr[i];
            if(want < pr[i]) break;
            //cout<<want<<" "<<cri[want]<<endl;
            cnt += cri[want];
        }
        cout<<"Case "<<tt+1<<": "<<cnt<<endl;
    }
    return 0;
}
