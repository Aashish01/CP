//Euclid
#include <iostream>
using namespace std;
int gcd(int a,int b){
if(a<b){
	return gcd(b,a);
}
if(b==0){
	return a;
}
return gcd(b,a%b);
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout<<gcd(2,3)<<"\n";
	cout<<gcd(25,5)<<"\n";
	cout<<gcd(5,5)<<"\n";
	return 0;
}