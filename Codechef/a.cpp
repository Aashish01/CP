#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
	float totalCost=0;
	unordered_map<string,int> m1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		
		if(m1.find(str)==m1.end()){
			int cost=0;
			if(str.length()!=0){
				cost=cost+2;
				for(int j=1;j<str.length();j++){
					char ch1= str.at(j-1);
					char ch2= str.at(j);
					if((ch1=='d' || ch1=='f')&& (ch2=='d'|| ch2=='f')){
						cost+=4;
					}
					else if((ch1=='j'|| ch1=='k')&& (ch2=='j'||ch2=='k')){
                         cost+=4;
					}else{
						cost+=2;
					}
				}
			}
			m1[str]=cost;
			totalCost+=m1[str];
		}else{
			totalCost+=0.5* m1[str];
		}
	}
	cout<<(int)totalCost<<"\n";
	}
	return 0;
	

}