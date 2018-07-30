#include <iostream>
#include <set>
#include <utility>
using namespace std;
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int a,b,d;
		cin>>a>>b>>d;
		set< pair<int,int> > set1;
        for(int x=0;a*x<=d;x++){
        	if((d-a*x)%b==0){
        		pair<int,int> p(x, (d-a*x)/b);
        		set1.insert(p);
        	}
        }
        for(int y=0;b*y<=d;y++){
        	if((d-b*y)%a==0){
        		set1.insert(make_pair((d-b*y)/a , y));
        	}
        }
        cout<<set1.size()<<"\n";
	}
	return 0;
}