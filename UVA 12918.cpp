#include <iostream>

using namespace std;

int main(){
	long long int T,n,m,ans,top,down;       //因為乘積超過int範圍 
	cin >> T;
	for(int o=0;o<T;o++){
		cin >> n >> m;
		
		top =  m-1;     //只需計算失敗次數 
		down = m-n;
		ans = (top+down)*n/2;
		
		cout << ans << endl;
	} 
}
