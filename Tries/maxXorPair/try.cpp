#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int * p= new int[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	int Xor=-1;
	int x=0,y=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int z=p[i]^p[j];
			if(z>Xor){
				x=p[i];
				y=p[j];
				Xor=z;
			}
		}
	}
	cout<<x<<" "<<y<<" "<<Xor<<endl;
	return 0;
}