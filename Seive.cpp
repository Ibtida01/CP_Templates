

void seive(int n)
{
    vector <bool> is_prime(n+1, true);
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
