#include <iostream>
#include <set>
using namespace std;
int main(){
	//Here we get a pool to add as many keys as we want. Unique is added as it searches 
	//if key to inserted is already present or not.
	//Unique only
	//logn for all operations:insert/search
	set<int> s1;
	s1.insert(5);
	s1.insert(3);
	s1.insert(5);
	s1.insert(4);

	set<int>:: iterator i1;
	for(i1=s1.begin();i1!=s1.end();i1++){
		cout<<*i1<<" ";
	}
    cout<<endl;
    //Deletion
    s1.erase(3);

    bool check= s1.empty();
    cout<<check<<endl;

    if(s1.find(3)==s1.end()){
    	cout<<"Not found"<<endl;
    }else{
    	cout<<"found"<<endl;
    }

//Just like set, unordered_set also exist for O(1).
}