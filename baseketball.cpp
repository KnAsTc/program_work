#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;


class Baseketball{
protected:

    int twoPointShotScore;
    int threePointShotScore;
    string name; 
public:
	Baseketball(string n):twoPointShotScore(0),threePointShotScore(0), name(n){
    }
    void TwoPointShot(){
        twoPointShotScore = twoPointShotScore + 2;
    }
    void ThreePointShot(){
        threePointShotScore = threePointShotScore + 3;    
    }
    void Score(){
        cout<<name<<": two-Point Shot Score = "<<twoPointShotScore<<endl;
        cout<<name<<": three-Point Shot Score = "<<threePointShotScore<<endl; 
    }
};

class Rockets:public Baseketball{
private:
	static int teamScore;
public:
	Rockets(string n):Baseketball(n){}
    void TwoPointShot(){
    	twoPointShotScore = twoPointShotScore + 2;
        teamScore = teamScore + 2;
    }
    void ThreePointShot(){
    	threePointShotScore = threePointShotScore + 3;    
        teamScore = teamScore + 3;        
    }
    void randomkey(){
    	switch(rand()%4){
    		case 1:case 2:
				TwoPointShot();
				break;
			case 3:
				ThreePointShot();
				break;
			case 0 :break;		
		}
	}
    bool Score(){
  
    	cout<<name<<": two-Point Shot Score = "<<twoPointShotScore<<endl;
        cout<<name<<": three-Point Shot Score = "<<threePointShotScore<<endl; 
        cout<<"Team Rockets Score = "<<teamScore<<endl<<endl;
		if (teamScore>=100){
		return 1; 
		}
		return 0;     
    }
};
int Rockets::teamScore = 0;

class Lakers:public Baseketball{
private:
	static int teamScore;
public:
	Lakers(string n):Baseketball(n){}
    void TwoPointShot(){
    	twoPointShotScore = twoPointShotScore + 2;
        teamScore = teamScore + 2;
    }
    void ThreePointShot(){
    	threePointShotScore = threePointShotScore + 3;    
        teamScore = teamScore + 3;        
    }
    void randomkey(){ 	
    	switch(rand()%4){
    		case 1:case 2:
				TwoPointShot();
				break;
			case 3:
				ThreePointShot();
				break;
			case 0 :break;		
		}	
		}
    bool Score(){

    	cout<<name<<": two-Point Shot Score = "<<twoPointShotScore<<endl;
        cout<<name<<": three-Point Shot Score = "<<threePointShotScore<<endl; 
        cout<<"Team Lakers Score = "<<teamScore<<endl<<endl;
		if (teamScore>=100){
		return 1; 
		}
		return 0;
    }
};
int Lakers::teamScore = 0;

int main(){
	srand(time(NULL));
    Rockets brooks("Brooks"), wall("Wall");
    Lakers james("James"), morris("Morris");
//	for(int i=0 ;i<1;i++){
	while(1){
			switch(rand()%4){
			case 0 : 
				brooks.randomkey();
				break;
			case 1 :
				wall.randomkey();
				break;
			case 2 :
				james.randomkey();
				break;
			case 3 :
				morris.randomkey();
				break;	
			}
		if(brooks.Score()|wall.Score()|james.Score()|morris.Score()){
			cout<<"finsh";
			break;
		}
	}

    return 0;
}
