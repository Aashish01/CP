#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node{
	bool hold;
	int sum, maxSum, bestPrefixSum, bestSuffixSum;
};
void buildSegmentTree(Node * p, int* arr, int start, int end, int index){
	if(start==end){
		p[index].sum= arr[start];
		p[index].maxSum= arr[start];
		p[index].bestPrefixSum= arr[start];
		p[index].bestSuffixSum= arr[start];
        p[index].hold=false;
		return;
	}
	int mid= (start+end)/2;
	buildSegmentTree(p,arr,start,mid,2*index);
	buildSegmentTree(p,arr,mid+1,end,2*index+1);
	p[index].sum= p[2*index].sum+ p[2*index+1].sum;
	p[index].bestPrefixSum= max(p[2*index].bestPrefixSum, p[2*index+1].bestPrefixSum + p[2*index].sum);
	p[index].bestSuffixSum= max(p[2*index+1].bestSuffixSum,p[2*index+1].sum+p[2*index].bestSuffixSum);
	p[index].maxSum= max(max(p[2*index].maxSum, p[2*index+1].maxSum),p[2*index].bestSuffixSum+p[2*index+1].bestPrefixSum);
	p[index].hold=false;
	return;

}
Node query(Node * p, int l, int r, int start, int end, int index){
	int mid=(start+end)/2;
	if(start>r || end <l){
		//created a null node to return.
         Node n1;
         n1.hold=true;
         return n1;
	}else if(start>=l && end <=r){
		return p[index];
	}else{
		Node n1= query(p,l,r,start,mid, 2*index);
		Node n2= query(p,l,r,mid+1,end,2*index+1);
		if(n1.hold == true){
           Node n3;
		n3.sum= n2.sum;
		n3.bestPrefixSum= n2.bestPrefixSum;
		n3.bestSuffixSum= n2.bestSuffixSum;
		n3.maxSum= n2.maxSum;
		n3.hold=false;
		return n3;
		}else if(n2.hold ==true){
           Node n3;
		n3.sum= n1.sum;
		n3.bestPrefixSum= n1.bestPrefixSum;
		n3.bestSuffixSum= n1.bestSuffixSum;
		n3.maxSum= n1.maxSum;
		n3.hold=false;
		return n3;
		}else{
			Node n3;
		n3.sum= n1.sum+ n2.sum;
		n3.bestPrefixSum= max(n1.bestPrefixSum,n1.sum+n2.bestPrefixSum);
		n3.bestSuffixSum= max(n2.bestSuffixSum, n2.sum+ n1.bestSuffixSum);
		n3.maxSum= max(max(n2.maxSum,n1.maxSum),n1.bestSuffixSum+n2.bestPrefixSum);
		n3.hold=false;
		return n3;
		}
		
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	Node * p= new Node[4*n];
	int * arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	buildSegmentTree(p,arr,0,n-1,1);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		Node n1= query(p,l,r,0,n-1,1);
		cout<<n1.maxSum<<endl;

	}
	delete [] p;
	delete [] arr;
	return 0;
}