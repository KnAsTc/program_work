#include<iostream>
#include<cstdlib>
using namespace std;

int func(int* a,int *b,int n){
	int inner;//���n���G
	cout<<"a matrix" <<endl;
	for(int i=0;i<n;i++){//��Ja�x�} 
		
		cin>>*(a+i);
	}
	cout<<"b matrix" <<endl;
	for(int i=0;i<n;i++){//��Jb�x�} 
		
		cin>>*(b+i);
	}
	
	for(int i=0;i<n;i++){
			
		inner+=	(*a) * (*b) ;
		a++;
		b++;
	}
	cout<<"inner product=";
	return inner;
}

int main(){
	int n;
	cin>>n; //�x�}�j�p 
	int* a=(int*)malloc(n*sizeof(n));//�Ы�a�x�} 
	int* b=(int*)malloc(n*sizeof(n));//�Ы�b�x�} 
	cout<<func(a,b,n);//�N�x�}��Jfunc 
}
