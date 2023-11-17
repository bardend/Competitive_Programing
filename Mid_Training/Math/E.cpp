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


__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

typedef __int128 ul;


int main(){

    int t;cin>>t;
    const int wnt = 18;
    const int maxn = 20;

    ul pot[maxn];
    pot[0] = 1ll;
    for(int i=1;i<maxn;i++) pot[i] = pot[i-1] * 10;

    auto num_d = [&](ul x){
        int ret = 0;
        while(x){
            ret++;
            x/=10;
        }
        return ret;
    };

    auto get_up = [&](ul x){
        return x/pot[max(num_d(x)-wnt,0)];
    };

    auto get_dow= [&](ul x){
        return x%1000;
    };

    auto rec_up =[&](ul n, int k, auto &&rec_up) -> ul{
        if(k == 0) return 1ll;
        ul ret = rec_up(n, k/2,rec_up);
        ret = get_up(ret*ret);
        if(k&1) ret = get_up(ret*n);
        return ret;
    };
    
    auto rec_dow =[&](ul n, int k, auto &&rec_dow) -> ul{
        if( k == 0) return 1ll;
        ul ret = rec_dow(n, k/2, rec_dow);
        ret = get_dow(ret*ret);
        if(k&1) ret = get_dow(ret*n);
        return ret;
    };

    for(int tt=1;tt<=t;tt++){
        ll tn;int k;
        cin>>tn>>k;
        ul n = tn;

        ul fn = rec_up(n,k,rec_up);
        ul sn = rec_dow(n,k,rec_dow);

        fn = fn/pot[num_d(fn)-3]; 
        cout<<"Case "<<tt<<": ";
        print(fn);
        cout<<" ";
        int nlen = num_d(sn);
        if(nlen == 0) cout<<"000";
        else if(nlen == 1) cout<<"00";
        else if(nlen == 2) cout<<"0";
        print(sn);
        cout<<endl;
    }
    return 0;
}
