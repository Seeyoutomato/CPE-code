#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int T,N,G;
	int price[1005],weight[1005],ans[35],MW,money;
	while(cin >> T){
		
		for(int q=0;q<T;q++){
			memset(ans,0,sizeof(ans));
			cin >> N;
			for(int w=0;w<N;w++){
				cin >> price[w] >> weight[w];
			}
			for(int i=0;i<N;i++){                 //當時想不到該怎麼放
				for(int j=30;j>=weight[i];j--){   // 
					if(ans[j-weight[i]] + price[i] > ans[j])
						ans[j] = ans[j-weight[i]] + price[i]; 
				}
			}	
			money = 0;	
			cin >> G;         //人 
			for(int q=0;q<G;q++){
				cin >> MW;
				money += ans[MW];	
			}		
			cout << money << endl;
		}
	}
}
