#include <bits/stdc++.h> 
int P(int n, int k) {
	long long ans=1;
	for(int i=0;i<k;i++){
		ans=(ans*(n-i))%1000000007;
	}
	return ans;
}