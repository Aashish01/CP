//Sieve Of eratosthenes
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

int countPrimes(int n){
	bool *p= new bool[n+1];
	p[0]=false;
	p[1]=false;
	for(int i=2;i<n+1;i++){
		p[i]=true;
	}
	int root= (int) pow(n,0.5);
	for(int i=2;i<=root;i++){
		if(isPrime(i)){
			for(int j=i;i*j<n+1;j++){
				p[i*j]=false;
			}
		}
	}
	int count=0;
	for(int i=0;i<n+1;i++){
		if(p[i]==true){
			count++;
		}
	}
	delete [] p;
	return count;
}
int main(){
ios_base:: sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
cout<<countPrimes(n)<<"\n";
return 0;
}
