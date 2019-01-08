#include <iostream>
using namespace std;
int main(){
	for(int i=0;i<8;i++){
	   int mask= (1<<i);
	   cout<<mask<<endl;
	}
	int mask= 13,i=2;
	//here though mask is declared 13, things will be happening in binary.
	//set ith bit :
	mask= mask | (1<<i);
	cout<<mask<<endl;
	
	//unset ith bit 

	mask= mask & (~(1<<i));
	cout<<mask<<endl;

	//check if ith bit of mask is set
	if((mask & (1<<i))==0){
		cout<<"Unset"<<endl;
	}else{
		cout<<"Set"<<endl;
	}

	//count no of set bits.
	int k=0;
	int temp=mask;
	while(temp>0){
		int lastDigit= temp&1;
		//this gives last digit of mask. temp&1= 1 if last digit is 1, else 0;
        k+=lastDigit;
        temp=temp/2;
        //since /2 trims the last digit in binary .
	}
	cout<<"No of set bits "<<k<<endl;


}