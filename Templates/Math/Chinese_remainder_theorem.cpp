#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }

inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }

inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }

ll bezout(ll a,ll b,ll& x_0,ll& y_0){
	if(b==0){
		x_0=1;
		y_0=0;
		return a;
	}
	ll x_1,y_1;
	ll g=bezout(b,a%b,x_1,y_1);
	x_0=y_1;
	y_0=x_1-(a/b)*y_1;
	return g;
}

int testCases;
int t;
long long a[N], n[N], ans, lcm;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++) cin >> a[i] >> n[i], normalize(a[i], n[i]);
    ans = a[1];
    lcm = n[1];
    
    for(int i = 2; i <= t; i++)
    {
        //auto pom = ex_GCD(lcm, n[i]);
        ll x1,y1;
        ll d=bezout(lcm,n[i],x1,y1);
        if((a[i] - ans) % d != 0) return cerr << "No solutions" << endl, 0;
        ans = normalize(ans + (x1 * (a[i] - ans) / d )% (n[i] / d) * lcm, lcm * n[i] / d);
        lcm = LCM(lcm, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
    }
    cout << ans << " " << lcm << endl;
    return 0;
}
