#include <iostream>
using namespace std;

int table[1000001]={},Ans[1000001]={};

void Create_divisor(){
	for(int i=1;i<=1000000;i++){
		for(int j=i;j<=1000000;j=j+i){  //2,3,4,5,6,...,的倍數    
			table[j]=table[j]+1;  //可以被j整除 
		}
	}
	int max=0,ans;
	for(int h=1;h<=1000000;h++){
		if(table[h]>=max){
			max = table[h];
			ans = h;          //更好的辦法是把答案丟到全域變數陣列，才不用每次進來要跑一百萬次
			Ans[h] = ans;
		}
		else
			Ans[h] = ans;
	}
	
}
int main(){
	int n,a,max,count;
	Create_divisor();
	while(cin >> n){
		for(int z=0;z<n;z++){
			cin >> a;
			cout << Ans[a] << endl; 	
		}
	}
}
