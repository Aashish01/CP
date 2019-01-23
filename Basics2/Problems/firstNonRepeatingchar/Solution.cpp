#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
char nonRepeatingCharacter(string str){
	unordered_map<char,int> m;
	for(int i=0;i<str.length();i++){
		char ch= str.at(i);
		if(m.find(ch)==m.end()){
			m[ch]=1;
		}else{
			m[ch]++;
		}
	}
	for(int i=0;i<str.length();i++){
		char ch= str.at(i);
		if(m[ch]==1){
			return ch;
		}
	}
	return str.at(0);
}
int main(){
	string str;
	cin>>str;
	char ch= nonRepeatingCharacter(str);
	cout<<ch<<endl;
	return 0;
}