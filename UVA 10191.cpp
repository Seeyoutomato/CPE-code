#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int T,hb,mb,he,me,bemin,endmin,Case=0;
	string ss;
	int race[481];
	
	while(cin >> T){
		int max=0,beginrace=0;
		getline(cin,ss);       //題目輸入不定 
		memset(race,0,sizeof(race));
		race[480] = 1;                 //乾 晚上6點下班回家了 
		for(int s=0;s<T;s++){
			getline(cin,ss);
			hb = (ss[0]-'0')*10 + ss[1]-'0';
			mb = (ss[3]-'0')*10 + ss[4]-'0';
			he = (ss[6]-'0')*10 + ss[7]-'0';
			me = (ss[9]-'0')*10 + ss[10]-'0';
			bemin = hb*60+mb-600;
			endmin = he*60+me-600;
			for(int i=bemin;i<endmin;i++){
				race[i] = 1;   //工作中 
			}
		}
		int countmin,now,racehour,racemin,maxhour,maxmin;
		if(race[0]==0)
			countmin=1;
		else
			countmin=0;
		for(int j=1;j<481;j++){
			if(race[j-1]==0 && race[j]==0){ 
				countmin++;
			}
			if(race[j-1]==1 && race[j]==0){ 
				countmin=1;
			}
			if(race[j-1]==0 && race[j]==1){
				if(max < countmin){    //插哪 
					max = countmin;
					beginrace = j - max;   //最長的nap開始時間 
				}
			}	
		}
		racehour = (beginrace+600)/60;
		racemin = (beginrace+600)%60;
		if(racemin<10)
			cout << "Day #" << ++Case << ": the longest nap starts at "	<< racehour << ":0" << racemin;
		else
			cout << "Day #" << ++Case << ": the longest nap starts at "	<< racehour << ":" << racemin;
		if(max >= 60)
			cout << " and will last for " << max/60 << " hours and " << max%60 << " minutes." << endl;
		else
			cout << " and will last for " << max << " minutes." << endl;		
			
	} 
}
