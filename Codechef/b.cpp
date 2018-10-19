#include <iostream>
using namespace std;
int gcd(int a,int b){
if(a<b){
	return gcd(b,a);
}
if(b==0){
	return a;
}
return gcd(b,a%b);
}
void graph(int ** p, int n, bool* visited, int start){
	visited[start]=true;
	for(int i=0;i<n;i++){
		if(p[start][i]==1 && visited[i]!=true){
			graph(p,n,visited,i);
		}
	}
}
void print(int n){
	int * arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ** p= new int*[n];
	for(int i=0;i<n;i++){
		p[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(gcd(arr[i],arr[j])==1){
				p[i][j]=1;
			}else{
				p[i][j]=0;
			}
		}
	}
	bool * visited= new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	graph(p,n,visited,0);
	bool ans= true;
	for (int i = 0; i < n; i++)
	{
		if(visited[i]==false){
			ans=false;
			break;
		}
	}
	if(ans==true){
		cout<<"0"<<"\n";
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}else{
		cout<<"1"<<"\n";
		arr[n-1]=29;
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<n;i++){
		delete [] p[i];
	}
	delete [] p;
	delete [] arr;
	delete [] visited;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int n;
		cin>>n;
		print(n);
	}
	return 0;
}