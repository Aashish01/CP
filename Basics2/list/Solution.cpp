#include <iostream>
#include <list>
#include <string>
using namespace std;
//comparator
bool compare1(string str1,string str2){
return str1.length()<str2.length();
}
int main(){
	//it is doubly linked list.
	list<int> list1;
	//Insertion at end
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);

	list<int>:: iterator it;
	for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
    cout<<endl;

    //Deletion at end
    while(!list1.empty()){
    	//give last element, since popback don't return anything.
    	cout<<list1.back()<<" ";
    	list1.pop_back();
    }
    cout<<endl;
    //size
    cout<<list1.size();
    
    //Insertion at beggining
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);
    list1.push_front(40);
    list1.push_front(50);
    for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
	cout<<endl;
	//deletion at front
	while(!list1.empty()){
		cout<<list1.front()<<" ";
		list1.pop_front();
	}
    cout<<endl;

    

    //Insertion at ith position.
    //Take iterator to that positon ,then do insert at position of iterator, it 
    //insert fn return an iterator that points to newly added element.

    it= list1.begin();
    list1.insert(it, 10);
    it++;
    list1.insert(it,25);
    it++;
    list1.insert(it,5);

    for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
    cout<<endl;

    list1.push_back(15);
    list1.push_back(29);
    //5 elements to insert after 3 elemnts.
    it= list1.begin();
    for(int i=0;i<3;i++){
      it++;
    }
    //insert element after position iterator is poiting to,
    //& return an pointer to position of newly added
    it=list1.insert(it,100);
    cout<<*it<<endl;
    for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
    cout<<endl;

    //Similar deletion works by erase.
    //it erase the elemnt iterator is pointing to & return a pointer to position
    //of elemnt next to deletd element
    it= list1.begin();
    for(int i=0;i<3;i++){
    it++;
    }
    it= list1.erase(it);
    cout<<*it<<endl;
    for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
    cout<<endl;

    //remove element by its value, it return nothing
    list1.remove(25);
    list1.remove(15);
    for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
    cout<<endl;

    //Sorting 
    list1.sort();
    for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
    cout<<endl;
    
    //sorting using comparator
    list<string> list2;
    list2.push_back("Hello");
    list2.push_back("Ashish");
    list2.push_back("Delhi");
    list<string>:: iterator it2;
    list2.sort(compare1);
    for(it2=list2.begin();it2!=list2.end();it2++){
		cout<<*it2<<" ";

	}
    cout<<endl;

    //reversing list.
    list1.reverse();
    for(it=list1.begin();it!=list1.end();it++){
		cout<<*it<<" ";

	}
    cout<<endl;

    list2.reverse();
    for(it2=list2.begin();it2!=list2.end();it2++){
		cout<<*it2<<" ";

	}
    cout<<endl;



    return 0;
}