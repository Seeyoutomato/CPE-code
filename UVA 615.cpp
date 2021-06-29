#include <iostream>

using namespace std;

/*int main(){
	int n,m,node[102],nottree,c=1,count,here,bug=0;
	for(int i=0;i<102;i++)
		node[i] = -1;
	while(cin >> n >> m){
		if(n==0 && m ==0){
			count=0;
			for(int i=0;i<102;i++){
				if(node[i]==1){
					count++;
					here=i;
				}
			}
			if(count>1 || nottree==1)   //原本寫 else if(count>1 || nottree==1)，因為上面一行count本來就會等於1了 所以根本不會進來else if 
				cout << "Case " << c++ <<  " is not a tree." << endl;
			else if(count==1){
				cout << "Case " << c++ << " is a tree. Root is " << here <<endl;
				//cout << bug << endl;
			}		
			for(int i=0;i<102;i++)
				node[i] = -1;
			nottree=0;
			
		}
		else if(n<0 && m<0)
			break;
		if(node[n] != 0){  //沒被指定過或者沒被別點連到 
			node[n]=1;
		}
		if(node[m] == 0){
			nottree=1;
			//bug++;
		}
		node[m]=0;
		//還少一個判斷cycle 
		
		 
	}
}*/

int main(){
	int father[100001],Case=1,tmp,m,n,root=-1;
	bool is_tree = true;
	for(int i=0;i<100001;i++) father[i] = -1;
	while(cin >> m >> n){
		if(m<0 && n<0)
			return 0;
		if(m==0 && n==0){
			for(int i=0;i<100001;i++){
				if(root == -1 && father[i] != -1)   //直接找最頂端的點 
					root = father[i];
				else if(father[i] != -1 && father[i] != root)  //有兩個以上的root 
					is_tree = false;
			}
			
			if(is_tree == false) 
				cout << "Case " << Case++ << " is not a tree." << endl;
            else 
				cout << "Case " << Case++ << " is a tree. Root is " << root << "." << endl;
            
            root = -1;
            is_tree = true ;
            for(int i=0 ; i<100001 ;i++) father[i] = -1 ;
		}
		else{
			if(father[n]!=-1)   //兩個父親以上 n理論上是直接接m 
				is_tree = false;
			if(m==n)    //自己接自己 
				is_tree = false;
			
			if(father[m] != -1)  //m上還有父親 
				tmp = father[m]; //tmp 拿來記m的父親 
			else
				tmp = m;
				
			if(father[m]==n)  //形成cycle 
				is_tree = false;
			else if(father[n] == -1) //n的父親就是m 
				father[n] = tmp;   //所以直接指向m的父親 如果m上沒有節點那就是-1 
			
			for(int i=0;i<100001;i++){ // 每一次輸入都能直接插入 
				if(father[i] == n)   //一路往上指 
					father[i] = tmp;
			}
		}
	}
}
