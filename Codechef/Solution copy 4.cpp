#include <iostream>
#include <math.h>
using namespace std;
long long int gcd(int a,int b){
	if(a<b){
		return gcd(b,a);
	}
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int ** p= new int*[n];
	for(int i=0;i<n;i++){
		p[i]=new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>p[i][j];
		}
	}
	int modulo= (int)pow(10,9) +7;
	long long int gcdSum= 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int x=i+1;x<n;x++){
              for(int y=0;y<m;y++){
              	long long int z= gcd(p[i][j],p[x][y]);
              	gcdSum= (gcdSum%modulo + z%modulo)%modulo;
              }
			}
		}
	}
	cout<<gcdSum<<"\n";
	for(int i=0;i<n;i++){
		delete [] p[i];
	}
	delete [] p;
	return 0;

}