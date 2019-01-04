#include <climits>
#include <iostream>
using namespace std;
int mcm(int** arr, int * p,int i, int j){
	if(arr[i][j]!=-1){
		return arr[i][j];
	}
	if(i==j){
		arr[i][j]=0;
		return 0;
	}
	int min= INT_MAX;
	for(int k=i;k<j;k++){
		int x= mcm(arr,p,i,k)+mcm(arr,p,k+1,j)+(p[i-1]*p[k]*p[j]);
		if(x<min){
			min=x;
		}
	}
	arr[i][j]=min;
	return arr[i][j];
}
int cost(int * p, int n){
	int** arr= new int*[n+1];
	for(int i=0;i<n+1;i++){
		arr[i]= new int[n+1];
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			arr[i][j]=-1;
		}
	}
	return mcm(arr,p,1,n);
}
int main(){
	int n;
	cin>>n;
	int * p= new int[n+1];
	for(int i=0;i<n+1;i++){
		cin>>p[i];
	}
	cout<<cost(p,n)<<endl;
	return 0;
}
