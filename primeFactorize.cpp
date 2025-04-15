/*
 * Function: primeFactorize
 * ------------------------
 * Returns the prime factorization of a number n as a vector of pairs.
 * Each pair contains:
 *    - the prime factor, and
 *    - its exponent in the factorization.
 *
 * Example:
 *   For n = 100, the function returns { {2,2}, {5,2} } since 100 = 2² * 5².
 *
 * Usage: 
 *   auto factors = primeFactorize(n);
 *   for(auto &p : factors) {
 *       // p.first is the prime, p.second is the exponent
 *   }
 */
vector<pair<ll, int>> primeFactorize(ll n) {
    vector<pair<ll, int>> factors;
    
    // Count the number of times 2 divides n
    int count = 0;
    while (n % 2 == 0) {
        count++;
        n /= 2;
    }
    if (count > 0)
        factors.push_back({2, count});
    
    // Check for odd factors from 3 up to sqrt(n)
    for (ll i = 3; i * i <= n; i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count > 0)
            factors.push_back({i, count});
    }
    
    // If n is a prime number greater than 2, then n remains.
    if (n > 1)
        factors.push_back({n, 1});
    
    return factors;
}
