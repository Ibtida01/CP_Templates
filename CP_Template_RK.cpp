#include <bits/stdc++.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef tuple<ll, ll, ll> t64;
typedef vector<t64> vt64;
typedef vector<vt64> vvt64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef vector<bool> vb;
ll mod =  1e9+7;
double eps = 1e-12;
// #define forn(i,e) for(ll i = 0; i < e; i++)
#define FOR(s, e, i) for(ll i = s; i <= e; i++)
// #define rforn(i,s) for(ll i = s; i >= 0; i--)
#define ROF(s ,e, i) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pii;
//#define MAXN 1000000

struct DSU
{
    vector<ll> e;

    ll comp;
    DSU(ll N)
    {
        e = vector<ll>(N, -1);
        //used = vb(N, false);
    }

    // get representive component (uses path compression)
    ll get(ll x)
    {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool same_set(ll a, ll b)
    {
        return get(a) == get(b);
    }

    ll size(ll x)
    {
        return -e[get(x)];
    }


    bool unite(ll x, ll y)    // union by size
    {

        x = get(x), y = get(y);
        if (x == y)
        {
            return false;
        }

        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};


bool valid(p64 x, ll &n, ll &m)
{
    return (x.fi  >= 0 && x.fi < n) && (x.se  >=0 && x.se< m);
}

ll mex(v64 A)
{
    ll x = 0;
    sort(all(A));
    ll prev = 0;
    for(ll y : A)
    {
        if(x == y) x++;
        else if(x < y) break;
    }
    return x;
}
ll digSum(ll n)
{
    ll ans =0;
    while(n) ans += n%10, n/=10;
    return ans;
}ll powMod(ll x, ll y, ll p = mod)
{
    ll res = 1;
    x %= p;
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % p;
            y >>= 1;
            x = (x * x) % p;
    }
    return res;
}


ll modInverse(ll n, ll p = mod)
{
    return powMod(n, p - 2, p);
}


ll ncr(ll n, ll r, ll p = mod)
{
    if(n < r) return 0;
    if(r == 0) return  1;
    v64 fact(n + 1, 0);
    fact[0] = 1;
    FOR(1, n, i)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n-r], p) % p) % p;
}
ll ans, x;
void dfs(ll s, ll n, vv64 &A, vb &used){
       if(x == 2*n) ans = max(ans, s);
        //cout << x << " ";
        FOR(0, 2*n-2, i)
        {
            if(!used[i]){
                used[i] = true;
                FOR(i + 1, 2*n-1, j){
                    if(!used[j]){
                        used[j] = true;
                        s ^= A[i][j];
                        //ans = max(ans, s);
                        x += 2;
                        dfs(s, n, A, used);
                        x -= 2;
                        s ^= A[i][j];
                        used[j] = false;
                        //break;
                    }
                }
                used[i] = false;
                break;
            }

        }
        //cout << s << " ";
        //ans = max(ans, s);
   }
template< typename T >
T pow_mod(T x, T n, const T &p) {
  T res = 1;
  while(n > 0) {
    if(n & 1) (res *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return res;
}

bool cmp(p64 x, p64 y)
{

    return x.se < y.se;

}

void solve(ll it)
{
      //ifstream fin("testcase.txt");
     
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    fast_cin();

    //FOR(1, 10, i) cout << fact[2e5] << " ";
    ll t = 1;
    cin >> t;

    for(int it=1; it<=t; it++)
    {
        //cout << "Case " << it << ": ";
        //cout << std::fixed << std::setprecision(0) << solve(it) << '\n';
        solve(it);
    }
    return 0;
}
