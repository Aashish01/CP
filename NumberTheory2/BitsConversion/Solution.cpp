#include <iostream>
#include <string>
using namespace std;
string decToBinary(int n) 
{ if(n==0){
	return "0";
}
	string str="";
    // Size of an integer is assumed to be 32 bits 
    for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            str+="1";
        else
            str+="0";
    } 
    int j=0;
    while(str.at(j)!='1'){
    	j++;
    }
    for(int i=0;i<j;i++){
    	
    		str=str.substr(1);
    	
    }
    return str;
} 
int binaryToDecimal(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
      
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
      
    int len = num.length(); 
    for (int i=len-1;i>=0;i--) 
    { 
        if (num[i] == '1')         
            dec_value += base; 
        base = base * 2; 
    } 
      
    return dec_value; 
}
int main(){
	int n;
	cin>>n;
	string str= decToBinary(n);
	cout<<str<<endl;
	int dec= binaryToDecimal(str);
	cout<<dec<<endl;
}