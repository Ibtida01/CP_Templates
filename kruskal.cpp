#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#define dbg(x) cout << #x << " = " << x << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define MAX 1000000000
#define pii pair<int,int>
#define EPS 1e-9
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;


// string bit(int x)
// {
//   //dbg(x);
//   string s;
//   while(x>0)
//   {
//     if(x%2==0)
//       s+="0";
//     else s+="1";
//     x=x/2;
//   }
//   //reverse(s.begin(), s.end());
//   return s;
// }

class edge{
public:
  int u,v,w;
  edge(int u,int v,int w)
  {
    this->u=u;
    this->v=v;
    this->w=w;
  }
  bool operator<(edge const& e) {
        return w < e.w;
    }
  friend ostream& operator<<(ostream& out,const edge e)
  {
    out<<"[ "<<e.u<<", "<<e.v<<", "<<e.w<<" ] ";
    return out;
  }
};

class DSU{
    int n;
    int parent[1000];
    int rank[1000];
    public:
    DSU(int sz)
    {
      n=sz;
    }
    int findParent(int v) //AKA find_set
    {
      if(v==parent[v])
        return v;
      parent[v]=findParent(parent[v]);//using path compression
      return parent[v];
    }

    void make_set(int v)
    {
      parent[v]=v;
      rank[v]=0;
    }

    void union_(int u,int v)
    {
      int pu=findParent(u);
      int pv=findParent(v);
      if (pu != pv) {
        if (rank[pu] < rank[pv])
            swap(pu, pv);
        parent[pv] = pu;
        if (rank[pu] == rank[pv])
            rank[pu]++;
    }
      //else we dont have to do anything, they have same parent means they are in same set,right?
    }
};
void solve()
{
  std::vector<edge> edgeList;
  int n,m;
  cin>>n>>m;
  int x,y,w;
  set<int> nodes;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y>>w;
    edge e(x,y,w);
    edgeList.pb(e);
    nodes.insert(x);
    nodes.insert(y);
  }
  sort(edgeList.begin(), edgeList.end());
  for(auto e:edgeList)
  {
    cout<<e<<endl;
  }
  DSU dsu(n);
  for(auto node:nodes)
    dsu.make_set(node);
  std::vector<edge> ans;
  int cost=0;
  for(edge e:edgeList)
  {
    if(dsu.findParent(e.u)!=dsu.findParent(e.v))
    {
      dsu.union_(e.u,e.v);
      ans.pb(e);
      cost+=e.w;
    }
  }
  cout<<"cost is "<<cost<<endl;
  for(auto edge:ans)
    cout<<edge<<" ";
}

int main()
{
     //fast_io;
    // int t;
    // cin>>t;
    // while(t--)
        solve();
}
