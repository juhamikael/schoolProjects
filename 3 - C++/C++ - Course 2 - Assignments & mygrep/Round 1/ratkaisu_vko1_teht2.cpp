#include <iostream>
using namespace std;

void swap(int* x, int* y);

int main() {
	int val1 = 9;
	int val2 = 24;
	cout << "Value 1: " << val1 << "\nValue 2: " << val2 << "\n" << "\nRunning swap function \n\n";
	swap(&val1, &val2);

	cout << "Values after swap function\n";
	cout << "Value 1: " << val1 << "\nValue 2: " << val2 << "\n\n\n";



	return 0;
}

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}
