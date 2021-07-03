#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int T,D,L[10000],H[10000],Q,P,change,ans;
	cin >> T;
	string M[10000];                //不能用char 輸入時有問題 
	for(int u=0;u<T;u++){
		cin >> D;
		for(int h=0;h<D;h++){
			cin >> M[h] >> L[h] >> H[h]; 
		}
		cin >> Q;
		for(int r=0;r<Q;r++){
			cin >> P;
			change =0;
			for(int i=0;i<D;i++){
				if(P>=L[i] && P<=H[i]){
					ans = i;
					change++;
				}
			}
			if(change>1 || change==0)
				cout << "UNDETERMINED" << endl;
			else
				cout << M[ans] << endl;
			
			
		}
	}
}
