#include <bits/stdc++.h>
int helloCount=1;
#ifndef ONLINE_JUDGE
#include "Templates/printContainer.h"
#endif
#define dbg(x) cout << #x << " = " << x << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define Endl "\n"
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ins insert
#define INF 1000000000
#define pii pair<int,int>
#define EPS 1e-9
#define fst first
#define snd second
#define _for(i,a,b) for(int i=a;i<=b;i++) // i is inclusive that is i belongs to [a,b] and not (a,b)
#define sqr(a) (a)*(a)
#define log(b,n) (log2(n)/(log2(b))) //logBase_b_(n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _hello { cout<<"hello "<<helloCount++<<"\n";}
#define _yes cout<<"YES\n"
#define _nope cout<<"NO\n"
#define _2TTP(k) 1LL<<k //_2TTP(k) means 2 to the power k
#define _tcNo cout<<tcNo<<"_________________________________________\n"
const long long mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
bool _areEqual(double x,double y)
{
    return (abs(x-y)<EPS) ? true : false;
}

string _bin(int decimal)
{
    //prints n bit integer
    int n=8;
    //you can change according to ur need
    string bin;
    for(int i=0;i<n;i++)
    {
        bin.pb(((decimal&(1<<i))>>i)+'0');
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

ll _toDeci(string binForm)
{
    reverse(all(binForm));
    int len=binForm.size();
    ll decimalForm=0;
    for(int i=0;i<len;i++)
    {
        decimalForm+=(ll)(binForm[i]-'0')<<i;
    }
    return decimalForm;
}
bool isPrime(ll n)
{
    if(n==2) return true;
    int lim=sqrt(n)+1;
    for(int i=2; i<=lim; i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

template <typename T> void inputContainer(std::vector<T>& v)       { for(auto &it:v) cin>>it; }
template <typename T> void base1InputContainer(std::vector<T>& v)  { int n=v.size()-1; for(int i=1;i<=n;i++)cin>>v[i]; }
                      void printVector(std::vector<int>& v)        { for(auto it:v)cout<<it<<" "; cout<<endl; }
                      void base1printContainer(std::vector<int>& v){ int n=v.size()-1; for(int i=1;i<=n;i++)cout<<v[i]<<" ";cout<<endl; }
class DSU
{
public:
    vector<int> rank,parent;
    DSU(int n)
    {
        for(int i=0; i<=n; i++)
            rank.pb(0);
        //parent.resize(n);
        for(int i=0; i<=n; i++)
            parent.pb(i);
    }
    int _findParent(int u)
    {
        if(u==parent[u]) return u;
        //else
        return parent[u]=_findParent(parent[u]);
    }
    void _union(int u,int v)
    {
        int pu=parent[u];
        int pv=parent[v];
        if(pu==pv) return;
        //else
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv])
        {
            parent[pv]=pu;
        }
        else
        {
            parent[pu]=pv;
            ++rank[pv];
        }
    }
};

class edge
{
public:
    int u,v,w;
    edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const edge& other) const
    {
        return w>other.w;
    }

};
void precompute()
{
    
}
const int MOD = 1e9 + 7;

// Custom comparator for sorting arrays
bool compareArrays(const array<ll, 3>& a, const array<ll, 3>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

void solve(int tcNo) {
    ll n;
    cin>>n;
    vector<array<ll, 2>> pairs(n);
    set<ll> uniqye;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        pairs[i] = {x, y};
        uniqye.insert(x);
        uniqye.insert(y);
    }
    map<ll, ll> valueToIndex;
    ll idx = 1;
    for (ll val : uniqye) {
        valueToIndex[val] = idx++;
    }
    vector<array<ll, 3>> result(n);
    for (int i = 0; i < n; i++) {
        ll compX = valueToIndex[pairs[i][0]];
        ll compY = valueToIndex[pairs[i][1]];
        result[i] = {compX + compY, pairs[i][0], pairs[i][1]};
    }
    sort(all(result), compareArrays);
    for (const auto& item : result) {
        cout << item[1] << " " << item[2] << " ";
    }
    cout << "\n";
}
int main() {
    fast_io;
    int t = 1;
    //void precompute();
    cin >> t;
     for (int i = 1; i <= t; i++)
         solve(i);
}

//substr  cmd c++
/*
string substr(size_t startingIdx=0,size_t len=npos) const;
here npos indicates all characters until the end of the string.
*/
//graphs -->vector<int> adj[n+1]; n=# of vertices
/*
taking graph input
for(int i=1;i<=n;i++)
{
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);//ONLY IF UNDIRECTED GRAPH
}
*/
