#include <iostream>
using namespace std;
//Make on heap for returning also, as can't make stack data static.
//return arr, not pointer to arr as arr itself is pointer
//Array made inside fns ,Delete outside after call,when work done
//static doesn't means scope will change ,scope will be restricted to blocks only, so can make diff var of sma ename in diff fns
//static just means all memory will be freed after run of program, not before by line scope.
//don't delete arr2 & p2 in same loop as due to static p2 might be used by arr2.
int* same1D(int* p,int size){
  static int* arr= new int[size];
  for(int i=0;i<size;i++){
  	arr[i]=p[i];
  }
  return arr;   //array itself is pointer
}
int** same2D(int** p,int row, int col){
	static int** arr= new int*[row];
	for(int i=0;i<row;i++){
		arr[i]= new int[col];
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j]=p[i][j];
		}
	}
	return arr; //arr itself is double pointer . we would hv made pointer to arr, if it was a array on stack and a var, not a pointer
}
int main(){
	//1D array.
	int x;
	cin>>x;
	int* p1=new int[x];
	for(int i=0;i<x;i++){
		cin>>p1[i];
	}
	int *arr1= same1D(p1, x);
	for(int i=0;i<x;i++ ){
		cout<<arr1[i]<<" ";
	}
	cout<<endl;
	delete [] p1;
	delete [] arr1;

	//2D array.
	int m,n;
	cin>>m>>n;
	int* * p2= new int*[m];
	for(int i=0;i<m;i++){
		p2[i]=new int[n];
	}
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		cin>>p2[i][j];
    	}
    }
    int* *arr2=  same2D(p2,m,n);
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		cout<<arr2[i][j]<<" ";
    	}
    	cout<<endl;
    }
    //aarr2 represent array of fn.
    for(int i=0;i<m;i++){
    	delete [] arr2[m];
    }
    delete [] arr2;
    
    for(int i=0;i<m;i++){
    	delete [] p2[m];
    }
    delete [] p2;

return 0;
}