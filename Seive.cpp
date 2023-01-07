

void seive(int n)
{
    vector <bool> is_prime(n+1, true);
    int ct_prime=n+1;//# of primes,initially assuming all are primes,then after processing,number of those whose truth value is false will be deducted from n+1
    int n;
    is_prime[0] = is_prime[1] = false;
    ct_prime-=2;
    for (int i = 2; i * i <= n; i++) 
    {
         if (is_prime[i]) {
              for (int j = i * i; j <= n; j += i)
              {
                  is_prime[j] = false;
                  --ct_prime;
              }
                     }
    }
}
