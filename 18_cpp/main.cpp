#include <iostream>

using namespace std;

int main()
{
    int arr1[2147483647];

    int* arr2 = new int[576460752303423487];


    cout << arr1[0];
    cout << *arr2+1;
}
