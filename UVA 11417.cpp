#include <iostream>
using namespace std;

int gcd(int i,int j){
	int r=0;
	while(j!=0){
		r = i%j;
		i = j;
		j = r;
	}
	return i;
}

int main(){
	int G,N,ans[510]={};
	for(int i=1;i<507;i++){
		ans[i] = ans[i-1];
		for(int j=1;j<i;j++)
			ans[i] += gcd(i,j);
	}
	while(cin >> N){
		if(N == 0)
			break;
		else
			cout << ans[N] << endl;
	}
}
