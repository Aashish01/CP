#include <iostream>
#include <math.h>
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
		return;
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
	return;
}
long long int fibonacci(long long int n){
	if(n==0){
		 return 0;
	}
	if(n==1){
		return 1;
	}
	int** p= new int*[2];
	for(int i=0;i<2;i++){
		p[i]= new int[2];
	} 
	p[0][0]=1;
	p[0][1]=1;
	p[1][0]=1;
	p[1][1]=0;
	matrixExponent(p,2,n-1);
	int** q= new int*[2];
	q[0]= new int[1];
	q[1]= new int[1];
	q[0][0]=1;
	q[1][0]=0;
	int** r= new int*[2];
	for(int i=0;i<2;i++){
      r[i]=new int[1];
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<1;j++){
          r[i][j]=0;
		}
	}
	multiplyMatrix(p,2,2,q,1,r);
	long long int ans=r[0][0];
	for(int i=0;i<2;i++){
		delete [] p[i];
		delete [] q[i];
		delete [] r[i];
	}
	delete [] p;
	delete [] q;
	delete [] r;
	return ans;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int mo =(int)pow(10,9)+7;
	int m, n;
	cin>>m>>n;
	long long int ans1= fibonacci(m+1);
	long long int ans2= fibonacci(n+2);
	long long int fibsum= (ans2%mo-ans1%mo)%mo;
	cout<<fibsum<<"\n";
	return 0;

}