#include <iostream>
using namespace std;


int main() {

	// a)
	cout << "Task A)" << "\n" << "---------\n";
	int numval = 1024;
	int *pval = &numval;

	cout << "Value of 'int numval': " << numval << endl;
	cout << "Address of 'int pval': " << &pval << "\n\n\n";

	// b)
	cout << "Task B)" << "\n" << "---------\n";
	*pval = 7;
	cout << "Value of int *pval should be now 7, let see: " << *pval << "\n\n\n";



	// c)

	cout << "Task C" << "\n" << "---------\n";
	cout << "Address of numval is: " << &numval <<"\nAnd the value of it is: "<< *&numval << endl;
	cout << "Address of numval is: " << &pval << "\nAnd the value of it is: " << *pval << "\n\n\n";
	//Muuttujien 2 viimeistä merkkiä ovat toisistaan erillisiä. Muuten lähes identtiset

	// d)
	cout << "Task E)" << "\n" << "---------\n";
	cout <<"Canceling * with & : " << *&numval << "\n\n\n";

	//e)
	cout << "Task E)" << "\n" << "---------\n";
	cout << "Size of 'int numval' in bytes is : " << sizeof(numval) << "\n";
	cout << "Size of 'int pval' in bytes is : " << sizeof(pval) << "\n\n";

	//g
	cout << "Task G)" << "\n" << "---------\n";
	int* pval2 = nullptr;
	pval2 = &numval;
	cout << *pval2;


	return 0;

}
