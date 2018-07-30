#include <iostream>
using namespace std;
bool check(int a,int b,int c,int x,int y){
	if((x-a)==(b+c-y)){
		if(x-a<=b && x-a>=0){
			return true;
		}
	}
	if((y-a)==(b+c-x)){
		if(y-a<=b && y-a>=0){
            return true;
		}
	}
	return false;
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int a,b,c,x,y;
		cin>>a>>b>>c>>x>>y;
		if(check(a,b,c,x,y) || check(b,a,c,x,y) || check(a,c,b,x,y)){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}