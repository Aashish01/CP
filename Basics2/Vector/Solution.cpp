#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	vector<int> v1;
	//Creates one array index and add element to it at end of vector.
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(9);
	cout<<v1.size()<<endl;

	//Iteration method1.
	vector<int>:: iterator i1;  //i1 is pointer
	for(i1=v1.begin();i1!=v1.end();i1++){ //begin is start element of vector
		//end is position next to last element of vector
     cout<<*i1<<" ";   //* is dereferencing operator,that gives value, that i1 is pointing to
	}
	cout<<endl;

    //Deletes element at end.
	v1.pop_back();

	//Updating values.
	v1[0]=1;
	v1[1]=2;

	//Method 2 for iteration.
	cout<<v1.size()<<endl;
	for(int i=0;i<v1.size();i++){
		cout<<v1[i]<<" ";
	}
	cout<<endl;

    //Declaring vector with some initial size
	vector<int> v2(5);
    for(int i=0;i<v2.size();i++){
    	v2[i]=i;
    	cout<<v2[i]<<" ";
    }
    cout<<endl;
    //Altering size.
    v2.pop_back();
    v2.push_back(5);
    v2.push_back(6);
    cout<<v2.size()<<endl;
    for(i1=v2.begin();i1!=v2.end();i1++){
    	cout<<*i1<<" ";
    }
    cout<<endl;
    
    //Analogous to empty fn.
    while(!v1.empty()){
     cout<<v1[v1.size()-1]<<" ";
     v1.pop_back();
    }
    cout<<endl;

    vector<char> v3;
    vector<string> v4;
    cout<<"Enter size of char vector & string vector"<<endl;
    int n1,n2;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++){
    	char ch;
    	cin>>ch;
    	v3.push_back(ch);
    }
    vector<char>:: iterator i2;
    for(i2=v3.begin();i2!=v3.end();i2++){
    	cout<<*i2<<" ";
    }
    cout<<endl;

    for(int i=0;i<n2;i++){
    	string str;
    	cin>>str;
    	v4.push_back(str);
    }
    vector<string>:: iterator i3;
    for(i3=v4.begin();i3!=v4.end();i3++){
    	cout<<*i3<<" ";
    }
    cout<<endl;


 return 0;

}