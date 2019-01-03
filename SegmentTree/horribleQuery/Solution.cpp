#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
void buildSegmentTree(long long int *p, int * arr, int start, int end, int index,long long int * lazy){
	if(start==end){
		p[index]=arr[start];
		lazy[index]=0;
		return;
	}
	int mid=(start+end)/2;
	buildSegmentTree(p,arr,start,mid,2*index,lazy);
	buildSegmentTree(p,arr,mid+1,end,2*index+1,lazy);
	p[index]=p[2*index]+p[2*index+1];
	lazy[index]=0;
	return;
}
void update(long long int *p,long long int * lazy, int start, int end , int l, int r,int x, int index){
  	if(lazy[index]!=0){
		long long int y=lazy[index];
			lazy[index]=0;
			if(start!=end){
				

				lazy[2*index]+=(long long int)y;
				lazy[2*index+1]+=(long long int)y;

			}
			
			p[index]+=y*(end-start+1);
		}
	if(start>r || end <l || start>end){
		return;
	}

  if(start >=l && end <=r){

		p[index]+= x*(end-start+1);
		if(start!=end){
			

				lazy[2*index]+=x;
				lazy[2*index+1]+=x;
		}
		return;
	}
		int mid=(start+end)/2;
		update(p,lazy,start,mid,l,r,x,2*index);
		update(p,lazy,mid+1,end,l,r,x,2*index+1);
		p[index]=p[2*index]+p[2*index+1];
		return;
	
}
int query(long long int * p,long long int * lazy, int start, int end, int l, int r, int index){
if(start>r || end <l){
		return 0;
	}
  if(lazy[index]!=0){
		long long int y=lazy[index];
			lazy[index]=0;
			if(start!=end){
				

				lazy[2*index]+=(long long int)y;
				lazy[2*index+1]+=(long long int)y;

			}
			
			p[index]+=y*(end-start+1);
		}
	
  	
  if(start >=l && end <=r){
		return p[index];
     }
		int mid=(start+end)/2;
		long long int a= query(p,lazy,start,mid,l,r,2*index);
	long long	int b= query(p,lazy,mid+1,end,l,r,2*index+1);
		return a+b;
	
}
void printTree(long long int *p ,long long int * lazy, int start, int end, int index){
	cout<<index<<" "<<p[index]<<" "<<lazy[index]<<endl;
	if(start==end){
		return;
	}
	int mid=(start+end)/2;
	printTree(p,lazy,start,mid,2*index);
	printTree(p,lazy,mid+1,end,2*index+1);
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int li=0;li<t;li++){
		int n;
	cin>>n;
	int * arr= new int[n];
	long long int * p=new long long int[4*n];
	long long int * lazy= new long long int[4*n];
	for(int i=0;i<n;i++){
		arr[i]=0;
	}
	buildSegmentTree(p,arr,0,n-1,1,lazy);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int ch;
		cin>>ch;
		if(ch==0){
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			update(p,lazy,0,n-1,l,r,x,1);
			
		}else{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<query(p,lazy,0,n-1,l,r,1)<<endl;
		}
	}
	delete [] arr;
	delete [] p;
	delete [] lazy;
	}
	
	return 0;
}