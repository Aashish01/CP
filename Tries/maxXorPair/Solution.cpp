#include <math.h>
#include <iostream>
using namespace std;
class Trie{
public:
	Trie* left;
	Trie* right; 
};
struct maxXorPair{
	int x;
	int y;
	int Xor;
};
void insert(int* arr, int n,Trie* head){
	
	Trie* temp=head;
	for(int i=0;i<n;i++){
		int j=arr[i];
		for(int k=31;k>=0;k--){
			int currentBit=(1<<k)&j;
			if(currentBit==0){
				if(!head->left){
                   head->left=new Trie();		
               }
				head=head->left;
				//cout<<"done"<<" ";

			}else{
				if(!head->right){
				   
                   head->right=new Trie();
				}
				head=head->right;
				//cout<<"done"<<" ";

			}
		}
		head=temp;
	}
}
maxXorPair maximumPair(int* arr,Trie* head, int n){
	maxXorPair ans;
	Trie* temp=head;
	ans.x=-1;
	ans.y=-1;
	ans.Xor=-1;
	for(int i=0;i<n;i++){
		int j=arr[i];
		int b=0;
		for(int k=31;k>=0;k--){
			int currentBit=(1<<k)&j;
			if(currentBit==0){
				if(!head->right){
					head=head->left;
				}else{
					head=head->right;
					b+=(int)pow(2,k);
				}
			}else{
				if(!head->left){
					head=head->right;
					b+=(int)pow(2,k);
				}else{
					head=head->left;
				}
			}
		}
		//one number is completed. head is pointing to last of trie. so move it to start again.
		head=temp;
		if((j^b)>ans.Xor){
			ans.Xor=(j^b);
			ans.x=j;
			ans.y=b;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int * p=new int[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	Trie* head=new Trie();
	insert(p,n,head);
	maxXorPair p1= maximumPair(p,head,n);
	cout<<p1.x<<" "<<p1.y<<" "<<p1.Xor<<"\n";
	delete [] p;
	return 0;

}