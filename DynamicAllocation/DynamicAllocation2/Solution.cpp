#include <iostream>
using namespace std;
//Macro
#define MULTIPLY(a,b) a*b
#define PI 3.
//global var
int a=6;

//inline fn
inline int max(int a,int b){
	return a>b?a:b;
}
//default arguements
int specialSum(int x1,int x2,int x3=-1,int x4=-2,int x5=0){
return x1+x2+x3+x4+x5;
}

int fn(){
	int a=4;  //can make in scpe block ,same var with name as global var, no errors.
	return a;
}
int main(){
	cout<<PI*2*2<<endl;
	cout<<MULTIPLY(2+3,3+4)<<endl;
	cout<<a<<endl;
	int i= fn();
	cout<<i<<endl;
    
    //Tertiary operator.
int x,y;
cin>>x>>y;
int i1= x>y?x:y;  //return any one  of x & y,based on condition which is stored in int i.
bool hold= x>y?true:false;
cout<<i1<<" "<<hold<<endl;

int j=max(x,y);
cout<<j<<endl;
cout<<specialSum(1,2,3,4,5)<<endl; //15
cout<<specialSum(1,2,3,4)<<endl;   //10
cout<<specialSum(1,2,3)<<endl; //4
cout<<specialSum(1,2)<<endl;  //0

return 0;
}