#include <iostream>
using namespace std;
int** productOfTwoMatrices(int** p, int m, int k, int** q, int x, int n){
	if(k!=x){
		int** r=0;
		return r;
	}
	static int** r= new int*[m];
	for(int i=0;i<m;i++){
		r[i]=new int[n];
	} 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			r[i][j]=0;
			for(int l=0;l<k;l++){
				r[i][j]=r[i][j]+p[i][l]*q[l][j];
			}
		}
	}
	return r;
}
int main(){
	int m,k;
	cin>>m>>k;
	int** p= new int*[m];
	for(int i=0;i<m;i++){
		p[i]=new int[k];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			cin>>p[i][j];
		}
	}
	int x,n;
	cin>>x>>n;
	int** q= new int*[x];
	for(int i=0;i<x;i++){
		q[i]=new int[n];
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<n;j++){
			cin>>q[i][j];
		}
	}
	int ** r= productOfTwoMatrices(p,m,k,q,x,n);
	if(r==0){
		cout<<"Not possible"<<"\n";
	}else{
		for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<r[i][j]<<" ";
		}
		cout<<"\n";
	}
	}
	for (int i=0;i<m;i++){
		delete [] p[i];
	}
	delete [] p;

	for(int i=0;i<x;i++){
		delete [] q[i];
	}
	delete [] q;
	for(int i=0;i<m;i++){
		delete [] r[i];
	}
	delete [] r;

}