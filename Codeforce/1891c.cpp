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

    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(all(a));
        
        int i,j;
        i = 0, j = n-1;
        ll comb = 0;
        ll ans = 0;
        while(i<j){
            if(comb + a[i] < a[j]){
                ans += a[i];
                comb += a[i];
                i++;
            }
            else if(comb + a[i] >= a[j]){
                int take = a[j] - comb;
                ans += take;
                ans ++;
                a[i] -= take;
                comb = 0;
                j--;
            }
        }

        if(a[i] > 0){
            int op1,op2;
            op1 = a[i];
            op2 = (a[i]-comb+1)/2 ;
            op2++;
            ans += min(op1,op2);
        }

        cout<<ans<<endl;
    }
    return 0;
}
