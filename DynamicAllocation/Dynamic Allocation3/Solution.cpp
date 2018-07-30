//const keyword.
#include <iostream>
using namespace std;
int main(){
int y=1;
int * p = &y;

cout<<*p<<" "<<y<<endl;
*p=*p+1;
(*p)++;
cout<<y<<endl;

const int i=2;  //read only
//i++;

int i1=3;  //R & W
 int const & j1= i1;  //R copy of R&W
i1++;
cout<<j1<<" "<<j1<<endl;
//j1++;

int const i2=5;  //R only
//int &j2= i2;  //can't make R& W copy of R only
int const &j2= i2; //R only copy of R only
//i2++
//j2++
cout<<i2<<endl;

//Pointers
int k1=5;  //R & W
int const *p1= &k1;  //R only copy of R&W
k1++;
//*(p1)++;
cout<<*(p1)<<endl;

int const k2=5;
int const *p2=&k2;
//k2++;
//*(p2)++;

//Pointer itself constant , so can't change address stored.
int m=6;
int * const n=&m;  //n is an constant pointer to an integer
m++;
(*n)++;
cout<<*n<<endl;
int z=12;
//n=&z;  //address change not allowed.

int const * const e= &m;
cout<<*e<<endl;

return 0;
}