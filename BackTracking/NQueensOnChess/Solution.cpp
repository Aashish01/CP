#include <iostream>
using namespace std;
void markVisited(bool** visited, int i,int j, int n){
	for(int l=0;l<n;l++){
		visited[i][l]= true;
		visited[l][j]=true;
	}
	int x=i;
	int y=j;
	while(x>=0 && y>=0){
		visited[x][y]=true;
		x--;
		y--;
	}
	x=i;
	y=j;
	while(x<n && y<n){
		visited[x][y]=true;
		x++;
		y++;
	}
	x=i;
	y=j;
	while(x>=0 && y<n){
		visited[x][y]=true;
		x--;
		y++;
	}
	x=i;
	y=j;
	while(x<n && y>=0){
		visited[x][y]=true;
		x++;
		y--;
	}
	return;
}

void markUnvisited(bool** visited,int** arr, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visited[i][j]=false;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				markVisited(visited,i,j,n);
			}
		}
	}
	return;

}

void print(int** arr, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void print2(bool** arr, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void printAll(int** arr, bool** visited,int row, int* col,bool backTrack,int n){
	if(row>=n){
		print(arr,n);
		arr[row-1][col[row-1]]=0;
		markUnvisited(visited,arr,n);
		col[row-1]++;
		printAll(arr,visited,row-1, col,true,n);
		return;
	}

	int i=row;
	int j;
	if(backTrack==false){
		j=0;
	}else{
		j=col[row];
	}

	while(visited[i][j]!=false && j<n){
		j++;
	}
	if(j==n && row==0){
		return;
	}
	if(j<n){
		arr[i][j]=1;
		markVisited(visited,i,j,n);
		col[row]=j;
		printAll(arr,visited,row+1,col,false,n);
	}else{
		arr[i-1][col[row-1]]=0;
		markUnvisited(visited,arr,n);
		col[row-1]++;
		printAll(arr,visited,row-1,col,true,n);
	}

}
void placeNQueens(int n){
	int* col= new int[n];
	for(int i=0;i<n;i++){
		col[i]=0;
	}
bool** visited= new bool*[n];
	int** arr= new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		visited[i]= new bool[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=0;
			visited[i][j]=false;
		}
	}
	printAll(arr,visited,0,col,false,n);
	for(int i=0;i<n;i++){
		delete [] arr[i];
	}
	delete [] arr;
	for(int i=0;i<n;i++){
		delete [] visited[i];
	}
	delete [] visited;

}

int main(){
	int n;
	cin>>n;
    
	placeNQueens(n);
	return 0;
}