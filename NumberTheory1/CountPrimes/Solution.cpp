#include <iostream>
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
int main(){
ios_base:: sync_with_stdio(false);
cin.tie(NULL);
int count=0;
int n;
cin>>n;
for(int i=1;i<=n;i++){
	if(isPrime(i)){
		count++;
	}
}
cout<<count<<"\n";
return 0;
}