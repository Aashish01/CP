#include <iostream>
using namespace std;
long long countInversion(int* arr, int n, int start, int end){
	if(start==end){
		return 0;
	}
	int mid= (start+end)/2;
	long long x= countInversion(arr,n,start,mid);
	long long y= countInversion(arr,n,mid+1,end);
	int size= end-start+1;
	int *p = new int[size];
	int i= start;
	int j= mid+1;
	int k=0;
	long long sum=0;
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			p[k]=arr[i];
			k++;
			i++;
		}
		if(arr[j]<arr[i]){
			sum+= mid-i+1;
			p[k]=arr[j];
			j++;
			k++;
		}

	}
	if(j>end){
			while(i<=mid){
				p[k]=arr[i];
				i++;
				k++;
			}
		}
		if(i>mid){
			while(j<=end){
				p[k]=arr[j];
				j++;
				k++;
			}
		}
		k=0;
		for(int l=start;l<=mid;l++){
			arr[l]=p[k];
			k++;
		}
		for(int l=mid+1;l<=end;l++){
			arr[l]=p[k];
			k++;
		}
		delete [] p;
		return x+y+sum;
}
long long solve(int A[], int n){
	int * p= &A[0];
	long long ans=countInversion(p,n,0,n-1);
	return ans;
}
int main(){
	int n;
	cin>>n;
	int *p= new int[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	long long ans= solve(p,n);
	cout<<ans<<endl;
	delete [] p;
	return 0;
}