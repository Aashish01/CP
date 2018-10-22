#include <iostream>
using namespace std;
void buildSegmentTree(int* arr,int* tree, int start, int end, int index){
	if(start==end){
		tree[index]=arr[start];
		return;
	}
	int mid= (start+end)/2;
	buildSegmentTree(arr,tree,start,mid,2*index);
	buildSegmentTree(arr,tree,mid+1,end,(2*index) +1);
	tree[index]=tree[2*index]+ tree[(2*index)+1];
}
int query(int* tree, int l,int r, int start,int end,int index){
	if(start>=l && end<=r){
		return tree[index];
	}
	if(end<l || start>r){
		return 0;
	}
	int mid= (start+end)/2;
	int sum=query(tree,l,r,start,mid,2*index)+ query(tree,l,r,mid+1,end,(2*index)+1);
	return sum;
}
void update(int* tree, int start, int end, int index, int gAIndex,int value){
	if(start==end){
		tree[index]=value;
		return;
	}
	int mid=(start+end)/2;
	if(gAIndex>mid){
		update(tree,mid+1,end,(2*index)+1,gAIndex,value);
		tree[index]=tree[2*index]+tree[(2*index)+1];
	}
	if(gAIndex<=mid){
		update(tree,start,mid,2*index,gAIndex,value);
		tree[index]=tree[2*index]+tree[(2*index)+1];
	}
	
}
int main(){
	int n;
	cin>>n;
	int* arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	} 
	int * tree= new int[4*n];
	for(int i=0;i<4*n;i++){
		tree[i]=-1;
	}
	buildSegmentTree(arr,tree,0,n-1,1);
	for(int i=0;i<4*n;i++){
		if(tree[i]!=-1){
			cout<<"index: "<<i<<" ,value: "<<tree[i]<<" ";
		}
	}
	cout<<"\n";

	//Query
	int l,r;
	cin>>l>>r;
	cout<<"Query: "<<query(tree,l,r,0,n-1,1)<<"\n";

	//update
	int gAIndex,value;
	cin>>gAIndex>>value;
	update(tree,0,n-1,1,gAIndex,value);
    for(int i=0;i<4*n;i++){
		if(tree[i]!=-1){
			cout<<"index: "<<i<<" ,value: "<<tree[i]<<" ";
		}
	}
	cout<<"\n";

	delete [] arr;
	delete [] tree;
	return 0;


}