#include <iostream>
#include <string>
using namespace std;
int main(){
	//Not allowed empty
	// int arr[];
	// for(int i=0;i<5;i++){
	// 	arr[i]=i;
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

   
	int arr[5];
	for(int i=0;i<5;i++){
		arr[i]=i;
	}
	cout<<arr<<endl;
	//It prints address.not the array

    //But this is allowed: can defined without declaring size, print all string by cout<<ch
    //And sizeof gives size..
	char ch[]="Hello";
	cout<<ch<<endl;
	cout<<ch[0]<<endl;
	cout<<sizeof(ch)<<endl;
	for(int i=0;i<sizeof(ch);i++){
		cout<<ch[i]<<" ";
	}
	cout<<endl;

	string str="HelloString";

	cout<<str<<endl;
	cout<<str.length()<<endl;
	cout<<str.at(0)<<endl;
	string str1=str.substr(1);
	//Just like java starting to last non included.
	string str2= str.substr(0,3);
	cout<<str<<" "<<str1<<" "<<str2<<endl;
	string str3;
	//But cin of string takes 1 string i.e each word after new space is taken
	//new string means space/enter base word input, not enter base line input
	cin>>str3;
	cout<<str3<<endl;
	//It ends after first space or first enter
	// //Concatenation works fine
	// for(int i=0;i<3;i++){
	// 	string str4;
	// 	cin>>str4;
	// 	str3=str3+" "+str4;
	// }
	// cout<<str3<<endl;

	//Line input.
	//it has a problem that it will start just from the enter of last input or space
	//of last input ,including its space also.
	//In same program so either use cin only or getline only.
	string line;
    getline(cin,line);
    string line2;
    getline(cin,line2);
    cout<<line<<endl;
    cout<<line2<<endl;
    cout<<"hello"<<endl;
    return 0;

}