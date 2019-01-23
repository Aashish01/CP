#include <iostream>
#include <queue> //for priority queue also same header file.
#include <vector>
#include <functional> // for greater int
#include <string>
using namespace std;
//learn after learning ponter
// class Comparator{
// 	bool compare(string str1,string str2){
// 	return str1.length()<str2.length();
//     }
// };

int main(){
	//By default max priority queue is made.
    priority_queue<int> pq1;
    pq1.push(25);
    pq1.push(4);
    pq1.push(19);
    pq1.push(1);
    pq1.push(29);

   //Iterator not allowed in stack , queue & priority queue.
    //Only allowed in linked list, vctor, map, set etc.

    // priority_queue<int>:: iterator it;
    // for(it = pq1.begin();it!=pq1.end();it++){
    // 	cout<<*it<<" ";
    // }
    // cout<<endl;

    while(!pq1.empty()){
    	//print front/ max/min element
    	cout<<pq1.top()<<" ";
    	//deletion will take place base on up/down heapify etc
    	pq1.pop();
    }
    cout<<endl;
    cout<<pq1.size()<<endl;


    //Min priority queue
    //greater<int> not greater<int>()
    // space b/w greater<int> & closing >
priority_queue<int, vector<int>, greater<int> > pq2;
    pq2.push(25);
    pq2.push(4);
    pq2.push(19);
    pq2.push(1);
    pq2.push(29);

    while(!pq2.empty()){
    	//print front/ max/min element
    	cout<<pq2.top()<<" ";
    	//deletion will take place base on up/down heapify etc
    	pq2.pop();
    }
    cout<<endl;
    cout<<pq2.size()<<endl;

    //Based On comparator
//make a comparator class that contain bool compare method . pass this class name, along with a vector

//learn it after learning pointers.
//     priority_queue<string , vector<string>, Comparator> pq3;
//     pq3.push("Hey");
//     pq3.push("Tsunami");
//     pq3.push("Ashish");
//     pq3.push("I");
//     while(!pq3.empty()){
//     	cout<<pq3.top()<<" ";
//     	pq3.pop();
//     }
// cout<<endl;





	return 0;
}