#include <iostream>
#include <utility>
using namespace std;
int main(){
	//Hashmaps in java were a pool, we make one map one add many key,value pairs on it.
	//But pair class exist solo,not added on same pool.
	//it can store 2 data tpes, or even objects.

	//Later
	pair<int ,char> p1;
	p1= make_pair(3,'b');
	cout<<p1.first<<" "<<p1.second<<endl;

    //hand to hand
	pair<int ,int> p2(3,4);
	cout<<p2.first<<" "<<p2.second<<endl;
}