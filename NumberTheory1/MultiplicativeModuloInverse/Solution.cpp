//Multiplicative modulo inverse.
#include <iostream>
using namespace std;
class Triplet{
public:
	int gcd;
	int x;
	int y;
};
Triplet extendedEuclid(int a,int b){
	if(a<b){
		Triplet t= extendedEuclid(b,a);
		return t;
	}
	if(b==0){
		Triplet t;
		t.gcd=a;
		t.x=1;
		t.y=0;
		return t;
	}
	Triplet t= extendedEuclid(b, a%b);
	Triplet current;
	current.gcd= t.gcd;
	current.y= t.x- ((a/b)*(t.y));
	current.x= t.y;
	return current;

}
int main(){
	int a, m;
	cin>>a>>m;
Triplet t= extendedEuclid(a,m);
if(t.gcd==1){
	cout<<"Multiplicative Modulo Inverse Exists"<<" "<<t.x<<"\n";
}else{
	cout<<"Don't exists"<<"\n";
}
return 0;
}