#include <iostream>

using namespace std;

//creating a class
class Box {
private:
    int length;

public:
    //default constructor
    Box(){
        cout<<"constructor called"<<endl;
    }
   //so adrees of object and this pointer are same both are pointing to same address 
    Box(int length) {
        cout<<this<<endl;
        this->length = length;
    }
    int getLenth(){
        return length;
    }
    int setLength(int length){
        this->length = length;
    }
    
};

int main() {

    Box rocky;
    rocky.setLength(10);
    cout<<"rocky length "<<rocky.getLenth()<<endl;

    //pandit ke sare lakshan rocky se mila diya ab padit bhi rocky ki tarah ho gya
    //copy constructor --> like mujhe khud ka kuch nhi karna bana banaya chiz hai mai to bhaiya use bhi follow karunga


    Box pandit(rocky);
    cout<<"pandit length "<<pandit.getLenth()<<endl;






    //object created statically

    // Box ajay(10);
    // cout<<"adress of object "<<&ajay<<endl;

}
