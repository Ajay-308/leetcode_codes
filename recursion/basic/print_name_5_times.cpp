#include <iostream>
#include <string>

using namespace std;

void call( string& name, int index) {
    if(index > 0){
        cout << name <<endl;
        call(name, index-1);
    }
}

int main() {
    string name;
    cout << "Enter your name:" << endl;
    cin >> name;

    call(name, 5);

    return 0;
}
