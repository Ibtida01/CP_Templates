#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<int> primes;
vector<bool> isprime(1000, false);//so that all evens except for 2 are marked as NTO PRIME

void seive(int n)
{
    isprime[2]=true;
    for(int i=3; i*i <= n; i+=2)
    {
        if(isprime[i]==true)
            {
                for(int j=i*i; j<= n; j+=i)
                    isprime[j]=false;
            }
    }
}
void preload_vectors(vector <int>& primearr)
{
    primearr.push_back(2);
    for(int i=3; i<10000; i+=2)
    {
        if(isprime[i]==true)
            primearr.push_back(i);
    }
}
double phi(int n)
{
    double retval=n;
    for(int i=0; primes[i]<=n; i++)
    {
        if(n%primes[i]==0)
            retval=retval*(1-1.0/primes[i]);
    }
    return retval;
}

//phi(10)=4 for example
/* prerequisites:
must preload the primnes
 int main()
 {
  int n=1000;
  seive(n);
  preload(primes)
  cin>>n;
  cout<<phi(n)<<endl;
 }
