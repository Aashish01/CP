#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int l=0;l<t;l++){
		bool hold=true, hold2=true;
		int n;
		cin>>n;
		int *p= new int[n];
		for(int i=0;i<n;i++){
			cin>>p[i];
			if(p[i]!=-1){
				hold=false;
			}
		}
		if(hold==true){
			cout<<"inf"<<"\n";
			continue;
		}
		for(int i=1;i<n;i++){
			if(p[i]!=-1){
				hold2=false;
			}
		}
		if(hold2==true && p[0]==1){
			cout<<"impossible"<<"\n";
			continue;
		}
		
		int countTotal=0;
		vector<int> v1;
		unordered_map<int,int> m1;
		bool hold3=false;;
        
        if(p[0]==1){
          for(int i=1;i<n;i++){
          	if(p[i]==-1){
          		continue;
          	}
			int count=0;
			int lhs=p[i]-1;
			if(lhs==0){
				v1.push_back(i);
				count++;
				if(m1.find(i)==m1.end()){
					m1[i]=1;
				}else{
					m1[i]++;
				}
			}
			for(int m=p[i];m>=1;m--){
				
				if(i%m==lhs){
					v1.push_back(m);
					count++;
					if(m1.find(m)==m1.end()){
						m1[m]=1;
					}else{
						m1[m]++;
					}
				}
			}
			if(count==0){
				cout<<"impossible"<<"\n";
				hold3=true;
				break;
			}else{
				countTotal++;
			}
		}
		}else{
for(int i=0;i<n;i++){
           	if(p[i]==-1){
          		continue;
          	}
			int count=0;
			int lhs=p[i]-1;
			if(lhs==0){
				v1.push_back(i);
				count++;
				if(m1.find(i)==m1.end()){
					m1[i]=1;
				}else{
					m1[i]++;
				}
			}
			for(int m=p[i];m>=1;m--){

				if(i%m==lhs){
					v1.push_back(m);
					count++;
					if(m1.find(m)==m1.end()){
						m1[m]=1;
					}else{
						m1[m]++;
					}
				}
			}

			if(count==0){
				cout<<"impossible"<<"\n";
				hold3=true;
				break;
			}else{
				countTotal++;
			}
		}
		}
        
          if(v1.size()==0 && hold3==true){
           continue;
          }
        
		  
		
			// int max=-1;
			// vector<int>:: iterator it;
			// for(it=v1.begin();it!=v1.end();it++){
			// 	if(m1[*it]==countTotal && *it>max){
			// 		max= *it;
			// 	}
			// }
			// if(max==-1){
			// 	cout<<"impossible"<<"\n";
			// }else{
			// 	cout<<max<<"\n";
			// }
            
   //          int max2=-1;
			// unordered_map<int,int> :: iterator it2;
			// for(it2=m1.begin();it2!=m1.end();it2++){
			// 	int elem= it2->first;
			// 	bool hold4=true;
			// 	int b=-1;
			// 	if(p[0]==1){
   //               b=1;
			// 	}else{
			// 		b=0;
			// 	}
   //            for(int i=b;i<n;i++){
   //            	if(p[i]!=-1){
   //            		if((p[i]-1)!=(i%elem)){
   //            		hold4=false;
   //            	}
   //            	}
              	
   //            }
   //            if(hold4==true && elem>max2){
   //            	max2=elem;
              
   //            }
			// }
			// if(max2==-1){
			// 	cout<<"impossible"<<"\n";
			// }else{
			// 	cout<<max2<<"\n";
			// }
          if(m1.size()!=0){
          	unordered_map<int,int> :: iterator it2;
          	int max=-1;
			for(it2=m1.begin();it2!=m1.end();it2++){
				int elem= it2->first;
				if(elem>max){
					max=elem;
				}

			}
			cout<<max<<"\n";
          }
		

	}
	return 0;
}