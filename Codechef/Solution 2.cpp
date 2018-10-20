#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
string decToBinary(int n) 
{ if(n==0){
	return "0";
}
	string str="";
    // Size of an integer is assumed to be 32 bits 
    for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            str+="1";
        else
            str+="0";
    } 
    int j=0;
    while(str.at(j)!='1'){
    	j++;
    }
    for(int i=0;i<j;i++){
    	
    		str=str.substr(1);
    	
    }
    return str;
} 
int binaryToDecimal(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
      
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
      
    int len = num.length(); 
    for (int i=len-1;i>=0;i--) 
    { 
        if (num[i] == '1')         
            dec_value += base; 
        base = base * 2; 
    } 
      
    return dec_value; 
}
vector<string> collectString(int l){
	if(l==1){
		vector<string> v1;
		v1.push_back("0");
		v1.push_back("1");
		return v1;
	}
	vector<string> v1= collectString(l-1);
	vector<string> v2;
	while(v1.size()!=0){
		string str= v1.back();
		v1.pop_back();
		string str1= "1"+str;
		string str2= "0"+str;
		v2.push_back(str1);
		v2.push_back(str2);
	}
	return v2;
}
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		int a,b,c;
		cin>>a>>b>>c;
		string str1=decToBinary(a);
		string str2= decToBinary(b);
		vector<string> v1= collectString(str1.length());
		vector<string> v2= collectString(str2.length());
    vector<string>:: iterator i1,i2;
    vector<int> s1,s2;
	for(i1=v1.begin();i1!=v1.end();i1++){
		string str3= *i1;
		if(binaryToDecimal(str3)<=c){
           s1.push_back(binaryToDecimal(str3));
		}
	}
	for(i2=v2.begin();i2!=v2.end();i2++){
		string str3= *i2;
		if(binaryToDecimal(str3)<=c){
			s2.push_back(binaryToDecimal(str3));
		}
	}
int count=0;
    unordered_set< std::pair<int, int> > edge;
	vector<int> :: iterator x1,x2;
	for(x1=s1.begin();x1!=s1.end();x1++){
		for(x2=s2.begin();x2!=s2.end();x2++){
			if((*x1 + *x2)==c){
				if(set1.find(key<*x1,*x2>)==set1.end()){
					count++;
                set1.insert(pair<*x1, *x2>);
				}
				
			}
		}
	}
    cout<<count<<"\n";
	}


	return 0;
}