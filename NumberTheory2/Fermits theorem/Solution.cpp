#include <iostream>
using namespace std;
long long int largePower(long long int a, long long int b, int m){
	if(b==0){
		return 1;
	}
	if(b%2==0){
		return largePower((a*a)%m,b/2,m);
	}
	return (a%m)*largePower((a*a)%m,b/2,m)%m;
}
class Triplet{
public:
	int gcd;
	int x;
	int y;
};
Triplet extendedEuclid(int a,int b){
	//This algo doesn't work for a<b. Works for a>b only. As u can't swap a ,b to get ans.
	//Since then (a* ans)%b would not be equal to 1. Only (b*ans)%a is 1 . But that was not the required question.
	//So... 
	// if(a<b){
	// 	//Not valid
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
int a,m;
cin>>a>>m;
Triplet t= extendedEuclid(a,m);
if(t.gcd!=1){
	cout<<"Mod inverse don't exists"<<"\n";
return 0;
}
int c;

if(a<m){
	cout<<"Extended euclid not possible"<<"\n";
}else{
	if(t.x<0){ //for -ve values
			c= ((t.x)%m +m)%m;
		}else{
			c= t.x;
		}
		cout<<"extendedEuclid ans "<<c<<"\n";
}



long long int b= largePower(a,m-2,m);
cout<<"Fermit's ans:"<<" "<<b<<"\n";
return 0;


}
