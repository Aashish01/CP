//No of solutions of diphantine equation.
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
int modInverse(int a,int m){
	Triplet t= extendedEuclid(a,m);
	int g= t.gcd;
	//inverse exist only if gcd==1
	if(g==1){
		if(t.x<0){ //for -ve values
			return ((t.x)%m +m)%m;
		}else{
			return t.x;
		}
	}
	return 0; //if modInv not exist.
}
long long int noOfSolutionsDiphantineEquation(int a,int b,int d){
Triplet t= extendedEuclid(a,b);
int g= t.gcd;
if(d%g !=0){
	return 0;
}
if(d==0){
	return 1;
}
a=a/g;
b=b/g;
d=d/g;
long long int y1= ((d%a)*modInverse(b,a))%a;
if(d< y1*b){
	return 0;
}
long long int n= ((d/b)-y1)/a;
return n+1;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
	int a,b,d;
	cin>>a>>b>>d;
	long long int ans= noOfSolutionsDiphantineEquation(a,b,d);
	cout<<ans<<"\n";
	}
	
	return 0;
}
