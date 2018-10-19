#include <iostream>
using namespace std;
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int n;
		cin>>n;
		int * arr= new int[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int count=0;
		for(int i=0;i<n-1;i++){
			if(arr[i+1]-arr[i]<0){
				count++;
			}
			if(count==2){
				break;
			}
		}
		if(count==0){
			cout<<"YES"<<"\n";
		}else if(count==1 && (arr[n-1]<=arr[0])){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
		delete [] arr;
	}
	return 0;
}