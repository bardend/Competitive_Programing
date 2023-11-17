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

const int maxn = 1e5+1;
vector<int>adj[maxn];
int main(){
    /*
     * Pensemos en una idea greedy en la cual podemos ir desde los mayores
     * numeros hacia los menores en caso tengamos n fijo quiza varios , ahora
     * tenemos (n-1) notamos que el n mas cercano a la derecha le conviene caso
     * contrario sera un nuevo n' para el (n-2)
     */
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<ii>a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i].f;
        a[i].s = i;
    }
    sort(rall(a));
    int ind = n-1;

    for(int i = 0 ; i < n ; ){
        int j = i;
        while(j<n and a[i].f == a[j].f){
            adj[ind].pb(a[j].s);
            j += 1;
        }
        ind--;
        i = j;
    }

    int col = 0;
    set<int>st;

    for(int i = n-1 ; i >= 0 ; i--){
        vector<int>tmp;
        for(auto e : adj[i]){
            auto itr = st.upper_bound(e);
            if(itr != st.end()){
                st.erase(itr);
                tmp.pb(e);
            }
            else {
                col += 1;
                tmp.pb(e);
            }
        }
        for(auto e : tmp)
            st.insert(e);
    }
    cout << col <<endl;
    return 0;
}
