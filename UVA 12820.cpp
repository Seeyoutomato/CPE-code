#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n,mark,t,j,c,b=0,i;
	string input;
	while(cin >> n){
		mark=0;
		for(int a=0;a<n;a++){
			int num[26]={},ans[30]={};
			cin >> input;
			for(int w=0;w<input.length();w++)
				num[input[w] - 'a']++;          //remarkable 
			for(i=0,c=0,j=0;i<26;i++){
				if(num[i]){
					j++;
					if(ans[num[i]]){
						c=1;
						break;
					}
					ans[num[i]]=1;
				}
			}
			if(c==0 && j!=1)      //一個字母不算 
				mark++;
		}
		cout << "Case " << ++b << " : " << mark << endl;
	}
}
