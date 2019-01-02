#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
void buildSegmentTree(int *p, int * arr, int start, int end, int index, int * lazy){
	if(start==end){
		p[index]=arr[start];
		lazy[index]=0;
		return;
	}
	int mid=(start+end)/2;
	buildSegmentTree(p,arr,start,mid,2*index,lazy);
	buildSegmentTree(p,arr,mid+1,end,2*index+1,lazy);
	p[index]=min(p[2*index],p[2*index+1]);
	lazy[index]=0;
	return;
}
void update(int *p, int * lazy, int start, int end , int l, int r,int x, int index){
	if(lazy[index]!=0){
			int y=lazy[index];
			lazy[index]=0;
			if(start!=end){
				lazy[2*index]+=y;
				lazy[2*index+1]+=y;

			}
			p[index]+=y;
			// cout<<"Settle the new value  "<<p[index]<<endl;
		}
	if(start>r || end <l){
		return;
	}else if(start >=l && end <=r){
		// if(lazy[index]!=0){
		// 	int y=lazy[index];
		// 	lazy[index]=0;
		// 	if(start!=end){
		// 		lazy[2*index]+=y;
		// 		lazy[2*index+1]+=y;

		// 	}
		// 	p[index]+=y;
		// 	cout<<"Settle the new value  "<<p[index]<<endl;
		// }
		p[index]+=x;
		// cout<<"new value "<<p[index]<<endl;

		if(start!=end){
			lazy[2*index]+=x;
			lazy[2*index+1]+=x;
		}
		return;
	}else{
		int mid=(start+end)/2;
		update(p,lazy,start,mid,l,r,x,2*index);
		update(p,lazy,mid+1,end,l,r,x,2*index+1);
		p[index]=min(p[2*index],p[2*index+1]);
		return;
	}
}
int query(int * p, int * lazy, int start, int end, int l, int r, int index){
	if(lazy[index]!=0){
			int y=lazy[index];
			lazy[index]=0;

		if(start!=end){
			lazy[2*index]+=y;
			lazy[2*index+1]+=y;
		}
		p[index]+=y;
      }
	if(start>r || end <l){
		return INT_MAX;
	}else if(start >=l && end <=r){
	// if(lazy[index]!=0){
	// 		int y=lazy[index];
	// 		lazy[index]=0;

	// 	if(start!=end){
	// 		lazy[2*index]+=y;
	// 		lazy[2*index+1]+=y;
	// 	}
	// 	p[index]+=y;
 //      }
		return p[index];
     }else{
		int mid=(start+end)/2;
		int a= query(p,lazy,start,mid,l,r,2*index);
		int b= query(p,lazy,mid+1,end,l,r,2*index+1);
		p[index]=min(a,b);
		return p[index];
	}
}
void printTree(int *p ,int * lazy, int start, int end, int index){
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
	int n;
	cin>>n;
	int * arr= new int[n];
	int * p=new int[4*n];
	int * lazy= new int[4*n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	buildSegmentTree(p,arr,0,n-1,1,lazy);
	// cout<<"Tree"<<endl;
	// printTree(p,lazy,0,n-1,1);

	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int ch;
		cin>>ch;
		if(ch==0){
			int l,r,x;
			cin>>l>>r>>x;
			update(p,lazy,0,n-1,l,r,x,1);
		}else{
			int l,r;
			cin>>l>>r;
			cout<<query(p,lazy,0,n-1,l,r,1)<<endl;
		}
		// cout<<"Tree"<<endl;

		// printTree(p,lazy,0,n-1,1);

	}
	delete [] arr;
	delete [] p;
	delete [] lazy;
	return 0;
}