#include <iostream>
#include <algorithm>
#include <cstring>
const int N = 55;
int n;
int ans;
int q[N];
int up[N], down[N];

void dfs(int u, int su, int sd){
	if(su + sd >= ans) return ;
	    if(u == n){
	        ans = su + sd;
	        return ;
	    }
    // 1. 将当前数放到上升子序列中
    int k = 0;
    while(k < su && up[k] >= q[u]) k++;
    int t = up[k];
    up[k] = q[u];
    if(k < su) dfs(u+1, su, sd);
    else dfs(u+1, su+1, sd);
    up[k] = t;
    
    //2. 将当前数放到下降子序列中
    k = 0;
    while(k < sd && down[k] <= q[u]) k++;
    t = down[k];
    down[k] = q[u];
    if(k < sd) dfs(u+1, su, sd);
    else dfs(u+1, su, sd+1);
    down[k] = t;
}
int main(){

	while(std::cin >> n, n){
		for(int i = 0;i < n;i ++) std::cin >> q[i];

		ans = n;
		dfs(0, 0, 0);
		std::cout << ans << std::endl;
	}
	return 0;
}