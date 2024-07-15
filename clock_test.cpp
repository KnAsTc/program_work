#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

class A{
	protected:
	A *next,*now;
		
	public:
	int x=0;
	A*call(A *re){
    	now = re;
		return now;
	}
	 void Link2(A *nextNode){
        next = nextNode;
    }
     A*Move2NextNode(){
        return next;
    }
};
class B:public A{

	public:
	B(int a){
		x=a;
	}	
	void E(){
		*(this->call(this))=*(this->Move2NextNode());
		cout<<this<<endl;
		cout<<this->Move2NextNode()<<endl;
		free(this->Move2NextNode());
	}
	
};

int main(){
	A *A1;
	B *B1;
	B *B2;
	
	B1 = new B(1);
	B2 = new B(2);
	A1 = B2;
	A1->Link2(A1);
	
	B1->Link2(A1->Move2NextNode());
    A1->Link2(B1);
	A1 = A1->Move2NextNode();
	B1->E();

	
}
