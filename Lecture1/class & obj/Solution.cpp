#include <iostream>
#include <string>
using namespace std;
//Rules: int main is not kept in any class.
//each class is terminated by semicolon
//methods are not terminated
//class is neither public, private anything. We just specify it when we want to inherit
//All private once, all public , all protected member fn, data member kept in one roof
//this pointer

class Student{
private:
	int marks;
public:
	int rollNo;
	string name;
	//Constructor.
Student(int a,int b, string name){
   this->marks=a;
   this->rollNo=b;
   this->name=name;
}
   void print(){
   	cout<<name<<" "<<marks<<" "<<rollNo<<endl;
   }
};
class Teacher{
  
};
class Monitor: public Student{
//monitor will inherit all these data members of Student.

 
};
//int main is kept outside classes always.
int main(){
	cout<<"Hello world"<<endl;
	Student Ashish(25, 9, "Ashish");
	Ashish.print();
	Student radha(12,23,"Radha");
    radha.print();
    


}
