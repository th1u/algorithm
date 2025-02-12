#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 1010;
int a[N];
int f[N];
int main(){
	int n;
	std::cin >> n;
	for(int i = 0;i < n;i ++) std::cin >> a[i];
	int res = 0;
	for(int i = 0;i < n;i ++){
		f[i] = a[i];
		for(int j = 0;j < i;j ++){
			if(a[i] > a[j]) f[i] = std::max(f[i], f[j]+a[i]);
		}
		res = std::max(res, f[i]);
	}
	std::cout << res << std::endl;
	return 0;
}