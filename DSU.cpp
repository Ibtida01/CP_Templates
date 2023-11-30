int parent[100];
int findParent(int v) //AKA find_set
{
  if(v==parent[v])
    return v;
  parent[v]=findParent(v);//using path compression
  return parent[v];
}

void make_set(int v)
{
  parent[v]=v;
}

union(int u,int v)
{
  int pu=findParent(u);
  int pv=findParent(v);
  if(pu!=pv)
    parent[pu]=pv;
  //else we dont have to do anything, they have same parent means they are in same set,right?
}
