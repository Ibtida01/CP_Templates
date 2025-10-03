Tips::
Use unordered_map with reserve() if element values are large or n is big — avoids rehashing.

If values are up to 1e9 and n is large, consider coordinate compression (map values → 0..m-1) to use vector<int> counts (faster).

Sliding-window for sum requires non-negative numbers. If negatives appear, you must use other techniques (prefix sums + map, two pointers won't work).

When counting subarrays with constraints per-left (like length bounds), compute valid low/high from l and current r, as shown.

Always use long long for answer accumulation when counting subarrays (can be ~n^2).

Reset state between testcases! (the template does)
