
 vector <bool> is_prime(n+1, true);
void seive(int n)
{
   
    int n;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) 
    {
         if (is_prime[i]) {
              for (int j = i * i; j <= n; j += i)
              {
                  is_prime[j] = false;
              }
                     }
    }
    /*this part is for counting the number of primes till n(from 0) */
  //if this part is enabled change void to int as return type of seive()
   /* 
    int ct_primes=0;
   for(int k=0;k<n;k++)
    {
        if(is_prime[k]==true)
            ++ct_primes;
    }
    return ct_primes;
    */
}



//MORE OPTIMIZED
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

//done with bitset

