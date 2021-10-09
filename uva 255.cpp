#include <iostream>

using namespace std;


int main(){
	int a,b,c;
	while(cin >> a >> b >> c){
		if(a==b)
			cout << "Illegal state" << endl;
		else{
			if(b/8 != c/8 && b%8 != c%8)
				cout << "Illegal move" << endl;
			else{
				if(b == c)
					cout << "Illegal move" << endl;
				else if((a==0 && c==0) || (a==7 && c==14) || (a==56 && c==49) || (a==63 && c==54))
					cout << "Stop" << endl;					
				else if((a/8 == c/8) && (b/8 == c/8)){   
					if((a-c)*(a-b)<=0)                    //a不能夾在b c之間
						cout << "Illegal move" << endl;
					else if((a+1)==c || (a-1)==c)
						cout << "Move not allowed" << endl;
					else
						cout << "Continue" << endl;
				}
				else if((a%8 == c%8) && (b%8 == c%8)){   
					if((a-c)*(a-b)<=0)                    //a不能夾在b c之間
						cout << "Illegal move" << endl;
					else if((a+8)==c || (a-8)==c)
						cout << "Move not allowed" << endl;
					else
						cout << "Continue" << endl; 
				}
				else{    
					if(((c-1)/8 == c/8 && c-1 == a) || (c+1)/8 == c/8 && c+1 == a)  //a c同列,b c同行 
						cout << "Move not allowed" << endl;
					else if((c-8 >= 0 && c-8 == a) || c+8 <64 && c+8 == a) //a c同行,b c同列 
						cout << "Move not allowed" << endl;
					else
						cout << "Continue" << endl; 
				}
			}
		}
			
	}
}
