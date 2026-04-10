#include <iostream>
using namespace std;

int main() {
    float side1, side2, side3;

    cin >> side1 >> side2 >> side3;

 
    if (side1 == side2 && side2 == side3) {
        cout << "Equilateral" << endl;
    }
 
    else if (side1 == side2 || side2 == side3 || side1 == side3) {
        cout << "Isosceles" << endl;
    }
 
    else {
        cout << "Scalene" << endl;
    }

    return 0;
}
