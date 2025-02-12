#include <iostream>
#include <algorithm>
#include <cstring>

const int N = 5010;
std::pair<int, int> p[N];
int f[N];
int main(){
	int n;
	std::cin >> n;
	for(int i = 0;i < n;i ++){
		int x, y;
		std::cin >> x >> y;
		p[i] = {x, y};
	}
	std::sort(p, p+n);
	int res = 0;
	for(int i = 0;i < n;i ++){
		f[i] = 1;
		for(int j = 0;j < i;j ++){
			if(p[i].second > p[j].second) f[i] = std::max(f[i], f[j]+1);
		}
		res = std::max(res, f[i]);
	}
	std::cout << res << std::endl;
	return 0;
}