#include <iostream>
using namespace std;
void print(int** arr, int n ){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool isValidMove(int** maze,int** arr, int n, int i,int j,char ch){

		if(ch=='l'){
			if((j-1)<0){
				return false;
			}
			if(maze[i][j-1]==0){
				return false;
			}
			if(arr[i][j-1]==1){
				return false;
			}
			

			return true;
		}

		if(ch=='r'){
			if((j+1)==n){
				return false;
			}
			if(maze[i][j+1]==0){
				return false;
			}
			if(arr[i][j+1]==1){
				return false;
			}

			return true;
		}

		if(ch=='u'){
			if((i-1)<0){
				return false;
			}
			if(maze[i-1][j]==0){
				return false;
			}
			if(arr[i-1][j]==1){
				return false;
			}

			return true;
		}

		if(ch=='d'){
			if((i+1)==n){
				return false;
			}
			if(maze[i+1][j]==0){
				return false;
			}
			if(arr[i+1][j]==1){
				return false;
			}

			return true;
		}

	return false;
}
void ratHelper(int** maze,int** arr,int n,int row,int col ){
	arr[row][col]=1;
	if(row==(n-1) && col== (n-1)){
		print(arr,n);
		arr[row][col]=0;
		return;
	}

	if(isValidMove(maze,arr,n,row,col,'u')){
		ratHelper(maze,arr,n,row-1,col);
	}
	if(isValidMove(maze,arr,n,row,col,'d')){
		ratHelper(maze,arr,n,row+1,col);
	}
	if(isValidMove(maze,arr,n,row,col,'l')){
		ratHelper(maze,arr,n,row,col-1);
	}
	if(isValidMove(maze,arr,n,row,col,'r')){
		ratHelper(maze,arr,n,row,col+1);
	}

	arr[row][col]=0;
	return;

}

void ratInAMaze(int** maze, int n){
	int ** arr= new int*[n];
	for(int i=0;i<n;i++){
		arr[i]= new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	ratHelper(maze,arr,n,0,0);
	for(int i=0;i<n;i++){
		delete [] arr[i];
	}
	delete [] arr;
	return;
}

int main(){
	int n;
	cin>>n;
	int** p= new int*[n];
	for(int i=0;i<n;i++){
		p[i]= new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>p[i][j];
		}
	}
	cout<<endl;
	ratInAMaze(p,n);
	for(int i=0;i<n;i++){
		delete [] p[i];
	}
	delete [] p;
	
	return 0;
}
