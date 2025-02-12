#include<iostream>
#include<algorithm>
#include<cstring>
const int N = 1010;
int h[N];
int f[N];
int g[N];
int main(){
    int n = 0;
    while(std::cin >> h[n]) n++;
    int res = 0; //一次最多拦截导弹数
    int count = 0; // 最少配备系统数
    for(int i = 0;i < n;i ++){
        f[i] = 1;
        for(int j = 0;j < i;j ++){
            if(h[i] <= h[j]) f[i] = std::max(f[i], f[j]+1);
        }
        res = std::max(res, f[i]);
    }
    for(int i = 0;i < n;i ++){
        int k = 0;
        while(k < count && g[k] < h[i]) k++;
        g[k] = h[i];
        if(k >= count) g[count++] = h[i];
    }
    std::cout << res << std::endl;
    std::cout << count << std::endl;
    return 0;
}