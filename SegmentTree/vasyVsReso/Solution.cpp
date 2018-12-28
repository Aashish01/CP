#include <iostream>
using namespace std;
struct Node{
int a,b, ansIndex;
bool hold;
};
void buildSegmentTree(Node * p, int* arr1, int* arr2, int start, int end, int index){
	if(start==end){
		p[index].a=arr1[start];
		p[index].b= arr2[start];
		p[index].ansIndex= start+1;
		p[index].hold=false;
		return;
	}
	int mid= (start+end)/2;
	buildSegmentTree(p,arr1,arr2,start,mid,2*index);
	buildSegmentTree(p,arr1,arr2,mid+1,end,2*index+1);
	p[index].hold=false;
	if(p[2*index].a > p[2*index+1].a){
		p[index].a= p[2*index].a;
		p[index].b= p[2*index].b;
		p[index].ansIndex=p[2*index].ansIndex;
	}else if(p[2*index].a < p[2*index+1].a){
		p[index].a= p[2*index+1].a;
		p[index].b= p[2*index+1].b;
		p[index].ansIndex=p[2*index+1].ansIndex;
	}else{
		if(p[2*index].b < p[2*index+1].b){
		p[index].a= p[2*index].a;
		p[index].b= p[2*index].b;
		p[index].ansIndex=p[2*index].ansIndex;
	}else if(p[2*index].b > p[2*index+1].b){
		p[index].a= p[2*index+1].a;
		p[index].b= p[2*index+1].b;
		p[index].ansIndex=p[2*index+1].ansIndex;
	}else{
		if(p[2*index].ansIndex<p[2*index+1].ansIndex){
			p[index].a= p[2*index].a;
		p[index].b= p[2*index].b;
		p[index].ansIndex=p[2*index].ansIndex;
	}else{
		p[index].a= p[2*index+1].a;
		p[index].b= p[2*index+1].b;
		p[index].ansIndex=p[2*index+1].ansIndex;
	}
	}
	}
	return;
}
Node query(Node * p, int l, int r, int start, int end, int index){
	if(start>r || end <l){
		Node n1;
		n1.hold=true;
		return n1;
	}else if(start >=l && end <=r){
		return p[index];
	}else{
		int mid=(start+end)/2;
		Node n1= query(p,l,r,start,mid,2*index);
		Node n2= query(p,l,r,mid+1,end,2*index+1);
		if(n1.hold == true){
			Node n3;
			n3.hold=false;
			n3.a= n2.a;
			n3.b= n2.b;
			n3.ansIndex= n2.ansIndex;
			return n3;
		}else if(n2.hold == true){
			Node n3;
			n3.hold=false;

			n3.a= n1.a;
			n3.b= n1.b;
			n3.ansIndex= n1.ansIndex;
			return n3;
		}else{
			Node n3;
			n3.hold=false;

			if(n1.a > n2.a){
				n3.a= n1.a;
			n3.b= n1.b;
			n3.ansIndex= n1.ansIndex;
			return n3;
		}else if(n1.a < n2.a){
			Node n3;
			n3.hold=false;

			n3.a= n2.a;
			n3.b= n2.b;
			n3.ansIndex= n2.ansIndex;
			return n3;
		}else{
			if(n1.b < n2.b){
				Node n3;
				n3.hold=false;

				n3.a= n1.a;
			n3.b= n1.b;
			n3.ansIndex= n1.ansIndex;
			return n3;
		}else if(n1.b > n2.b){
			Node n3;
			n3.hold=false;

			n3.a= n2.a;
			n3.b= n2.b;
			n3.ansIndex= n2.ansIndex;
			return n3;
		}else{
			if(n1.ansIndex > n2.ansIndex){
				Node n3;
				n3.hold=false;

			n3.a= n2.a;
			n3.b= n2.b;
			n3.ansIndex= n2.ansIndex;
			return n3;
			}else{
				Node n3;
				n3.hold=false;

				n3.a= n1.a;
			n3.b= n1.b;
			n3.ansIndex= n1.ansIndex;
			return n3;
			}
			
		}
		}
		}
	}

}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int * arr1= new int[n];
	int * arr2= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}
	Node * p= new Node[4*n];
	buildSegmentTree(p,arr1,arr2,0,n-1,1);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int l, r;
		cin>>l>>r;
        l--;
		r--;
		Node n1= query(p,l,r,0,n-1,1);
		cout<<n1.ansIndex<<endl;

	}
	delete [] arr1;
	delete [] arr2;
	delete [] p;

	return 0;
}