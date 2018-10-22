#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
void buildSegmentTree(int* arr,int* tree, int start, int end, int index){
	if(start==end){
		tree[index]=arr[start];
		return;
	}
	int mid= (start+end)/2;
	buildSegmentTree(arr,tree,start,mid,2*index);
	buildSegmentTree(arr,tree,mid+1,end,(2*index) +1);
	tree[index]=min(tree[2*index],tree[(2*index)+1]);
}
int query(int* tree, int l,int r, int start,int end,int index){
	if(start>=l && end<=r){
		return tree[index];
	}
	if(end<l || start>r){
		return INT_MAX;
	}
	int mid= (start+end)/2;
	int minimum= min(query(tree,l,r,start,mid,2*index), query(tree,l,r,mid+1,end,(2*index)+1));
	return minimum;
}
void update(int* tree, int start, int end, int index, int gAIndex,int value){
	if(start==end){
		tree[index]=value;
		return;
	}
	int mid=(start+end)/2;
	if(gAIndex>mid){
		update(tree,mid+1,end,(2*index)+1,gAIndex,value);
		tree[index]=min(tree[2*index],tree[(2*index)+1]);
	}
	if(gAIndex<=mid){
		update(tree,start,mid,2*index,gAIndex,value);
		tree[index]=min(tree[2*index],tree[(2*index)+1]);
	}
	
}
int main(){
	int n,q;
	cin>>n>>q;
	int* arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	} 
	int * tree= new int[4*n];
	for(int i=0;i<4*n;i++){
		tree[i]=-1;
	}
	buildSegmentTree(arr,tree,0,n-1,1);
	for(int i=0;i<q;i++){
		char ch;
		cin>>ch;
		int a,b;
		cin>>a>>b;
		if(ch=='q'){
			cout<<query(tree,a-1,b-1,0,n-1,1)<<"\n";
		}
		if(ch=='u'){
			update(tree,0,n-1,1,a-1,b);
		}
	}
	

	delete [] arr;
	delete [] tree;

	return 0;


}