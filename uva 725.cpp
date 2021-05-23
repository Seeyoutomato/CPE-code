#include <iostream>
using namespace std;

bool diff(int a,int b){
	int n[10];
	if(a<10000 && b<10000) 
		return false;
	for(int j=0;j<10;j++) n[j]=0;
	if(a<10000 || b<10000) n[0]=1; //如果小於10000,n[0]就會沒被算到 
	while(a>0){
		if(n[a%10]==0){
			n[a%10]=1;
			a/=10;
		}
		else
			return false;			
	}
	while(b>0){
		if(n[b%10]==0){
			n[b%10]=1;
			b/=10;
		}
		else
			return false;
	}
	return true;
}
int main(){
	int n,a,no;
	while(cin >> n){
		no = 1;
		if(n==0)
			break;
		for(int i=1234;i<=49876;i++){
			a = i*n;
			if(a>99999)
				continue;
			else{
				if(diff(a,i)){
					if(a<10000){
						no=0;
						cout << "0" << a << "/" << i << "=" << n << endl;
					}
					if(i<10000){
						no=0;
						cout << a << "/" << "0" << i << "=" << n << endl;
					}	
			  }	
      }		
		}
		if(no==1)
			cout << "There is no answer for " << n << "." << endl;		
	}
}
