#include <iostream>
#include <algorithm>
#include <cstring>
const int N = 110;

int h[N];
int l[N], r[N];

int main(){
	int n;
	std::cin >> n;
	int res = 0;
	for(int i = 1;i <= n;i ++) std::cin >> h[i];
	for(int i = 1;i <= n;i ++){
		l[i] = 1;
		for(int j = 1;j < i;j ++){
			if(h[j] < h[i]) l[i] = std::max(l[i], l[j]+1);
		}
	}
	for(int i = n;i > 0;i --){
		r[i] = 1;
		for(int j = n;j > i;j--){
			if(h[i] > h[j]) r[i] = std::max(r[i], r[j]+1);
		}
	}
	for(int i = 1;i <= n;i ++) res = std::max(res, l[i]+r[i]-1);
	std::cout << n - res << std::endl;
	return 0;
}