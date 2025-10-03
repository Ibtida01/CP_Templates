// Sliding-window template — contest-ready (C++17)
// Paste into your solution; edit functions for the problem at hand.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ---------- Utilities ----------
static inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Reserve hashmap space for speed on large inputs (optional)
template<class M>
static inline void reserve_map(M &m, size_t n) {
    m.reserve(n * 2);
    m.max_load_factor(0.7);
}

// ---------- Two-pointer skeleton ----------
// Generic pattern: window is [l, r) with r non-decreasing.
// For each l (0..n-1) expand r while condition holds, process contribution, then remove a[l].
template<typename FExpand, typename FProcess, typename FRemove>
void two_pointer_skeleton(int n, FExpand can_expand, FProcess process_for_l, FRemove remove_left) {
    int l = 0, r = 0;
    // state (e.g., freq map) should be maintained by the lambdas / captured variables
    for (l = 0; l < n; ++l) {
        // expand r as much as allowed by can_expand(r)
        while (r < n && can_expand(r)) {
            // caller must update state inside can_expand or via capturing r
            ++r;
        }
        // process contribution for this l with current r (r is exclusive)
        process_for_l(l, r);
        // remove a[l] from state (caller handles actual removal)
        remove_left(l);
    }
}

// ---------- at_most_k_distinct with optional length bounds ----------
// Counts subarrays with <= K distinct elements and length in [Lmin, Lmax].
// If you only need all subarrays (no length bounds) set Lmin=1, Lmax=n.
ll at_most_k_distinct_with_length_bounds(const vector<int> &a, int K, int Lmin, int Lmax) {
    if (K <= 0) return 0; // no non-empty subarray has 0 distinct values
    int n = (int)a.size();
    unordered_map<int,int> freq;
    reserve_map(freq, n);
    int distinct = 0;
    int r = 0;       // window [l, r)
    ll ans = 0;

    for (int l = 0; l < n; ++l) {
        // expand r while adding a[r] keeps distinct <= K
        while (r < n) {
            int v = a[r];
            if (freq[v] == 0 && distinct + 1 > K) break;
            if (freq[v] == 0) ++distinct;
            ++freq[v];
            ++r;
        }
        // valid right endpoints for at most K distinct are indices in [l, r-1]
        int low = l + Lmin - 1;
        int high = min(n - 1, l + Lmax - 1);
        int allowed_high = min(high, r - 1);
        if (low <= allowed_high) ans += (ll)(allowed_high - low + 1);

        // remove a[l] when moving left forward
        int leftVal = a[l];
        --freq[leftVal];
        if (freq[leftVal] == 0) {
            freq.erase(leftVal);
            --distinct;
        }
    }
    return ans;
}

// ---------- Common sliding-window helpers ----------

// Longest subarray with sum <= S (works only for non-negative elements)
int longest_subarray_sum_at_most(const vector<ll> &a, ll S) {
    int n = (int)a.size();
    int l = 0, r = 0;
    ll cur = 0;
    int best = 0;
    while (r < n) {
        cur += a[r++];
        while (l < r && cur > S) {
            cur -= a[l++];
        }
        best = max(best, r - l);
    }
    return best;
}

// Minimum-length subarray with sum >= S (works only for positive elements)
// returns n+1 if no such subarray exists
int min_len_subarray_sum_at_least(const vector<ll> &a, ll S) {
    int n = (int)a.size();
    int l = 0;
    ll cur = 0;
    int ans = n + 1;
    for (int r = 0; r < n; ++r) {
        cur += a[r];
        while (l <= r && cur >= S) {
            ans = min(ans, r - l + 1);
            cur -= a[l++];
        }
    }
    return ans;
}

// ---------- Example usage for "exactly k distinct & length in [l,r]" ----------
// exactly_k = at_most_k - at_most_(k-1)
ll count_exactly_k_with_length_bounds(const vector<int> &a, int k, int lmin, int lmax) {
    ll at_most_k = at_most_k_distinct_with_length_bounds(a, k, lmin, lmax);
    ll at_most_km1 = at_most_k_distinct_with_length_bounds(a, k - 1, lmin, lmax);
    return at_most_k - at_most_km1;
}

// ---------- Main (example template for multiple testcases) ----------
int main() {
    fast_io();
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        ll ans = count_exactly_k_with_length_bounds(a, k, l, r);
        cout << ans << '\n';
    }
    return 0;
}
