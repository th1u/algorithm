#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;
int a[N][N];
int f[N][N];
int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
			cin >> a[i][j];
	
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(i == 1 && j == 1) f[i][j] = a[i][j];
			else{
				f[i][j] = 0x3f3f3f;
				if(i > 1) f[i][j] = min(f[i][j], f[i-1][j] + a[i][j]);
				if(j > 1) f[i][j] = min(f[i][j], f[i][j-1] + a[i][j]);
			}
		}
	}
	cout << f[n][n] << endl;

	return 0;
}