#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int cost(int** arr, int* p, int i, int j ){
    if(arr[i][j]!=-1){
    	return arr[i][j];
    }
    if(i==j){
    	arr[i][j]=0;
    	return 0;
    }
    int min= INT_MAX;
    for(int k=i;k<j;k++){
    	int x= cost(arr,p,i,k)+ cost(arr,p,k+1,j);
    	int c1=0,c2=0;
    	for(int l=i;l<=k;l++){
    		c1=(c1+p[l])%100;
    	}
    	for(int l=k+1;l<=j;l++){
    		c2=(c2+p[l])%100;
    	}
    	x+= c1*c2;
    	if(x<min){
    		min=x;
    	}
    }
    arr[i][j]=min;
    return arr[i][j];
}
int minSmoke(int * p, int n){
	int** arr= new int*[n+1];
	for(int i=0;i<n+1;i++){
		arr[i]=new int[n+1];
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			arr[i][j]=-1;
		}
	}
	return cost(arr,p,1,n);
}

int solve(int n,vector<int>colors)
{   
	int * p=new int[n+1];
	vector<int>:: iterator i1;
	int i=1;
	p[0]=-1;
	for(i1=colors.begin();i1!=colors.end();i1++){
       p[i]= *i1;
       i++;
	}
	return minSmoke(p,n);
}
int main(){
   int n;
   cin>>n;
   vector<int> v;
   for(int i=0;i<n;i++){
   	int x;
   	cin>>x;
   	v.push_back(x);
   }
   cout<<solve(n,v)<<endl;
   return 0;
}