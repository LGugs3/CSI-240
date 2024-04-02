#include "item.h"

Item::Item()
{
	mCode = "unknown";
	mPrice = -1.0;
	mQuantity = -1;
}

Item::Item(string code, double price, int quantity)
{
	mCode = code;
	mPrice = price;
	mQuantity = quantity;
}

Item::~Item()
{
}

string Item::getCode()
{
	return mCode;
}

double Item::getPrice()
{
	return mPrice;
}

int Item::getQuantity()
{
	return mQuantity;
}

void Item::setCode(string code)
{
	mCode = code;
}

void Item::setPrice(double price)
{
	mPrice = price;
}

void Item::setQuantity(int quantity)
{
	mQuantity = quantity;
}

istream& operator>>(istream& input, Item& item)
{
	string junk;

	getline(input, item.mCode);
	input >> item.mPrice >> item.mQuantity;
	input >> junk;

	return input;

}

ostream& operator<<(ostream& output, Item& item)
{
	output << "Code: " << item.mCode << endl
		 << "Price: " << item.mPrice << endl
		 << "Quantity: " << item.mQuantity << endl;

	return output;
}