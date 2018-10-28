#include <iostream>
using namespace std;
struct Node{
   int first;
   int second;
};
int main(){
   Node node1;
   node1.first=3;
   node1.second=12;
   cout<<node1.first<<" "<<node1.second<<"\n";
   return 0;
}