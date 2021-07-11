#include <iostream>

using namespace std;

int main(){
	int h1,h2,m1,m2,ans;
	while(cin >> h1 >> m1 >> h2 >> m2){
		if(h1 == 0 && m1==0 && h2 ==0 && m2 == 0)
			break;
		if(h1*60+m1 > h2*60+m2)
			ans = 1440 - (h1*60+m1 - h2*60-m2);
		else
			ans = h2*60+m2 - h1*60-m1;
		cout << ans << endl; 
	}
}
