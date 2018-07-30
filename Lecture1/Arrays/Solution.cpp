#include<iostream>
using namespace std;
int main(){
	//Arrays
	//size of is used for finding length.
	//abort trap is like array out of bound exception.
	int arr1[10];
	//size of array=n
	int n= sizeof(arr1)/sizeof(arr1[0]);
	//cout<<sizeof(arr1)<<endl;
	int j=28;
	for(int i=0;i<n;i++){
		arr1[i]=j;
		j=j-2;
	}
	//use g++ -std=c++11 Solution.cpp for using for each loop
	for(int elem : arr1){
		cout<<elem<<" ";
	}
	cout<<endl;

	//Sorting : no header file required.
	sort(arr1,arr1+n);
	for(int elem : arr1){
		cout<<elem<<" ";
	}
	cout<<endl;
}