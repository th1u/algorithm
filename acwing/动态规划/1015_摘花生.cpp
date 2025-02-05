#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
int a[N][N];
int f[N][N];
int main(){
	int t;
	cin >> t;
	while(t--){
		int r, c;
		cin >> r >> c;
		for(int i = 1;i <= r;i ++){
			for(int j = 1;j <= c;j ++){
				cin >> a[i][j];
			}
		}
		memset(f, 0, sizeof(f));
		for(int i=1;i<=r;i++)
			for(int j=1;j <= c;j ++)
				f[i][j] = max(f[i][j-1]+a[i][j], f[i-1][j]+a[i][j]);
		cout << f[r][c] << endl;
	}
	return 0;
}