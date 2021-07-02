#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T,S,A,F,x[1000],y[1000];
	cin >> T;
	for(int u=0;u<T;u++){
		cin >> S >> A >> F;
		for(int h=0;h<F;h++){
			cin >> x[h] >> y[h];
		}
		sort(x,x+F);
		sort(y,y+F);
		if(F%2)
			cout << "(Street : " << x[F/2] << ", Avenue: " << y[F/2] << " )" <<endl;
		else
			cout << "(Street : " << x[F/2-1] << ", Avenue: " << y[F/2-1] << " )" <<endl;
	}
}
