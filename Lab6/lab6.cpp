#include "comic.h"

int main()
{

	/************************************************************************************************
	* Custom Constructors
	*************************************************************************************************/

	Item item;
	Book book;
	Comic comic;

	cout << "Default Constructors" << endl
		 << "Item: " << endl << item << endl
		 << "Book: " << endl << book << endl
		 << "Comic: " << endl << comic << endl << endl;

	/************************************************************************************************
	* Preset Custom Constructors
	*************************************************************************************************/

	Item item2 = Item("0123456789", 420.69, 3);
	Book book2 = Book("987654321", "Yo mamma", "Sir Dickhead", 7, 8008);
	Comic comic2 = Comic("19734668250", "Go away", "qwerty", 69.69, 10, 5, 9);

	cout << "Preset Custom Constructos:" << endl
	     << "Item: " << endl << item << endl
		 << "Book: " << endl << book << endl
		 << "Comic: " << endl << comic << endl << endl;

	/************************************************************************************************
	* Unset Custom Constructors
	*************************************************************************************************/

	Item item3;
	Book book3;
	Comic comic3;

	cout << "Unset Custom Constructors" << endl;

	cin >> item3 >> book3 >> comic3;

	cout << "Item: " << endl << item3 << endl
		<< "Book: " << endl << book3 << endl
		<< "Comic: " << endl << comic3 << endl;

	return 0;
}