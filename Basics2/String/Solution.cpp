#include <iostream>
#include <string>
using namespace std;
int main(){
	string str1="Hello";
    //length
	cout<<str1.length()<<endl;
	//char at i
	cout<<str1.at(2)<<endl;
	//substring: starting from index i=1 , take next 2 chars
	cout<<str1.substr(1,2)<<endl;
	//starting from char i=1 ,take all char
	cout<<str1.substr(1)<<endl;

	//Concatenation
	string str2="";
	str2= str2+str1+" ";
	cout<<str2<<endl;
    
    //line input
    string line;
    getline(cin,line); //use getline only for word input also ,its better.

    cout<<line<<endl;
    
    string str3= "Ashish";
    //copy str3 to str4 or make str4 using str3
    string str4(str3);
    cout<<str4<<endl;
    //make str5 using str3, using substring starting from i=1 & taking next 3 index.
    string str5(str3,1,3);
    cout<<str5<<endl;

    //comparing two string
    string str6,str7;
    getline(cin,str6);
    getline(cin,str7);
    if(str6.compare(str7)==0){
    	cout<<"equal"<<endl;
    }else{
    	cout<<"Not equal";
    }



}