#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int prime[1001];

int bfs(int s,int t){
	int count[1001]={};
	queue <int> q;
	q.push(s);
	
	while(!q.empty()){
		int now = q.front();
		q.pop();      //已全部清空 
		
		for(int i=0;prime[i]<now;i++){   // 把各種可能質因數的加法都算出來，但最後也只有一種可能 
			if(!(now%prime[i])){
				int tmp = now + prime[i];
				if(count[tmp])   //******如果之前有更快步驟到達這 ex: tmp = 7 = 2 + 2 + 3   要跑兩次while 
					continue;                         //              tmp = 7 = 2 + 5  這個執行步驟比較少 在while迴圈一次就能執行完 
				                                    
				if(tmp == t)
					return count[now] + 1;   
				else if(tmp < t){
					count[tmp] = count[now] + 1;   //還沒加到t 計次數 
					q.push(tmp);  //暫存檔 
				}
				else  //tmp>t 
					break;   //找不到解 
			}
		}
	}
	return -1;
}

int main(){
	int mark[1001];
	bool notprime[1001]={true,true}; //0,1非質 
	for(int i=2;i<=32;i++){              //1000中，只須找<=sqrt(1000)之數 
		for(int j=i+i;j<1001;j+=i){
			notprime[j] = true;
		}
	}
	int c;
	for(int i=2;i<1001;i++)   //找質數 
		if(!notprime[i])
			prime[c++] = i;
	int Case,s,t;
	while(cin >> s >> t && s && t){   //0,0 out 
		cout << "Case " << ++Case << ": ";
		if(s == t)
			cout << "0" << endl;
		else
			cout << bfs(s,t) << endl; 	
	}
}
