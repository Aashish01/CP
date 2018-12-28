#include <iostream>
#include <math.h>
#include <string>
using namespace std;
struct Node{
	int  digit, modulo;
	long long int val;
	bool hold;
};
void buildSegmentTree(Node * p ,int* arr, int start, int end, int index){
	if(start==end){
		if(arr[start]==1){
			p[index].val=1;
			p[index].modulo= 1%3;
			
		}else{
           p[index].val=0;
			p[index].modulo= 0%3;
		}
		p[index].digit=1;
		p[index].hold=false;
		return;
	}
	int mid=(start+end)/2;
	buildSegmentTree(p,arr,start,mid,2*index);
	buildSegmentTree(p,arr,mid+1,end,2*index+1);
	p[index].digit= p[2*index].digit + p[2*index+1].digit;
	p[index].val= (long long int)(pow(2,p[2*index+1].digit)*p[2*index].val )+ p[2*index+1].val;
	
	p[index].hold=false;
	p[index].modulo= p[index].val%3;
	cout<<index<<" "<<p[index].val<<" "<<p[index].modulo<<endl;
	return;
}
Node query(Node * p, int l, int r, int start, int end, int index){
	if(start>r || end <l){
		Node n1;
		n1.hold=true;
		return n1;
	}else if(start>=l && end<=r){
		return p[index];
	}else{
		int mid=(start+end)/2;

		Node n1= query(p,l,r,start,mid, 2*index);
		Node n2= query(p,l,r,mid+1,end,2*index+1);
		Node n3;
		if(n1.hold==true){
           n3=n2;
           return n3;
		}else if(n2.hold==true){
             n3=n1;
             return n3;
		}else{
			n3.digit= n1.digit+n2.digit;
			n3.val= (long long int)(pow(2,n2.digit)*n1.val) + n2.val;
			n3.hold=false;
			n3.modulo= n3.val%3;
			return n3;
		}
	}
}
void update(Node * p, int start, int end, int index, int givenIndex){
	int mid=(start+end)/2;
	if(start==end){
		if(p[index].val==0){
			p[index].val=1;

		}
		return;
	}
	if(givenIndex>mid){
		update(p,mid+1,end,2*index+1,givenIndex);
		p[index].digit= p[2*index].digit + p[2*index+1].digit;
	p[index].val= (long long int)(pow(2,p[2*index+1].digit)*p[2*index].val )+ p[2*index+1].val;
	p[index].hold=false;
	p[index].modulo= p[index].val%3;
	return;
	}
	 if(givenIndex<=mid){
		update(p,start,mid,2*index,givenIndex);
		p[index].digit= p[2*index].digit + p[2*index+1].digit;
	p[index].val= (long long int)(pow(2,p[2*index+1].digit)*p[2*index].val )+ p[2*index+1].val;
	p[index].hold=false;
	p[index].modulo= p[index].val%3;
	return;
	}
}
int main(){
	
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string str;
	cin>>str;
	int * arr= new int[n];
	Node * p= new Node[4*n];
	for(int i=0;i<n;i++){
		char ch= str.at(i);
		if(ch=='0'){
			arr[i]=0;
		}else{
			arr[i]=1;
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	buildSegmentTree(p,arr,0,n-1,1);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		if(t==0){
			int l, r;
			cin>>l>>r;
			Node n1= query(p,l,r,0,n-1,1);
			cout<<n1.modulo<<endl;
		}else{
			int l;
			cin>>l;
			update(p,0,n-1,1,l);
		}
	}
	delete [] p;
	delete [] arr;
	return 0;

}








