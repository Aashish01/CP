#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
void buildTree(int * arr, pair<int,int> * p, int start, int end, int index){
	if(start==end){
		p[index].first=arr[start];
		return;
	}
	int mid=(start+end)/2;
	buildTree(arr,p,start,mid,2*index);
	buildTree(arr,p,mid+1,end,2*index+1);
	p[index].first= max(p[2*index].first ,p[2*index+1].first);
	if(p[index].first==p[2*index].first){
      p[index].second=max(p[2*index+1].first,p[2*index].second);
	}else{
		p[index].second=max(p[2*index].first,p[2*index+1].second);
		
	}

	return;
}
pair<int,int> query(pair<int,int> * p, int start, int end, int l, int r, int index){
	if(start>=l && end<=r){
		pair<int,int> q(p[index].first, p[index].second);
		return q;
	}
	if(start>r || end <l){
		pair<int,int> q(-1,-1);
		return q;
	}
	int mid = (start+end)/2;
	pair<int,int> q1= query(p,start,mid,l,r,2*index);
	pair<int,int> q2= query(p,mid+1,end,l,r,2*index+1);

	int fMax= max(q1.first,q2.first);
	int sMax;
	if(fMax==q1.first){
		sMax=max(q2.first,q1.second);
	}else{
		sMax= max(q1.first,q2.second);
	}
	pair<int,int> q(fMax,sMax);
	return q;
}
void update(pair<int,int> * p, int start, int end,int index,int gAindex,int value){
	if(start==end){
		p[index].first=value;
		return;
	}
	int mid=(start+end)/2;
	if(gAindex<=mid){
		update(p,start,mid,2*index,gAindex,value);
	}
	if(gAindex>mid){
		update(p,mid+1,end,2*index+1,gAindex,value);
	}

	p[index].first= max(p[2*index].first ,p[2*index+1].first);
	if(p[index].first==p[2*index].first){
      p[index].second=max(p[2*index+1].first,p[2*index].second);
	}else{
		p[index].second=max(p[2*index].first,p[2*index+1].second);

	}
	return;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int * arr= new int[n];
	pair<int,int> * p= new pair<int,int>[4*n];
	for(int i=0;i<4*n;i++){
		p[i]=make_pair(-1,-1);
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	buildTree(arr,p,0,n-1,1);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
       char ch;
       cin>>ch;
       if(ch=='U'){
       	int gAindex,value;
       	cin>>gAindex>>value;
       	gAindex--;
       	update(p,0,n-1,1,gAindex,value);
       }
       if(ch=='Q'){
       	int l,r;
       	cin>>l>>r;
       	l--;
       	r--;
       	pair<int,int> q1= query(p,0,n-1,l,r,1);
       	cout<<q1.first+q1.second<<"\n";
       }
	}
	delete [] p;
	delete [] arr;
	return 0;
}
