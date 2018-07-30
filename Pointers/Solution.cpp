#include<iostream>
using namespace std;
void fnArray(int a[]){
cout<<sizeof(a)<<endl;
return ;
}
int* manipulatedArray(int* p,int size){
	int manipulatedArr[size];
	cout<<size<<endl;
	for(int i=0;i<size;i++){
		manipulatedArr[i]=p[i]+3;
		cout<<manipulatedArr[i]<<" ";
	}
	cout<<endl;
		int *p1= &manipulatedArr[0];
	return p1;
}
void print(int* p){
	cout<<*p<<endl;
}
void incrementPointer(int* p){
	p=p+1;
}
void incrementValue(int* p){
	(*p)++;
}
void increment1(int** p){
	//=address stored in p= &p1
	p++;
}
void increment2(int** p){
	//=addres stored in p1
	//derefernce p. =&i
	(*p)++;
}
void increment3(int** p){
	//dreference *p = i
	(**p)++;
}
int main(){
	//Symbol table
	int i=5;
	int b=i;
	cout<<b<<endl;

	cout<<&i<<endl;

	int * p= &i;
	cout<<p<<" "<<sizeof(p)<<" "<<*p<<" "<<&p<<endl;

	int d=7;
	*p=d;
	cout<<*p<<endl;
	(*p)++;
	cout<<*p<<endl;

	//Null pointer
	int * np=0;
	cout<<np<<endl;

	//2 pointer to same var
	int c=5;
	int * q1= &c;
	int *q2= q1;
	cout<<*q1<<" "<<*q2<<endl;
	q2= &i;
	cout<<*q2<<endl;

	//Pointer arithmetic
	int a= 19;
	int *ap= &a;
	cout<<*ap<<" "<<ap<<endl;
	ap=ap+3;
	cout<<ap<<endl; //a+3*4 i.e3* size of 1 int to reach next meaningful integer address.

    //Pointers and arrays.
    int arr[10];
    //Address of arr= address of arr[0]
    cout<<arr<<endl;
    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;

    cout<<*arr<<" "<<arr[0]<<endl;
    arr[3]=5;
    //arr[3]
    cout<<*(arr+3)<<endl;


    //Making pointer to an array.
    int myArr[10];
    int *myPtr= &myArr[0];
    //Difference b/w arr & pointer to arr
    //1.
    cout<<sizeof(myArr)<<" "<<sizeof(myPtr)<<endl;
    //2.
    cout<<myArr<<" "<<&myArr<<endl;
    cout<<myPtr<<" "<<&myPtr<<endl;
    //3.
    //accessing not reassigning
    cout<<*(arr+3)<<endl;
    //reassigning
    //since there is 8 byte space made whenever pointer is made, can change value stored in this space.
    myPtr=myPtr+2;
    cout<<myPtr<<endl;
    //Not allowed in symbol table ,as no extra byte 
    //space is there like pointer to store addresses and overwite later
    // myArr=myArr+2;
    // cout<<myArr<<endl;

    cout<<endl;
    //Pointer to array
    int arr1[5];
    int *p1= &arr1[0];
    //arr[0]
    cout<<*p<<endl;
    //equivalent
    cout<<*(p+5)<<" "<<p[5]<<endl; //for now some garbage value: 0 or non 0 will be printed.

    //Character array
    int e[]={1,2,3,4};
    cout<<e<<endl; //print address.
    char ch[]="Hello";
    cout<<ch<<endl;// Prints value instead of address.

    char ch1[]="JavaDoc";
    char * cp= & ch1[0];
    //dereference works fine as usual
    cout<<*cp<<" "<<*(cp+1)<<" "<<cp[2]<<" "<<cp[3]<<endl;
    //But if we want to print address ,it print value, just like above case, with char array
    //it prints starting from where pointer is refering to till encounter null '\0' in string, & if not found print garbage.
    cout<<cp<<endl;
    cout<<cp+2<<endl;
    //this is accessing, not assigning, since array is continous cp+2 will be pointing to element 3 of array

    //
    char ch3='a';
    char * ptr1= &ch3;
    cout<<*ptr1<<endl; //dereference work fine as above
    cout<<ptr1<<endl; //same fundaa as above, print garbage since '\0' not found

   
    //Pointer in functions.
    int f=12;
    int *pf= &f;
    //Address is passed.
    print(pf);
    print(&f);
    
    //no change since , since local copy was passed.
    cout<<pf<<endl;
    incrementPointer(pf);
    cout<<pf<<endl;

    //change occur ,since refering to same
    cout<<*pf<<" "<<f<<endl;
    incrementValue(pf);
    cout<<*pf<<" "<<f<<endl;

    //Double pointers
    cout<<"Double pointer"<<endl;
        int g=5;
    int *pg= &g;
    int* *dp = & pg;

    cout<<dp<<" "<<*dp<<" "<<**dp<<endl;


    increment1(dp);
    cout<<dp<<" "<<*dp<<" "<<**dp<<endl;

    increment2(dp);
    cout<<dp<<" "<<*dp<<" "<<**dp<<endl;

    *dp= &g;
    increment3(dp);
    cout<<dp<<" "<<*dp<<" "<<**dp<<endl;




    //pointer to function with array as parameter. 
    //not taking size of array as input from user bcoz of cin fundaa
    int b1[10];
    for(int i=0;i<10;i++){
    	cin>>b1[i];
    }
    //will print size of pointer i.e 8 instead of 10*4=40, since array is never passes in cpp, only pointer is passed.
    fnArray(b1);

    //so need to send pointer and size of array by us in fn, as can't be calculated there
    int *pTob1= &b1[0];
    
    int size= sizeof(b1)/sizeof(b1[0]);
    //will not print properly ,since we address we asked for is no more in memory after fn complete, goes out of scope.//Dynamic allocation fundaa

    // int *collect= manipulatedArray(pTob1, size);
    // for(int i=0;i<size;i++){
    // 	cout<<collect[i]<<" ";
    // }
    // cout<<endl;
    manipulatedArray(pTob1,size);

    









	return 0;
}