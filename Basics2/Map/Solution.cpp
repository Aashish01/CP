#include <iostream>
#include <map>
#include<unordered_map>
using namespace std;
int main(){

   //Pool
	//all operations insert/find.. in logn as made using bst.
	//key is unique, via search then insert if present update value of old 

	map<int,int> m1;
	//Insertion
	//method1
	m1[1]=1;
	m1[2]=1;
	m1[3]=2;
	m1[4]=1;

	//method2
	m1.insert(pair<int,int>(5,2));

	//Deletion via key
	m1.erase(2);

	//Surf
    //it->first means it.first , when use -> no need of *
	map<int,int>:: iterator it;
	for(it=m1.begin();it!=m1.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	

	//finding key: since find fn return m1.end if not found
	if(m1.find(4)==m1.end()){
		cout<<"Not found"<<endl;
	}else{
		cout<<"Found"<<endl;
	}

	//Getting value at key: map behave like array so use like that.
	cout<<m1[4]<<endl;

 
 //Unordered map has everything in O(1)
	//Everything /fns are same as of map.
	unordered_map<char,int> m2;
	m2['a']=1;
	m2['b']=2;
	m2.insert(pair<char,int>('c',1));

	unordered_map<char,int>:: iterator it1;
	for(it1=m2.begin();it1!=m2.end();it1++){
		cout<<it1->first<<" "<<it1->second<<endl;
	}

	bool check= m2.empty();
	cout<<check<<endl;

	cout<<m2.size()<<endl;
	m2.erase('c'); 





}