#include <iostream>
using namespace std;
int main(){
	int i=5;
	int b=i;
	//used symbol table.
	cout<<b<<endl;
    
    //Address
	cout<<&i<<endl;

	//Storing address in ptr
	int * ptr1= &i;
	int* ptr2=&i;
	int *ptr3= &i;

	cout<<ptr1<<" "<<ptr2<<" "<<ptr3<<endl;
    
    //Derefrence operator.
	cout<<*ptr1<<endl;
    
    //Null ptr
	int * ptr4=0;
	cout<<ptr4<<endl;

	(*ptr1)++;
	cout<<*ptr1<<" "<<i<<endl;

	*ptr1= *ptr1+5;
	cout<<*ptr1<<" "<<i<<endl;

	*ptr1= 3;
	cout<<ptr1<<" "<<*ptr1<<" "<<i<<endl;

	int c=45;

	*ptr1=c;
	cout<<ptr1<<" "<<*ptr1<<" "<<i<<endl;

//Invalid statement.
	//On left is value i.e int , right is address
	// *ptr1= &c;
	// cout<<ptr1<<" "<<&c<<" "<<*ptr1<<" "<<endl;

	//int *ptr5=0;
	//error , null ptr can't be assigned a value.
	// *ptr5= c;
	// cout<<ptr5<<" "<<*ptr5<<endl;

//same error.Ptr can be declared once only can't reassign it to other address later
	//, *ptr after declaration line means dereference operator not pointer,i.e its value,

	// int *ptr5=0;
	// *ptr5=&c;
	// cout<<ptr5<<" "<<*ptr5<<endl;
    cout<<"break"<<endl;
	int *p=&c;
	int *q=p;
	//can't hv a pointer that store address of other pointer.
	// int *r= &q;

	//Ptr referncing to same var address.
	cout<<&c<<endl;
	cout<<p<<" "<<&p<<" "<<*p<<endl;
	cout<<q<<" "<<&q<<" "<<*q<<endl;
	//cout<<r<<" "<<&r<<" "<<*r<<endl;

	//sizeof pointer is 8 for all data types 
	cout<<sizeof(p)<<endl;
	cout<<&c<<" "<<p<<endl;
	//increment by 1 means increment address to next integer i.e by 4, 8 in double.
	p=p+1;
	cout<<&c<<" "<<p<<endl;
	p=p+1;
	cout<<&c<<" "<<p<<endl;
	p=p+1;
	cout<<&c<<" "<<p<<endl;

	int arr[5];
	for(int i=0;i<5;i++){
		arr[i]=i;
	}
	//Address of arr & arr[0] is same but pointer to array is declared differnetly.
	//Array is continuos chunk of meemory so p+1 takes to next integer which is arr[1]
	//pointer arithmetic work here
	cout<<&arr<<endl;
	cout<<&arr[0]<<endl;


	

}