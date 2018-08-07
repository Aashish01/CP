//Done using Backtracking, LOL!
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
void markYes(char** p,int i,unordered_map<char,int> map1, bool &ans){
	if(i==3){
		ans=true;
		return;
	}
	for(int j=0;j<2;j++){
		if(!(map1.find(p[i][j])==map1.end())){
			if(p[i][j]=='b'){
				map1['b']--;
				if(map1['b']==0){
					map1.erase('b');
				}
			}else if(p[i][j]=='o'){
				map1['o']--;
				if(map1['o']==0){
					map1.erase('o');
				}
			}
			markYes(p,i+1,map1,ans);
			if(p[i][j]=='b'){
				if(map1.find('b')==map1.end()){
                   map1['b']=1;
				}else{
					map1['b']++;
				}
			}else if(p[i][j]=='o'){
				if(map1.find('o')==map1.end()){
                   map1['o']=1;
				}else{
					map1['o']++;
				}
			}
		}
	}
	return;
}
void isFriend(string str1,string str2){
	char** p= new char*[3];
	for(int i=0;i<3;i++){
		p[i]= new char[2];
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++){
			p[i][0]=str1.at(i);
			p[i][1]=str2.at(i);
		}
	}
	bool ans=false;
	unordered_map<char,int> map1;
	map1['b']=2;
	map1['o']=1;
	markYes(p,0,map1,ans);
	if(ans==false){
		cout<<"no"<<"\n";
	}else{
		cout<<"yes"<<"\n";
	}
	for(int i=0;i<3;i++){
		delete [] p[i];
	}
	delete [] p;
	return ;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		string str1,str2;
		cin>>str1>>str2;
		isFriend(str1,str2);
	}
	return 0;
}