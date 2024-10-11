bool chk(int x) {
	//something condition that the chk fnc is checking
}
signed main() {
  //...
  l = 1, r = maxn; // min and max possible values for the concerned variable
  while(l <= r) {
		int mid = (l + r) / 2;
		if(chk(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1 << endl;
	return 0;
}
