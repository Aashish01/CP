#include <iostream>
#include <climits>
using namespace std;
void buildSegmentTree(int* p, int* arr,int start, int end, int index){
	if(start==end){
		p[index]=arr[start];
		return;
	}
	int mid= (start+end)/2;
	buildSegmentTree(p,arr,start,mid,2*index);
	buildSegmentTree(p,arr,mid+1,end,2*index+1);
	p[index]=p[2*index]+p[2*index+1];
	return;
}
void query(int* p, int l,int r, int start, int end, int index, int* max){
	int mid=(start+end)/2;
	if(start>r || end<l){
		
		return;
	}
	else if(start>=l && end <=r){
		if(start==end){
			
			if(p[index]> *max){
			*max =p[index];
			return;
		     }
		}else{


			if(p[index]> *max){
			*max =p[index];
		    }
		query(p,l,r,start,mid,2*index,max);
		query(p,l,r,mid+1,end,2*index+1,max);
		return;
		}
		
	}else{
		query(p,l,r,start,mid,2*index,max);
	query(p,l,r,mid+1,end,2*index+1,max);
	return;
	}
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int * arr= new int[n];
	int * p= new int[4*n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	buildSegmentTree(p,arr,0,n-1,1);
	
	int max= INT_MIN;
	int * q= &max;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		query(p,l-1,r-1,0,n-1,1,q);
		cout<<*q<<endl;
		*q=INT_MIN;
	}
	delete [] p;
	delete [] arr;
	return 0;
}