#include <iostream>
#include <math.h>
using namespace std;
int maxNo(int a,int b,int c,int arr[]){
int n= (sizeof(arr))/sizeof(arr[0]);
sort(arr,arr+n);
int maxElementOfArray= arr[n-1];
return max(max(a,b),max(c,maxElementOfArray));
}
int main(){
	//Already in define no header file required.
cout<<max(2,3)<<endl;
cout<<min(45,2)<<endl;
//cout<<pow(2,3)<<endl;

//There are no restrictions in size but may need to do implicitly cast sometimes.
//Typecasting
//Need here.
int a=(int)2.5;
cout<<a<<endl;

//No need here.
double b=34.8;
int c=b;
cout<<c<<endl;
double result= pow(2,3);
cout<<result<<endl;

cout<<"Enter a, b, c"<<endl;
cin>>a>>b>>c;
cout<<"Enter Array size"<<endl;
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
	cin>>arr[i];
}
int ans= maxNo(a,b,c,arr);
cout<<"Ans is"<<" "<<ans<<endl;
}