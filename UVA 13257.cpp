#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int N,n;
	string vocal;	
	cin >> N;
	 
	while(N--){
		cin >> vocal;
		int list[26] = {};
		int n = vocal.size();
		int table[n];
		
		for(int i=0;i<n;i++){
			table[i] = list[vocal[i] - 'A'];  // 
			list[vocal[i]-'A'] = i+1;   //記錄在哪出現過 
		}
		
		/*for(int i=0;i<n;i++){
			cout << table[i] << " ";
		}
		cout << endl;
		for(int i=0;i<26;i++){
			cout << list[i] << " ";
		}*/
		int count=0;
		for(int i=0;i<n-2;i++){    //三個字母三個迴圈 
			if(table[i]!=0)        //不能放的原因 
				continue;
			for(int j=i+1;j<n-1;j++){  //從第二個開始找，因為第一個一定跟別人不一樣 
				if(table[j]-1>=i+1 && table[j]-1<n-1) //第二個字母的工作;不能放的原因 ;第二個字母可以第一字母重複但前面找過的幾組字母中不可出現 
					continue;
				for(int k=j+1;k<n;k++){
					if(table[k]-1>=j+1 && table[k]-1<n)
						continue;
					count++;
				}
			}
		}
		cout << count << endl;
		
	}
	
} 
