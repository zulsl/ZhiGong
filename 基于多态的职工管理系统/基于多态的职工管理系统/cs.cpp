#include<iostream>
using namespace std;

int main()
{
	int arr[5] = { 0,1,2,3,4 };
	int* arr2 = arr;
	cout << arr2[2] << endl;
	system("pause");
}