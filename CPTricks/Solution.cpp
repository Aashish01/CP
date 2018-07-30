#include <iostream>

using namespace std;
int main(){
	// To find if even or odd.
	int a;
	cin>>a;
	bool ans= (a&1)==0 ? true : false ;
	cout<<ans<<endl;
	
	//quick swap.

	int b=5;
	int c=6;
	cout<<b<<" "<<c<<endl;
	b^=c;   //b= b^c;  xor
	c^=b;
	b^=c;
	cout<<b<<" "<<c<<endl;

	}