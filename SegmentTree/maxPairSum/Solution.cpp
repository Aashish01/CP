#include <iostream>
#include <utility>
using namespace std;
void tryFunc(pair <int,int> &p ){
	cout<<p.first<<" "<<p.second<<endl;
	p.second=29;

}
int main(){

	pair<int ,char> p1;
	p1= make_pair(3,'b');
	cout<<p1.first<<" "<<p1.second<<endl;

	pair<int ,int> p2(3,4);
	cout<<p2.first<<" "<<p2.second<<endl;

	//change
	p2.first=29;
	cout<<p2.first<<" "<<p2.second<<endl;
 
 pair<int,int> & p3=p2;
 cout<<"p3"<<endl;
 cout<<p3.first<<" "<<p3.second<<endl;

tryFunc(p2);
cout<<p2.first<<" "<<p2.second<<endl;

}