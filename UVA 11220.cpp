#include <iostream>
#include <cstring>
using namespace std;

char buf[1001];

int main(){
	int n;
	cin >> n;
	getchar();  //讀空白
	getchar();  //讀\n
	for(int i=1;i<=n;i++){
		cout << "Case " << i << " :\n";
		while(gets(buf)&& buf[0]){
			int count = 1, word = 0, flag = 0;   //word是數到第幾個字母 
			for(int j=0; buf[j]; j++){
				if(buf[j] == ' '){
					word = 0;
					if(flag){
						flag = 0;    //flag->那個單字結束 
						count++;     //換找下個單字 
					}
				}
				else
					word++;
				if(word == count){
					cout << buf[j];
					flag = 1;       //是我要找的字母 
				}
			} 
			cout << endl;
		}
		if(i < n)
			cout << endl;
	}
	
} 
