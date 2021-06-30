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
char data[55][1005];      //這兩個要宣告為全域變數 否則容量不夠
char ans[51];
int main(){
	int n,m,gh,cou,cou1,cou2,cou3; 
	cin >> gh;
	for(int a=0;a<gh;a++){
		cin >> m >> n;           //m列 n行 
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

// 以下是別人的 三個迴圈更簡單省事

#include <stdio.h>
#include <string.h>
#include <limits.h>
int nums[55];
char dnas[55][1005];
char const_dna[4] = {'T', 'G', 'C', 'A'};
int main()
{
    int cases,i,j,k,n,m;
    int minNum;
    int minDnaIndex;
    char ansDns[1005];
    int ansSum, tempSum;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d %d", &m, &n);
        for(i = 0 ; i < m;++i){
            nums[i] = 0;
            scanf("%s", dnas[i]);
        }

        ansSum = 0;
        for(i = 0 ; i < n ;++i){            //關鍵
            minNum = INT_MAX;
            minDnaIndex = -1;
            for(j = 0 ; j < 4;++j)         //關鍵
            {
                tempSum = 0;
                for(k = 0 ; k < m;++k)     //關鍵
                {
                    if(const_dna[j] != dnas[k][i]){
                        tempSum++;
                    }
                }

                if(tempSum <= minNum){
                    minDnaIndex = j;
                    minNum = tempSum;
                }
            }
            ansSum += minNum;
            ansDns[i] = const_dna[minDnaIndex];
        }
        ansDns[n] = '\0';

        printf("%s\n%d\n", ansDns, ansSum);
    }
    return 0;
}
