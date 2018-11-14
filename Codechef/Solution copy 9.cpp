#include <iostream>
#include <string>
using namespace std;
void reverse(char str[]){
  string str1= str;
  string str2="";
  bool * p= new bool[str1.length()];
  for(int i=0;i<str1.length();i++){
  	p[i]=false;
  	char ch= str1.at(i);
  	int l= ch;
  	if((l>=65 && l<=90) || (l>=97&& l<=122)){
  		str2=str2+ch;
    }else{
    	p[i]=true;
    }
  }
  string str3=str;
  int j=str2.length()-1;
  for(int i=0;i<str1.length();i++){
  	if(p[i]!=true){
  		str3.at(i)=str2.at(j);
  		j--;
  	}
  }
  delete [] p;
  char * p2= new char[str3.length()];
  for(int i=0;i<str3.length();i++){
  	p2[i]=str3.at(i);
  }
  str=p2;
  cout<<str;
  


  // cout<<str1.length()<<endl;
  // cout<<str1<<endl;
}
int main(){
  string str;
  cin>>str;
  char * ch= new char[str.length()];
  for(int i=0;i<str.length();i++){
    ch[i]=str.at(i);
  }
  reverse(ch);
  delete [] ch;
}