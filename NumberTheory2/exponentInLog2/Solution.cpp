#include <iostream>
using namespace std;
long long int power(int a,int b){
	if(b==0){
		return 1;
	}
	if(b%2==0){
		return power(a*a, b/2);
	}
	return a*power(a*a,b/2);

}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	cout<<power(a,b)<<"\n";
	return 0;
}