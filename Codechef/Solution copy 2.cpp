#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}
int main(){
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int n;
		cin>>n;
		int * p= new int[n];
		for(int i=0;i<n;i++){
			cin>>p[i];
		}
		int result =p[0];
		for(int i=1;i<n;i++){
			result= gcd(p[i],result);

		}
		cout<<result<<endl;
		delete [] p;
	}
}