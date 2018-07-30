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
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	Triplet t= extendedEuclid(a,b);
	cout<<t.gcd<<" "<<t.x<<" "<<t.y<<"\n";
	return 0;
}