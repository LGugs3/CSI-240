#include "book.h"


Book::Book() : Item()
{
	mTitle = "unknown";
	mAuthor = "unknown";
}

Book::Book(string code, string title, string author, double price, int quantity) : Item(code, price, quantity)
{
	mTitle = title;
	mAuthor = author;
}

Book::~Book()
{
}

string Book::getAuthor()
{
	return mAuthor;
}

string Book::getTitle()
{
	return mTitle;
}

void Book::setAuthor(string author)
{
	mAuthor = author;
}

void Book::setTitle(string title)
{
	mTitle = title;
}

istream& operator>>(istream& input, Book& book)
{
	input >> static_cast<Item&>(book);

	getline(input, book.mTitle);
	getline(input, book.mAuthor);

	return input;
}

ostream& operator<<(ostream& output, Book& book)
{
	output << static_cast<Item&>(book);
	output << "Title: " << book.mTitle << endl
		 << "Author: " << book.mAuthor << endl;

	return output;
}
