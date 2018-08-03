#include <iostream>
using namespace std;
void multiplyMatrix(int** p,int m, int k, int** q, int n, int** r){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			r[i][j]=0;

			for(int l=0;l<k;l++){
				r[i][j]= r[i][j]+ (p[i][l]*q[l][j]);
			}
		}
	}
	return;
}
void matrixExponent(int** p, int m,int n){
	if(n==0){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				if(i==j){
					p[i][j]=1;
				}else{
					p[i][j]=0;
				}
			}
		}
		return ;
	}
	if(n%2==0){
		int** r= new int*[m];
		for(int i=0;i<m;i++){
			r[i]= new int[m];
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				r[i][j]=0;
			}
		}
		multiplyMatrix(p,m,m,p,m,r);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				p[i][j]=r[i][j];
			}
		}
		for(int i=0;i<m;i++){
			delete [] r[i];
		}
		delete [] r;

		matrixExponent(p,m,n/2);
	}
	int** temp = new int*[m];
	for(int i=0;i<m;i++){
		temp[i]= new int[m];
	} 
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			temp[i][j]= p[i][j];
		}
	}
	int** r= new int*[m];
		for(int i=0;i<m;i++){
			r[i]= new int[m];
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				r[i][j]=0;
			}
		}
		multiplyMatrix(p,m,m,p,m,r);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				p[i][j]=r[i][j];
			}
		}
	matrixExponent(p,m,n/2);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				r[i][j]=0;
			}
		}
	multiplyMatrix(temp,m,m,p,m,r);
	for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				p[i][j]=r[i][j];
			}
		}
		for(int i=0;i<m;i++){
			delete [] r[i];
		}
		delete [] r;
	for(int i=0;i<m;i++){
		delete [] temp[i];
	}
	delete [] temp;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int m,power;
	cin>>m>>power;
	int** p= new int*[m];
	for(int i=0;i<m;i++){
      p[i]= new int[m];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>p[i][j];
		}
	}
	matrixExponent(p,m,power);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cout<<p[i][j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=0;i<m;i++){
		delete [] p[i];
	}
	delete [] p;
	return 0;
}
