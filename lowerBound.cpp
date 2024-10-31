int lowerBound(const vector<int>& a, int target) {
    int L = 0, R = a.size() - 1;
    int ans = -1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (a[mid] >= target) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    return ans;
}
