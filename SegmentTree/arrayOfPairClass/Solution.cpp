#include <iostream>
#include <utility>
using namespace std;
//Array of pair class.
int main(){
	int n;
	cin>>n;
	pair<int,int> * p= new pair<int,int>[n];
	for(int i=0;i<n;i++){
		p[i]= make_pair(i,i+2);
		cout<<p[i].first<<" "<<p[i].second<<"\n";
	}
	return 0;
}