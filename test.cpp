#include <iostream>

using namespace std;

class Car{
private:
    int x;
    int y;
public:
    //default
    Car(){
        x = 0;
        y = 0;
        cout<<"Move to ("<<x<<","<<y<<")"<<endl;
    }
    //parameterized
    Car(int a, int b){
        x = a;
        y = b;
        cout<<"Move to ("<<x<<","<<y<<")"<<endl;
    }
    //copy
    Car(const Car &reproduce){
        x = reproduce.x;
        y = reproduce.y;
        cout<<"Move to ("<<x<<","<<y<<")"<<endl;
    }
};

int main(){
    cout<<"Car toyota calls default constructor Car()"<<endl;
    Car toyota;
    cout<<"Car lexus calls parameterized constructor Car(int a, int b)"<<endl;
    Car lexus(10,20);
    cout<<"Car bmw calls copy constructor Car(Car &) moves to the same location as Car lexus"<<endl;
    Car bmw(lexus);

 /*
    cout<<"Car toyota calls default constructor Car()"<<endl;
    Car *toyota = new Car;
    cout<<"Car lexus calls parameterized constructor Car(int a, int b)"<<endl;
    Car *lexus = new Car(10,20);
    cout<<"Car bmw calls copy constructor Car(Car &) moves to the same location as Car lexus"<<endl;
    Car *bmw = new Car(lexus);
 */

    return 0;
}

