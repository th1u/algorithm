#include<iostream>
#include<algorithm>
#include<cstring>

const int N = 3010;
int a[N], b[N];
int f[N][N];

int main(){
    int n;
    std::cin >> n;
    for(int i = 1;i <= n;i ++) std::cin >> a[i];
    for(int i = 1;i <= n;i ++) std::cin >> b[i];
    
    // for(int i = 1;i <= n;i ++){
    //     for(int j = 1;j <= n;j ++){
    //         f[i][j] = f[i-1][j];
    //         if(a[i] == b[j]){
    //             f[i][j] = std::max(f[i][j], 1);
    //             for(int k = 1;k < j;k ++){
    //                 if(b[k] < b[j]){
    //                     f[i][j] = std::max(f[i][j], f[i][k]+1);
    //                 }
    //             }
    //         }
    //     }
    // }
    for(int i = 1;i <= n;i ++){
        int maxv = 1;
        for(int j = 1;j <= n;j ++){
            f[i][j] = f[i-1][j];
            if(a[i] == b[j]) f[i][j] = std::max(f[i][j], maxv);
            if(b[j] < a[i]) maxv = std::max(maxv, f[i][j]+1);
        }
    }
    int res = 0;
    for(int i = 0;i <= n;i ++) res = std::max(res, f[n][i]);
    std::cout << res << std::endl;
    
    return 0;
}