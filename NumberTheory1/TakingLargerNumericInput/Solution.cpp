#include <iostream>
#include <string>
using namespace std;
int main(){
ios_base:: sync_with_stdio(false);
cin.tie(NULL);
string str;
cin>>str;
int num=0;
for(int i=0;i<str.length();i++){
	char ch= str.at(i);
	int j=(int)ch -48;
	num =num*10+j;
}
cout<<num<<"\n";
return 0;
}