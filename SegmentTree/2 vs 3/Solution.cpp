#include <iostream>
#include <string>
using namespace std;
struct Node{
	char type;
	int digit;
	bool hold;
};
void buildSegmentTree(Node * p, int * arr, int start, int end, int index){
	if(start==end){
		if(arr[start]==1){
			p[index].type='b';
			p[index].digit=1;
			p[index].hold=false;
		}else{
			p[index].type='a';
			p[index].digit=1;
			p[index].hold=false;
		}
		return;
	}
	int mid=(start+end)/2;
	buildSegmentTree(p,arr,start,mid,2*index);
	buildSegmentTree(p,arr,mid+1,end,2*index+1);
	p[index].digit=p[2*index].digit+p[2*index+1].digit;
	p[index].hold=false;
    if(p[2*index].type=='a' && p[2*index+1].type =='a'){
       p[index].type='a';
    }
    if(p[2*index].type=='a' && p[2*index+1].type =='b'){
    	p[index].type='b';
    }
    if(p[2*index].type=='a' && p[2*index+1].type =='c'){
    	p[index].type='c';
    }
    if(p[2*index].type=='b' && p[2*index+1].type =='a'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='b';
    	}else{
           p[index].type='c';
    	}
    }
    if(p[2*index].type=='b' && p[2*index+1].type =='b'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='c';
    	}else{
           p[index].type='a';
    	}
    }
    if(p[2*index].type=='b' && p[2*index+1].type =='c'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='a';
    	}else{
           p[index].type='b';
    	}
    }
    if(p[2*index].type=='c' && p[2*index+1].type =='a'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='c';
    	}else{
           p[index].type='b';
    	}
    }
    if(p[2*index].type=='c' && p[2*index+1].type =='b'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='a';
    	}else{
           p[index].type='c';
    	}
    }
    if(p[2*index].type=='c' && p[2*index+1].type =='c'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='b';
    	}else{
           p[index].type='a';
    	}
    }
    return;
}
void update(Node * p, int start, int end, int index, int givenIndex){
	if(start==end){
		if(p[index].type=='a'){
			p[index].type='b';
		}
		return;
	}
	int mid=(start+end)/2;
	if(givenIndex>mid){
		update(p,mid+1,end,2*index+1,givenIndex);
	}else{
		update(p,start,mid,2*index,givenIndex);
	}
	p[index].digit=p[2*index].digit+p[2*index+1].digit;
	p[index].hold=false;
    if(p[2*index].type=='a' && p[2*index+1].type =='a'){
       p[index].type='a';
    }
    if(p[2*index].type=='a' && p[2*index+1].type =='b'){
    	p[index].type='b';
    }
    if(p[2*index].type=='a' && p[2*index+1].type =='c'){
    	p[index].type='c';
    }
    if(p[2*index].type=='b' && p[2*index+1].type =='a'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='b';
    	}else{
           p[index].type='c';
    	}
    }
    if(p[2*index].type=='b' && p[2*index+1].type =='b'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='c';
    	}else{
           p[index].type='a';
    	}
    }
    if(p[2*index].type=='b' && p[2*index+1].type =='c'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='a';
    	}else{
           p[index].type='b';
    	}
    }
    if(p[2*index].type=='c' && p[2*index+1].type =='a'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='c';
    	}else{
           p[index].type='b';
    	}
    }
    if(p[2*index].type=='c' && p[2*index+1].type =='b'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='a';
    	}else{
           p[index].type='c';
    	}
    }
    if(p[2*index].type=='c' && p[2*index+1].type =='c'){
    	if(p[2*index+1].digit%2==0){
           p[index].type='b';
    	}else{
           p[index].type='a';
    	}
    }
    return;
}
Node query(Node * p, int l, int r, int start, int end, int index){
	if(start>r || end <l){
		Node n1;
		n1.hold=true;
		return n1;
	}else if(start>=l && end <=r ){
         return p[index];
	}else{
		Node n3;
		int mid=(start+end)/2;
		Node n1= query(p,l,r,start,mid,2*index);
		Node n2= query(p,l,r,mid+1,end,2*index+1);
		if(n1.hold==true){
			n3=n2;
			return n3;
		}else if(n2.hold ==true){
			n3=n1;
			return n3;
		}else{
			n3.digit= n1.digit+n2.digit;
			n3.hold=false;
			if(n1.type=='a' && n2.type =='a'){
              n3.type='a';
            }
    if(n1.type=='a' && n2.type =='b'){
    	n3.type='b';
    }
    if(n1.type=='a' && n2.type =='c'){
    	n3.type='c';
    }
    if(n1.type=='b' && n2.type =='a'){
    	if(n2.digit%2==0){
           n3.type='b';
    	}else{
           n3.type='c';
    	}
    }
    if(n1.type=='b' && n2.type =='b'){
    	if(n2.digit%2==0){
           n3.type='c';
    	}else{
           n3.type='a';
    	}
    }
    if(n1.type=='b' && n2.type =='c'){
    	if(n2.digit%2==0){
           n3.type='a';
    	}else{
           n3.type='b';
    	}
    }
    if(n1.type=='c' && n2.type =='a'){
    	if(n2.digit%2==0){
           n3.type='c';
    	}else{
           n3.type='b';
    	}
    }
    if(n1.type=='c' && n2.type =='b'){
    	if(n2.digit%2==0){
           n3.type='a';
    	}else{
           n3.type='c';
    	}
    }
    if(n1.type=='c' && n2.type =='c'){
    	if(n2.digit%2==0){
           n3.type='b';
    	}else{
           n3.type='a';
    	}
    }
      return n3;
		}
	}

}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
  string str;
  cin>>str;
	int * arr= new int[n];
	Node * p= new Node[4*n];
	for(int i=0;i<n;i++){
		char ini=str.at(i);
    if(ini=='1'){
       arr[i]=1;
    }else{
      arr[i]=0;
    }
	}
	buildSegmentTree(p,arr,0,n-1,1);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int ch;
		cin>>ch;
		if(ch==0){
			int l,r;
			cin>>l>>r;
			Node n1= query(p,l,r,0,n-1,1);
			char ty=n1.type;
			if(ty=='a'){
				cout<<0<<endl;
			}else if(ty=='b'){
                cout<<1<<endl;
			}else{
				cout<<2<<endl;
			}
		}else{
			int givenIndex;
			cin>>givenIndex;
			update(p,0,n-1,1,givenIndex);
		}
	}
	delete [] p;
	delete [] arr;
	return 0;
}
