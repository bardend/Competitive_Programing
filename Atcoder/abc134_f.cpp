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

    int n = 4;

    vector<int>a(n);
    for(int i = 0 ; i < n ; i++)
        a[i] = i+1;

    do{
        vector<int>tmp = a;
        int val = 0;
        for(int i = 0 ; i < n ; i++)
            val += abs((i+1)-tmp[i]);
        for(auto e : tmp)
            cout << e << " ";
        cout << " : " << val <<endl;
    } while(next_permutation(all(a)));

    return 0;
}
