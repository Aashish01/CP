#include <iostream>
#include <string>
using namespace std;
void reverse(char str[]){
	int size=0;
    while(str[size]!='\0'){
    	size++;
    }
    string str1="";
    for(int i=size-1;i>=0;i--){
    	char ch= str[i];
    	int l=ch;
    	if((l>=65 && l<=90) || (l>=97 && l<=122)){
          str1+=ch;
    	}
    }
    int j=0;
    for(int i=0;i<size;i++){
    	char ch= str[i];
    	int l=ch;
    	if((l>=65 && l<=90) || (l>=97 && l<=122)){
          str[i]= str1.at(j);
          j++;
    	}
    }
    cout<<str<<endl;
    return;
}
int main(){
	char str[]={'h','e','l','%','o','\0'} ;
	cout<<str<<endl;
	char * p= &str[0];
	cout<<p[2]<<endl;
	reverse(p);
}