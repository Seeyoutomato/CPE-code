#include <iostream>
#include <cstring>
using namespace std;

char table[51][51],word[51];
int Case,m,n,k;


void upper_lower(char a[]){
	for(int i=0;a[i];i++){
		if(a[i]>='A' && a[i]<='Z')
			a[i] +=32;
	}
}

bool locate(int i,int j){           //找八個方向的單字
	int x;
	for(x=1;i-x>=0 && word[x] == table[i-x][j];){        
		x++;
		if(word[x] == '\0')     //全部找到的話跳出 
			return 1;
	}
	for(x=1;i+x<m && word[x] == table[i+x][j];){
		x++;
		if(word[x] == '\0')
			return 1;	
	}
	for(x=1;j-x>=0 && word[x] == table[i][j-x];){
		x++;
		if(word[x] == '\0')
			return 1;
	}
	for(x=1;j+x<n && word[x] == table[i][j+x];){
		x++;
		if(word[x] == '\0')
			return 1;
	}
	for(x=1;i-x>=0 && j-x>=0 && word[x]==table[i-x][j-x];){
		x++;
		if(word[x] == '\0')
			return 1;
	}
	for(x=1;i-x>=0 && j+x<n && word[x]==table[i-x][j+x];){
		x++;
		if(word[x] == '\0')
			return 1;
	}
	for(x=1;i+x<m && j-x>=0 && word[x]==table[i+x][j-x];){
		x++;
		if(word[x] == '\0')
			return 1;
	}
	for(x=1;i+x<m && j+x<n && word[x]==table[i+x][j+x];){
		x++;
		if(word[x] == '\0')
			return 1;
	}
	return 0;
	
}
int main(){
	cin >> Case;
	while(Case--){
		cin >> m >> n;
		for(int i=0;i<m;i++){
			cin >> table[i];
			upper_lower(table[i]);
		}
		int c;
		cin >> c;
		for(int s=0;s<c;s++){
			cin >> word;
			upper_lower(word);	
			int d,e,ok=0;
			for(d=0;d<m && !ok;d++){
				for(e=0;e<n && !ok;e++){
					if(table[d][e] == word[0] && locate(d,e)){
						cout << d+1 << " " << e+1 << endl;
						ok =1;
					}
				}
			}
		}
		if(Case)
			cout << endl;
	}
	return 0;
}
