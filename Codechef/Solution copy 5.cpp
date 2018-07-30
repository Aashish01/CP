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

int sumPrimes(int n){
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
	int sum=0;
	for(int i=0;i<n+1;i++){
		if(p[i]==true){
			if(n%i==0)
			sum+=i;
		}
	}
	delete [] p;
	return sum;
}
int main(){
ios_base:: sync_with_stdio(false);
cin.tie(NULL);
int t;
cin>>t;
for(int l=0;l<t;l++){
	int n;
	cin>>n;
	int *p= new int[n];
	int *s= new int[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
		int x=p[i];
		s[i]=sumPrimes(x);
	}
	long long int countPairs=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				//nothing
			}else{
				if(p[j]%p[i]==0 && s[j]%s[i]==0){
				countPairs++;
			}
			}
			
		}
	}
	cout<<countPairs<<"\n";
	delete [] p;
	delete [] s;
}
return 0;
}
