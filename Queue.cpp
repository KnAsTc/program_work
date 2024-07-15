#include<iostream>

#define SIZE     3
#define IS_FULL  1
#define IS_EMPTY  1
#define	FALL     -1
#define SUCESS   1



using namespace std;



class Queue{
private:
	int *data = new int[SIZE];
	int front=-1;//開頭 
	int rear=-1;//當前 

public:
//	int IsFull(){
//		
//		cout<<"1"<<(rear==SIZE-1 && front==0)<<endl;
//		cout<<"2"<<(front==rear+1)<<endl;
//		if ((rear==SIZE-1 && front==0) ||(front==rear+1))return IS_FULL;
//	}
	int IsFull(){
		
        if((front == rear + 1) || (front == 0 && rear == SIZE - 1)){
            return IS_FULL;
        }
        return 0;
    }
	int IsEmpty(){
		if (rear == -1){
			return IS_EMPTY;	
		}
		return 0;
	} 
	
	void enqueue(int value){
		if(IsFull()){
				
			cout<<"FULL"<<endl;	
		}
		else{
			if(front==-1)front=0;
			rear=(rear+1)%SIZE;
			data[rear]=value;
			cout<<"add:"<<value<<endl; 	
		}	
	}
	int dequeue(){
		int temp;
		if(IsEmpty()){
			cout<<"EMPTY"<<endl;
			return FALL;
		}
		else{
			temp=data[front];
			
			if(front==rear){
				front=-1;
				rear=-1;
			}
			else{
				front=(front+1)%SIZE;
			}
			cout<<"dequeue:"<<temp<<endl;
			return temp;
		}
		
	}
	void showqueue(){
		int i;
		if(IsEmpty())cout<<"EMPTY"<<endl;	
		else{
			for(i=front; i!=rear; i=(i+1)%SIZE){
                cout<<data[i]<<" ";
            }
            cout<<data[i]<<endl;
		}
	}		


};



int main(){
	
	Queue Q1;
	
	Q1.dequeue();
	
	Q1.enqueue(10);
	
	Q1.showqueue();
	
	Q1.enqueue(30);
	Q1.enqueue(40);
	Q1.enqueue(50);
	
	Q1.showqueue();
	
	Q1.dequeue();
	Q1.dequeue();
	Q1.dequeue();
	Q1.dequeue();
	
	Q1.showqueue();
		
	Q1.enqueue(20);
	Q1.enqueue(30);
	Q1.enqueue(40);
	Q1.enqueue(50);
	Q1.enqueue(20);
	Q1.enqueue(30);
	Q1.enqueue(20);
	Q1.enqueue(30);
	
	Q1.showqueue();
	
	Q1.enqueue(40);
	Q1.enqueue(50);
	Q1.enqueue(20);	
	
	
	return 0;
}
 
