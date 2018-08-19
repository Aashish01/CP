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
	// if(a<b){
	// 	Not valid ans.
	// }
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
	if(a<m){
		cout<<"Extended extendedEuclid will not work."<<endl;
		return 0;
	}
Triplet t= extendedEuclid(a,m);
if(t.gcd!=1){
	cout<<"Mod Inverse doesnot exists"<<"\n";
	return 0;
}
if(t.gcd==1){
	int c;
	if(t.x<0){
      c= ((t.x)%m + m)%m;
	}else{
		c=t.x;
	}
	cout<<"Multiplicative Modulo Inverse Exists"<<" "<<c<<"\n";
}
return 0;
}