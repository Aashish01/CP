#include <iostream>
#include <algorithm>
using namespace std;
bool isValid(int* arr, int n, int min, int cow,int lastIndex){
	cow--;
	for(int i=1;i<n;i++){
		if((arr[i]-arr[lastIndex])>=min){
			cow--;
			lastIndex=i;
		}
		if(cow==0){
			return true;
		}
	}
	if(cow==0){
		return true;
	}
	return false;
}
int aggressiveCows(int* arr, int n,int cow,int start, int end){
	int min= (start+end)/2;
	if(start>end){
		return min;
	}
	if(!isValid(arr,n,min,cow,0)){
		return aggressiveCows(arr,n,cow,start,min-1);
	}
	return aggressiveCows(arr,n,cow,min+1,end);

}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x;
		int cow;
		cin>>x>>cow;
		int* p= new int[x];
		for(int j=0;j<x;j++){
			cin>>p[j];
		} 
		sort(p,p+x);
		int ans= aggressiveCows(p,x,cow,0,p[x-1]-p[0]);
		cout<<ans<<endl;
		delete [] p;
	}
	return 0;
}