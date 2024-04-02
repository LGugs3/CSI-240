
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item
{
	protected:
		string mCode;
		double mPrice;
		int mQuantity;

	public:
		Item();
		Item(string code, double price, int quantity);
		~Item();

		string getCode();
		double getPrice();
		int getQuantity();

		void setCode(string code);
		void setPrice(double price);
		void setQuantity(int quantity);

		friend istream& operator>>(istream& input, Item& item);
		friend ostream& operator<<(ostream& output, Item& item);
};



#endif