#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n){
	if(n==1){
		return false;
	}
	for(int i=2;i<=n-1;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
long long int occurence(int n,int m){
	int k=0;
	while(pow(m,k)<=n){
		k++;
	}
	k--;
	long long int x=0;
	for(int i=1;i<=k;i++){
		int y= (int)pow(m,i);
		x=x+ (n/y);
	}
	return x;
}
long long int noOfDivisors(int n){
	bool * p= new bool[n+1];
	p[0]=false;
	p[1]=false;
	for(int i=2;i<n+1;i++){
		p[i]=true;
	}
	int root= (int)pow(n,0.5);
	for(int i=2;i<=root;i++){
		if(isPrime(i)){
			for(int j=i;i*j<n+1;j++){
				p[i*j]=false;
			}
		}
	}
	long long int divisors=1;
	int m=(int) pow(10,9)+7;
	for(int i=0;i<n+1;i++){
		if(p[i]==true){
			long long int x= occurence(n,i)+1;
			divisors= ((divisors%m)*(x%m))%m;
		}
	}
	delete [] p;
	return divisors;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int n;
		cin>>n;
		cout<<noOfDivisors(n)<<"\n";
	}
	return 0;
}
