#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int arr[6];
	for(int i=0;i<6;i++){
		cin>>arr[i];
	}
	int x;
	cin>>x;
	//for binary search array must be sorted in increasing order.
	sort(arr,arr+6);
	bool isFound= binary_search(arr,arr+6,x);
	if(isFound==true){
        cout<<lower_bound(arr,arr+6,x)-arr<<endl;
	}else{
		cout<<"Not found"<<endl;
	}

	return 0;
}