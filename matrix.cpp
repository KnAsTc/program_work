#include<iostream>
using namespace std;


void product(int* first,int* second){
	int *temp=first;//first �O�d�}�Y��m 
	int *temp2=second;//second �O�d�}�Y��m 
	int ans[3][3];//�x�}�ۭ����Ȧs 
	cout<<"first matrix"<<endl;
	int col[3];
	for(int i=0;i<3;i++){	//�Ĥ@�ӯx�}��J 
		for(int j=0;j<3;j++){
			cin>>*first;
			first++;
		}
	}
	cout<<"second matrix"<<endl;	
	for(int i=0;i<3;i++){	//�ĤG�ӯx�}��J 
		for(int j=0;j<3;j++){
			cin>>*second;
			second++;
		}
	}
	for(int i=0;i<3;i++){	//�x�}�ۭ� 
		for(int j=0;j<3;j++){//�Ĥ@�ӯx�} 0 1 2����m �� �ĤG�ӯx�} 0 3 6����m �H������ 
			ans[i][j]=(*temp +i*3) * (*temp2+j) + (*temp+i*3+1) * (*temp2+j+3) +(*temp+i*3+2) * (*temp2+j+6);
		}
	}
	for(int i=0;i<3;i++){  //�N�Ĥ@�ӯx�}�������G 
		for(int j=0;j<3;j++){
			*temp=ans[i][j];
			temp++;
		}
	}
}
int main(){	
	int first[3][3]={0};
	int *ptr;
	ptr = &first[0][0];//�Ĥ@�ӯx�}�}�Y
	int second[3][3]={0};
	int *ptr2;
	ptr2 = &second[0][0];//�ĤG�ӯx�}�}�Y
	
	product(ptr,ptr2); //�x�}�}�Y��Jfunction
	cout<<"the answer:"<<endl;
	for(int i=0;i<3;i++){ //��X���G 
		for(int j=0;j<3;j++){
			cout<<first[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
