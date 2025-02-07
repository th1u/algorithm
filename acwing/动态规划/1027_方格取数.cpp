#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20;
int a[N][N];
int f[2*N][N][N];
int main(){
	int t;
	cin >> t;
	memset(a, 0, sizeof(a));
	int x, y, z;
	while(cin >> x >> y >> z, x || y || z) a[x][y] = z;
	for(int k = 2;k <= 2*t;k ++){
		for(int i = 1;i <= t;i ++){
			for(int j = 1;j <= t;j ++){
				int i1 = k - i;
				int j1 = k - j;
				if(i1 >= 1 && i1 <= t && j1 >= 1 && j1 <= t){
					int tmp = a[i][i1];
					if(i1 != j1) tmp += a[j][j1];
					f[k][i][j] = max(f[k][i][j], f[k-1][i-1][j-1]+tmp);
					f[k][i][j] = max(f[k][i][j], f[k-1][i][j-1]+tmp);
					f[k][i][j] = max(f[k][i][j], f[k-1][i][j]+tmp);
					f[k][i][j] = max(f[k][i][j], f[k-1][i-1][j]+tmp);
				}
			}
		}
	}
	cout << f[2*t][t][t] << endl;
	return 0;
}