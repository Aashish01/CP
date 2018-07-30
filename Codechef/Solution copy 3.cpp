#include <iostream>
#include <string>
using namespace std;
int find(int ** p,int m,int n, int i,int j){
	if(p[i][j]==1){
		return 0;

	}
	for(int l=0;l<n;l++){
		if(p[i][j]==1){
			return 1;
		}
	}
	for(int l=0;l<m;l++){
      if(p[l][j]==1){
      	return 1;
      }
	}
	int x=i,y=j;
	while(x>=0 && y>=0){
		if(p[x][y]==1){
			return 2;
		}
		x--;
		y--;
	}
	x=i;
	y=j;
	while(x<m && y<n){
		if(p[x][y]==1){
			return 2;
		}
		x++;
		y++;
	}
	x=i;
	y=j;
	while(x>=0 && y<n){
		if(p[x][y]==1){
			return 2;
		}
		x--;
		y++;
	}
	x=i;
	y=j;
	while(x<m && y>=0){
		if(p[x][y]==1){
			return 2;
		}
		x++;
		y--;
	}
return -1;
}
int main(){
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int m,n;
		cin>>m>>n;
		int ** p= new int*[m];
		for(int i=0;i<m;i++){
			p[i]=new int[n];

		}
		for(int i=0;i<m;i++){
			string str;
			cin>>str;
			for(int j=0;j<str.length();j++){
				char ch=str.at(j);
				int count=ch;
				if(count==48){
					p[i][j]=0;
				}else{
					p[i][j]=1;
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cout<<find(p,m,n,i,j)<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<m;i++){
			delete [] p[i];
		}
		delete [] p;
	}
}