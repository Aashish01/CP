#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n;
cin>>n;
int * x= new int[n];
int * y= new int[n];
for(int i=0;i<n;i++){
	cin>>x[i];
}
for(int i=0;i<n;i++){
	cin>>y[i];
}
int * vx= new int[n-1];
int * vy= new int[n-1];
int j=0;
for(int i=1;i<n;i++){
	vx[j]=x[i]-x[0];
	vy[j]=y[i]-y[0];
	j++;
}
double area=0;
for(int i=0;i<n-2;i++){
	area+= (1.0/2)*((vx[i]*vy[i+1])-(vy[i]*vx[i+1]));
}
if(area<0){
	area*=-1;
}
cout<<area<<endl;
delete [] x;
delete [] vx;
delete [] y;
delete [] vy;
return 0;
}

