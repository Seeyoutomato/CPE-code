#include <iostream>
#include <queue>
using namespace std;
int x[1000001];    // 問題出在這 記憶體容量不夠       
int main(){
	int t;
	cin >> t;
	int N,M,K;
	for(int f=0;f<t;f++){
		cin >> N >> M >> K;
		for(int a=4;a<=N;a++){
			x[a]=(x[a-1]+x[a-2]+x[a-3])%M+1;
		}
		int now[N+1]={},sum=0,ans=100000,cur;
		queue<int> Q;
		for(int m=1;m<=N;m++){
			cur=x[m];
			if(cur>=1&&cur<=K){
				Q.push(m);
				if(!now[cur])
					sum++;
				now[cur]=m;
				while(Q.front()!=now[x[Q.front()]]) //卡住的點，now[]跟上一行有關 
					Q.pop();
				if(sum==K){
					ans=min(ans,m-Q.front()+1);		
				}
			}
		}
		if(sum==K)
			cout << "Case " << f+1 << ": " << ans << endl;
		else 
			cout << "Case"  << f+1 << ":" <<" sequence nai" << endl;
	}
}
