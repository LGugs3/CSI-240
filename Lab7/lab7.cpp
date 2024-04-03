
#include "method1.h"

int main()
{
	string inputFileName, outputFileName;
	int key;

	cout << "Input file name: ";
	getline(cin, inputFileName);

	cout << "Output file name: ";
	getline(cin, outputFileName);

	do
	{
		cout << "Enter key: ";
		cin >> key;
	} while (key > 26);

	Method1 test = Method1(inputFileName, outputFileName);
	test.setKey(key);
	test.encrypt();


	return 0;
}