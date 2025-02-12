#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1100;
int h[N];
int l[N], r[N];

int main(){
	int n;
	cin >> n;
	int res = 0;
	for(int i = 1;i <= n;i ++) cin >> h[i];
	for(int i = 1;i <= n;i ++){
		l[i] = 1;
		for(int j = 1;j < i;j ++){
			if(h[j] < h[i]) l[i] = max(l[i], l[j]+1);
		}
	}
	for(int i = n;i > 0;i --){
		r[i] = 1;
		for(int j = n;j > i;j --){
			if(h[i] > h[j]) r[i] = max(r[i], r[j]+1);
		}
	}
	for(int i = 1;i <= n;i ++) res = max(res, l[i]+r[i]);
	cout << res - 1 << endl;
	return 0;
}