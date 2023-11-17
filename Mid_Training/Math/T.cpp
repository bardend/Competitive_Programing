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

const int maxn = 50;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll fib[maxn];
    fib[0] = 1; fib[1] = 2;
    for(int i=2;i<maxn;i++) fib[i] = fib[i-1] + fib[i-2];

    auto get_num = [&](string cd){
        ll ret = 0;
        int n =(int)cd.size();
        for(int i=0;i<n;i++)
            if(cd[i] == '1') ret += fib[i];
        return ret;
    };
    auto trans = [&](ll num, string &cd){
        int i,j;
        for(i = maxn-1;i>=0;i--){
            if(num >= fib[i]){
                j = i;
                break;
            }
        }
        for(int k=j;k>=0;k--){
            if(num >= fib[k]){
                cd += "1";
                num -= fib[k];
            }
            else cd += "0";
        }
        if(i==-1) cd += "0";
    };

    vector<string>cd(3);
    while(cin>>cd[0]>>cd[1]){
        for(int i=0;i<2;i++)
            reverse(all(cd[i]));
        vector<ll>tmp(2);
        for(int i=0;i<2;i++) {
            tmp[i] = get_num(cd[i]);
            cd[i] = "";
        }
        tmp[2] = tmp[0] + tmp[1];
        cd[2] = "";
        for(int i=0;i<3;i++)
            trans(tmp[i], cd[i]);


        cout<<" ";for(int i=0;i<((int)cd[2].size() - (int)cd[0].size());i++)cout<<" ";cout<<cd[0]<<endl;
        cout<<"+";for(int i=0;i<((int)cd[2].size() - (int)cd[1].size());i++)cout<<" ";cout<<cd[1]<<endl;
        cout<<" ";for(int i=0;i<((int)cd[2].size());i++)cout<<"-";cout<<endl;
        cout<<" ";cout<<cd[2]<<endl;
        cout<<endl;
    }

    return 0;
}
