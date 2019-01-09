#include <iostream>
#include <algorithm>
using namespace std;
int grundy(int n){
	if(n==0){
		return 0;
	}
	int arr[3];
	arr[0]= grundy(n/2);
	arr[1]=grundy(n/3);
	arr[2]=grundy(n/6);

	sort(arr,arr+3);
	if(arr[0]==0 && arr[1]==0 && arr[2]==0){
		return 1;
	}
	if(arr[0]==0 && arr[1]==0 && arr[2]==1){
		return 2;
	}
	if(arr[0]!=0){
		return 0;
	}else{
		if(arr[1]!=1){
			return 1;
		}else{
			if(arr[2]!=2){
				return 2;
			}else{
				return 3;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	cout<<grundy(n)<<"\n";
	return 0;
}