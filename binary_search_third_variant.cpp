int low = 0, high = 1e9, ans = -1;
while (low <= high) {
    int mid = (low + high) / 2;
    if (ok(mid)) {
        ans = mid;
        high = mid - 1; // try smaller answer
    } else {
        low = mid + 1; // need a bigger value
    }
}
