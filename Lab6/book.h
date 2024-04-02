
#ifndef BOOK_H
#define BOOK_H

#include "item.h"

class Book : public Item
{
	private:
		string mTitle;
		string mAuthor;

	public:
		Book();
		Book(string code, string title, string author, double price, int quantity);
		~Book();

		string getAuthor();
		string getTitle();

		void setAuthor(string author);
		void setTitle(string title);

		friend istream& operator>>(istream& input, Book& book);
		friend ostream& operator<<(ostream& output, Book& book);
};


#endif