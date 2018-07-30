#include <iostream>
using namespace std;
int main(){
	//byte a=3;
	//cout<<a;
	char ch='a';
	cout<<ch<<endl;
	short s=2;
	cout<<s<<endl;
	int i=3;
	cout<<i<<endl;
	long l= 245;
	cout<<l<<endl;
	float f=2.3;
	cout<<f<<endl;
	double d=3.2;
	cout<<d<<endl;

	cout<<sizeof(ch)<<" "<<sizeof(s)<<" "<<sizeof(i)<<" "<<sizeof(l)<<" "<<sizeof(f)<<" "<<sizeof(d)<<endl;
    
    bool b= true;
    cout<<b<<endl;
    short int si= 3;
    cout<<si<<endl;
    long long int lli =234;
    cout<<lli<<endl;
    long double ld= 34.56;
    cout<<ld<<endl;

    cout<<sizeof(b)<<" "<<sizeof(si)<<" "<<sizeof(lli)<<" "<<sizeof(ld)<<endl;

    //Garbage Initialisation: Can or can't be 0 initialised.
    int j,k;
    cout<<j<<" "<<k<<" "<<(j+k)<<endl;
    
    //Typecasting
    int i1=4;
    double d1= 997.34;
    float f1= 23.9;
    char ch1='e';
    i1= d1;
    cout<<i1<<endl;
    i1= f1;
    cout<<i1<<endl;
    i1= ch1;
    cout<<i1<<endl;

    //Boolean funda: declaration & conditional :put true, prints 0 & 1.
    bool hold1= true;
    bool hold2= false;
    if(hold1==true && hold2==false){
    	cout<<hold1<<" "<<hold2<<endl;
    }

    //Ascii values
    int ai= 'a';
    cout<<ai<<endl;
    cout<<('c'+3)<<endl;
    char ch2= 'd';
    ch2=ch2+2;
    cout<<ch2<<endl;

    //Signed :reserve 1 sign bit for +ve & -ve , by default sign
    //Unsigned: No sign bit reserve means take +ve values only & larger storage
    signed int w= 5;
    unsigned int y= 9;
    cout<<w<<" "<<y<<endl;
    cout<<sizeof(w)<<" "<<sizeof(y)<<endl;



}