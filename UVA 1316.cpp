#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct item{
	int price,day;
};

bool cmp(const item &a, const item &b){
	return a.price > b.price;
}

int main(){
	int n,ans,i,j,k,s[10001];
	item t[10001];        //10001個struct 
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> t[i].price >> t[i].day;
		}
		sort(t,t+n,cmp);     //按照價錢排 陣列裡的資料交換  先取價值最大  
		memset(s, -1, sizeof(s)); //陣列全為-1 尚未選過 
		ans = 0;
		for(i=0;i<n;i++){
			int v = t[i].day;
			for(;;){           //while(1) 
				if(s[v]== -1){    //這件沒被選過 一直迴圈，找哪個disjoint set有沒有被用過
					k = v;        
					break;
				}
				else              //被用過的話，就去找比他更早之前的商品有沒有被用過，加上已經先按照 
					v = s[v];     //價錢高低sort了，所以如果在他之前的集合沒被用過的話，直到找到那集合是-1
					              //那代表自己的就是最佳方案      
			}
			if(k){   //只要非0都會進來 
				ans +=t[i].price;
				s[k] = k-1;        //去看比當前更前面的disjoint set，減一就是為了往前找之前的集合 
			}
		}
		cout << ans << endl;
	}
}
