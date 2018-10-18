//Segemneted sieve with upper bounds
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
	bool * arr= new bool[r-l+1];
	for(int i=0;i<(r-l+1);i++){
		arr[i]=true;
	}
	for(int i=2;i<100001;i++){
		int maxR= (int) pow(r,0.5);
		if(i>maxR){
			break;
		}
		if(sieve[i]){
			int no=i;
			if(l<=no){
				for(int j=i;(i*j)<=r;j++){
					arr[(i*j)-l]=false;
				}
			}else{
				int nextBase;
				if(l%no==0){
					nextBase=l/no;
				}else{
					nextBase=(l/no) +1;
				}
				if(nextBase<=no){
					for(int j=i;i*j<=r;j++){
						arr[(i*j)-l]=false;
					}
				}else{
					for(int j= nextBase;i*j<=r;j++){
						arr[(i*j)-l]=false;
					}
				}
			}
		}
	}
	for(int i=0;i<(r-l+1);i++){
		if(arr[i]){
			cout<<l+i<<" ";
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