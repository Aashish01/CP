#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
	int t;
	cin>>t;
	unordered_map<char,char> map1;
	int k=0;
	int j=122;
	for(int i=97;i<=122;i++){
		char ch1= i;
		char ch2= j-k;
		map1[ch1]=ch2;
		k++;
	}

	for(int l=0;l<t;l++){
		int n;
		cin>>n;
		string str1;
		cin>>str1;
		string str2="";
		if(n%2==0){
			for(int i=0;i<str1.length();i+=2){
              str2=str2+str1.at(i+1)+str1.at(i);
			}
		}else{
			for(int i=0;i<str1.length()-1;i+=2){
              str2=str2+str1.at(i+1)+str1.at(i);
			}
			str2= str2+str1.at(str1.length()-1);
		}
		string str3="";
		for(int i=0;i<str2.length();i++){
			char ch3=str2.at(i);
			str3=str3+map1[ch3];
		}
		cout<<str3<<endl;
	}
}