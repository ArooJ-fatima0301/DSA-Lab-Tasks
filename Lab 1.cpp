#include <iostream>
using namespace std;

/*
   Create a program that declares an integer variable and a pointer to it. Modify the value of the variable 
   using the pointer and display both the variable and pointer values.
   */
int main()
{
    int num = 91;
    int *ptr = new int;

    ptr = &num;

    cout << "Number: " << num<<endl;
    cout << "Address of the number: " << &num<<endl;
    cout << "Address store in the pointer: " << ptr<<endl;
    cout<<"\n";

    *ptr = 50;
    cout << "Modified number: " << num<<endl;
    cout << "Address of the pointer:" << &ptr <<endl;
    cout << "Address stored in the pointer:" << ptr<<endl;

    return 0;
}