#include <iostream>
#include <stack>
using namespace std;
int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	//iterator is not allowed on stack as well.
	//bot insert and deletion from top end.

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	cout<<s.size()<<endl;
}