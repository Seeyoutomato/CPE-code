#include <iostream>
using namespace std;

int main(){
	int n;
	int a,b,dis;
	cin >> n;
	while(n--){
		cin >> a >> b;
		dis = b-a;
		int leng=0,step=0;
		long long int all=0;
		while(1){
			leng++;
			if(all+leng*2> dis)
				break;
			else{
				all += leng*2;
				step += 2;
			}
		}
		if(all+leng < dis)
			step += 2;          //all+leng < dis < all + leng*2
		else if(all != dis)
			step += 1;
		cout << step << endl; 
	}
}
