#include <iostream>
using namespace std;
int eulerTotient(int n){
	int * p= new int[n+1];
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	for(int i=2;i<n+1;i++){
		if(p[i]==i){
			

		for(int j=2;j*i<n+1;j++){
			double d= p[i*j]*(1-(1.0/p[i]));
			p[i*j]=d;
		}
		p[i]=i-1;

	}
	}
	int ans=p[n];
	delete [] p;
	return ans;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	cout<<eulerTotient(n)<<"\n";
	return 0;
}