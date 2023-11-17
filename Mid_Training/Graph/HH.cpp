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

const int maxn = 10;
map<string,int>mp;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    auto swp = [&](int i, int j, string &cd){
        string ret = cd;
        while(i<j){
            swap(ret[i], ret[j]);
            i++;
            j--;
        }
        return ret;
    };
    string ini = "abcdefghij";
    mp[ini] = 0;
    queue<string>q;
    q.push(ini);

    int steps = maxn-1;

    while(!q.empty()){
            string v = q.front();
            q.pop();

            for(int i=0;i<maxn;i++){
                for(int j=i+1;j<maxn;j++){
                    string go = swp(i,j,v);
                    if(mp.find(go) == mp.end()){
                        mp[go] = mp[v] + 1;
                        q.push(go);
                    }
                }
            }
    }
    int ans = 0;
    for(auto e:mp)
        ans = max(ans,e.s);
    cout<<ans<<endl;

    int cnt = 0;
    for(auto e:mp)
        if(e.s == ans) cnt++;
    cout<<cnt<<endl;

    return 0;
}
