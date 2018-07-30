#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> removeDuplicates(vector<int> input){
	set<int> set1;
	vector<int>:: iterator it1;
	for(it1=input.begin();it1!=input.end();it1++){
		set1.insert(*it1);
	}

	vector<int> v1;
	set<int>:: iterator it2;
	for(it2=set1.begin();it2!=set1.end();it2++){
		v1.push_back(*it2);
	}
	return v1;
}
int main(){
	vector<int> v1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		v1.push_back(m);
	}
	vector<int>:: iterator it;
	vector<int> v2= removeDuplicates(v1);
	
	for(it=v2.begin();it!=v2.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}