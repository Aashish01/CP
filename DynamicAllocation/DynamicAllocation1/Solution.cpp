#include <iostream>
using namespace std;
//Bad practice: To return pointer or refernce n c++, as after fn call mmemory goes out of scope & get freed & we are trying to hold that address still.
int* in(int x){
	int * p= &x;
	return p;
}
int& o(int x){
	int& j=x;  //j is reference var to x
	return j;  // we are returning j but by refrence so int& in return type.
}
//end

//Array print
void printArr(int* p,int size){
	for(int i=0;i<size;i++){
      cout<<p[i]<<" ";
	}
	cout<<endl;
}

void printArray2D(int** p,int row, int col){
for(int i=0;i<row;i++){
	for(int j=0;j<col;j++){
		cout<<p[i][j]<<" ";
	}
	cout<<endl;
}
}

void increment(int& p){  //receive a reference
	p++;
}
int main(){
//Typecasting of pointers
	int i1= 97;
	int * p1= &i1;
	char * p2= (char*)p1;  //explicit  typecast is req.
	cout<<*p2<<endl;  //print 1 byte i.e first byte ony out of 4
	cout<<p2<<endl;  //print each byte of array until null found, instead of printing address

	char ch1= 'a';
	char *p3= &ch1;
	int * p4= (int*)p3;
	cout<<*p4<<endl; // print 4 byte , so print garbage after first byte
 
 //Pass by refrence.
	int i2= 25;
	int & j= i2;
	cout<<j<<endl;
	j++;
	cout<<i2<<" "<<j<<endl;

	j= 12;
	cout<<j<<" "<<i2<<endl;

    increment(i2);  //way to send
    cout<<j<<" "<<i2<<endl;
    

    int x=5;
    int *p= in(x);
    int& k= o(x);
    cout<<*p<<" "<<k<<endl;// value of pointer using dereference operator, reference var by directly its name.

    //Dynamic allocation
    int* p5=new int;
    *p5= 11;
    cout<<*p5<<endl;
    delete p5;
    
    //p5 itself isn't deleted & can be reused
    int w=13;
    p5= &w;
    cout<<*p5<<endl;

    //Array.
    int* p6=new int[5];   
    for(int i=0;i<5;i++){
    	p6[i]=i;
    	cout<<p6[i]<<" ";
    } 
    cout<<endl;
    printArr(p6,5);
    delete [] p6;

    //2d array.
    int m,n;
    cin>>m>>n;
    int* * p7 =new int*[m];  //pointer array of size row to store address of m arrays
    for(int i=0;i<m;i++){
     p7[i] =new int[n];  //m array of size n each ,whose address is storedin pointer array
    }

    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		cin>>p7[i][j];
    	}
    }
    printArray2D(p7,m,n);

    for(int i=0;i<m;i++){
    	delete [] p7[i];
    }
    delete [] p7;




}