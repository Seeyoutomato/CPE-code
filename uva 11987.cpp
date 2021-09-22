#include <iostream>

using namespace std;

int ances[200001],sum[200001],mapp[200001],num[200001];      //mapp是在哪一群 ;ances祖先;num群的個數 
int update(int i){
	if(i!=ances[i]){
		ances[i] = update(ances[i]);
	}
	return ances[i];
}
int main(){
	int n,m,com,p,a,b,node;
	while(cin >> n >> m){
		for(int s=0;s<=n;s++){
			ances[s] = sum[s] = mapp[s] = s;
			num[s] = 1; 
		}
		node = n+1;
		while(m--){
			cin >> com ;
			if(com == 3){
				cin >> p;
				int y = update(mapp[p]);
				cout << num[y] << " " << sum[y] << endl;
			}
			else{
				cin >> a >> b;
				int i = update(mapp[a]), j = update(mapp[b]);
				if(com == 1){  //合併 
					if(i!=j){
						sum[j] += sum[i];
						num[j] += num[i];
						ances[i] = j;
						num[i]=0,sum[i]=0;
					}
				}
				else{        //移動 
					if(i!=j){
						mapp[a] = node++;        //為了把a從一個群中抽離出來 獨立 
						ances[mapp[a]] = j;      //結合 
						sum[j] += a,num[j]++;
						sum[i] -= a,num[i]--;
					}
				}
			}
		}
	}
}
