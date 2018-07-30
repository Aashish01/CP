#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//Comparator.
bool compare(int i1, int i2){
	return i1<i2;
}

bool compare1(string str1, string str2){
	return str1.length()<str2.length();
}

int main(){

int arr[5];
for(int i=0;i<5;i++){
	cin>>arr[i];
}
//fix to use cin & getline together.
string nullStore;
getline(cin,nullStore);
//sort
sort(arr+2,arr+5);
for(int elem: arr){
	cout<<elem<<" ";
}
cout<<endl;

sort(arr+0,arr+5);
for(int elem: arr){
	cout<<elem<<" ";
}
cout<<endl;

//Sorting in reverse manner.
sort(arr,arr+5,greater<int>());
for(int elem: arr){
	cout<<elem<<" ";
}
cout<<endl;

//Using comparator

sort(arr,arr+5,compare);
for(int elem: arr){
	cout<<elem<<" ";
}
cout<<endl;
 string arr1[5];
 for(int i=0;i<5;i++){
 	string str;
 	getline(cin,str);
 	arr1[i]=str;
 }
sort(arr1,arr1+5,compare1);
for(string elem: arr1){
	cout<<elem<<" ";
}
cout<<endl;




}