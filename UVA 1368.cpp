#include <iostream>

using namespace std;

char who_biggest(int a,int b,int c,int d){
	if(a>=b && a>=c && a>=d)
		return 'A';
	else if(b>a && b>=c && b>=d)
		return 'C';
	else if(c>a && c>b && c>=d)
		return 'G';
	else if(d>a && d>b && d>c)
		return 'T';
}

int main(){
	int n,m,gh,cou,cou1,cou2,cou3; 
	char ans[51]={};
	cin >> gh;
	for(int a=0;a<gh;a++){
		cin >> m >> n;           //m列 n行 
		char data[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin >> data[i][j];
			}
		}
		for(int i=0;i<n;i++){
			cou=0;cou1=0;cou2=0;cou3=0;              //記每一行哪個大 
			for(int j=0;j<m;j++){
				switch(data[j][i]) {           //忘記大括號 
					case 'A':
						cou++;
						break;
					case 'C':
						cou1++;
						break;
					case 'G':
						cou2++;
						break;
					case 'T':
						cou3++;
						break;
				} 
			}
			ans[i] = who_biggest(cou,cou1,cou2,cou3);
		}
		int wrongans=0;
		for(int x=0;x<n;x++){
			for(int y=0;y<m;y++){
				if(data[y][x] != ans[x])
					wrongans++;
			}
		}
		for(int u=0;u<n;u++)
			cout << ans[u];
		cout << endl << wrongans << endl;		
	}
}
