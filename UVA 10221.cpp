#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip> 
using namespace std;


int main(){
	double s,a,ang;
	double disarc,dischord;
	string input;
	while(cin >> s >> a >> input){
		if(input[0] =='m')
			ang = a/60;
		else
			ang = a;
		if(ang>180)
			ang = 360-ang;
		disarc = 2*M_PI*(s+6440)*ang/360.0;
		dischord = 2*(s+6440)*sin(ang*M_PI/360);
		cout << fixed << setprecision(6) << disarc << " " << dischord << endl; //fixed控制小數點後 
	}
}
