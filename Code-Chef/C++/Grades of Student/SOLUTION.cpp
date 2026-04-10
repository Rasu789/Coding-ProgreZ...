 #include <iostream>
using namespace std;

int main() {
    int mark;
    cin>>mark;
    if (mark > 90)
    {
        cout<<"A\n";
    }
    else if(70>mark>90)
    {
        cout<<"B\n";
    }
    else {
        cout<<"C\n";
    }
    return 0;
}
