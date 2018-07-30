#include <iostream>
#include <queue>
using namespace std;
int main(){
	queue<int> q1;
	//insertion take place at end, deletion at beginning
	q1.push(5);
	q1.push(10);
	q1.push(15);
	q1.push(25);
	q1.push(30);

//Iterator to queue is not allowed in c++
	// queue<int>::iterator it;
	// for(it=q1.begin();it!=q1.end();it++){
	// 	cout<<*it<<" ";
	// }
	//cout<<endl;

	while(!q1.empty()){
		cout<<q1.front()<<" ";
		q1.pop();
	}
	cout<<endl;
	cout<<q1.size()<<endl;

	return 0;

}