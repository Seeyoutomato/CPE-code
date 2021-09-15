#include <iostream>
#include <cstring>
using namespace std;
int flag[5][5];
int confirm(int array[5][5]){
	for(int i=0;i<5;i++){
		if(array[0][i]==1 && array[1][i]==1 && array[2][i]==1 && array[3][i]==1 && array[4][i]==1)
			return 1; 
	}
	for(int j=0;j<5;j++){
		if(array[j][0]==1 && array[j][1]==1 && array[j][2]==1 &&array[j][3]==1 && array[j][4]==1)
			return 1; 
	}
	if(array[0][0]==1 && array[1][1]==1 && array[3][3]==1 && array[4][4]==1)
			return 1;
	if(array[4][0]==1 && array[3][1]==1 && array[1][3]==1 && array[0][4]==1)
			return 1;
	return 0;
}
int main(){
	int n,bingo[5][5],num[76];
	while(cin >> n){
		for(int a=0;a<n;a++){
			memset(flag,0,sizeof(flag));
			flag[2][2]=1;
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++){
					if(i==2 && j==2){
						bingo[i][j]=0;	
						continue;
					} 
					else
						cin >> bingo[i][j];
				}
			}
			for(int b=1;b<=75;b++)
				cin >> num[b];
			int out=0;
			for(int x=1;x<=75;x++){
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						if(bingo[i][j]==num[x]){
							flag[i][j]=1;
							//cout << bingo[i][j] << " ";
						}
						if(confirm(flag)){
							cout << "BINGO after " << x << " numbers announced" << endl;
							out=1;
							/*for(int i=0;i<5;i++){
								for(int j=0;j<5;j++){
									cout << flag[i][j] << " ";
								}
								cout << endl;
							}*/
							break;
						}
					}
					if(out)
						break;
				}
			if(out)
				break;	
			}
		}
	}
}
