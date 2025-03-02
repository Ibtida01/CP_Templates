ull isqrt(ull n) {
    if (n < 2) {
        return n;
    }
    ll low = 1, high = n;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}
