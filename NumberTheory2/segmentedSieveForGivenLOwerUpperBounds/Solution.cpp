#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n){
	if(n==2){
		return true;
	}
	for(int i=2;i<=n/2;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
void printPrimes(long long int l, long long int r){
	bool sieve[100001];
	for(int i=0;i<100001;i++){
		sieve[i]=true;

	}
	int max= (int)pow(100001, 0.5);

	for(int i=2;i<=max;i++){
		if(sieve[i]==true){
			if(isPrime(i)){
			for(int j=i;i*j<100001;j++){
				sieve[i*j]=false;
			  }
		    }
		}
	}
	for(int i=0;i<100001;i++){
		if(sieve[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;

	
	bool * arr= new bool[r-l+1];
	for(int i=0;i<r-l;i++){
		arr[i]=true;
	}
	for(int i=2;i<100001;i++){
		if(sieve[i]){
			if(l%i==0){
				if((l/i)<i){
					for(int j=i;i*j<=r;j++){
						arr[i*j-l]=false;
					}
				}else{
					int x=l/i;
					for(int j=x;i*j<=r;j++){
						arr[i*j-l]=false;
					}
				}
			}else{
				int y=l/i+1;
				if(y<i){
					for(int j=i;i*j<=r;j++){
						arr[i*j-l]=false;
					}
				}else{
					int x=y;
					for(int j=x;i*j<=r;j++){
						arr[i*j-l]=false;
					}
				}
			}
		}
	}
	for(int i=0;i<r-l;i++){
		if(arr[i]){
			cout<<i+l<<" ";
		}
	}
	cout<<"\n";
	delete [] arr;
	return;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long int l,r;
		cin>>l>>r;
		printPrimes(l,r);
	}
	return 0;
}