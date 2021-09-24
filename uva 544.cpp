#include <iostream>
#include <map>
#include <cstring>
using namespace std;
const int unknownmaxweight = -1;
struct City{
	string name;
	map<string,int> edges;
	int maxweight;
	bool isVisited;
};

int findmaxweight(map<string,City>& roadmap,const string& sourcename,const string& targetname){
	City* currentcity = &(roadmap[sourcename]);
	currentcity->maxweight = INT_MAX;
	while(currentcity != NULL && currentcity->maxweight != unknownmaxweight){
		currentcity->isVisited = true;
		
		City* nextcity = NULL;
		for(map<string,City>::iterator it = roadmap.begin(); it != roadmap.end();it++){
			City* city = &(it->second);   / city每次跟著it換 
			if(currentcity->edges.find(city->name)!=currentcity->edges.end()) {
				int edgemaxweight = currentcity->edges[city->name];
				int maxweight = min(currentcity->maxweight,edgemaxweight);
			
				if(maxweight > city->maxweight)
					city->maxweight = maxweight;
			}
			if(!city->isVisited && (nextcity == NULL || city->maxweight > nextcity->maxweight)){
				nextcity = city;
			}
		}
		currentcity = nextcity;
	}
	return roadmap[targetname].maxweight;
}
int main(){
	int n,r,case1=1;
	while((cin >> n >> r) && n!=0 && r!=0){
		map<string,City> roadmap;
		
		for(int i=0; i<r;i++){
			string sourcecity,targetcity;
			int maxweight;
			cin >> sourcecity >> targetcity >> maxweight;
			
			if(roadmap.find(sourcecity) == roadmap.end()){
				roadmap[sourcecity] = (City){
					sourcecity,map<string,int>(),unknownmaxweight};
				}
			if(roadmap.find(targetcity) == roadmap.end()){
				roadmap[targetcity] = (City){
					targetcity,map<string,int>(),unknownmaxweight};
			}
			
			int* sourcetotarget_maxweight_ptr = &roadmap[sourcecity].edges[targetcity];
			int* targettosource_maxwieght_ptr = &roadmap[targetcity].edges[sourcecity];
			*sourcetotarget_maxweight_ptr = max(*sourcetotarget_maxweight_ptr,maxweight);
			*targettosource_maxwieght_ptr = max(*targettosource_maxwieght_ptr,maxweight);
		}
		string sourcename,targetname;
		cin >> sourcename >> targetname;
		cout << "Scenario #" << case1++ << " " << findmaxweight(roadmap,sourcename,targetname) << "tons" << endl; 	
			
	}
	return 0;	
}
