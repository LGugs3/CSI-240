#include "comic.h"

Comic::Comic() : Book()
{
	mSeries = -1;
	mVolume = -1;
}

Comic::Comic(string code, string title, string author, double price, int quantity, int volume, int series) : Book(code, title, author, price, quantity)
{
	mSeries = series;
	mVolume = volume;
}

Comic::~Comic()
{
}

int Comic::getSeries()
{
	return mSeries;
}

int Comic::getVolume()
{
	return mVolume;
}

void Comic::setSeries(int series)
{
	mSeries = series;
}

void Comic::setVolume(int volume)
{
	mVolume = volume;
}


istream& operator>>(istream& input, Comic& comic)
{
	string junk;

	input >> static_cast<Book&>(comic);
	input >> comic.mVolume >> comic.mSeries;

	return input;
}

ostream& operator<<(ostream& output, Comic& comic)
{
	output << static_cast<Book&>(comic);
	
	output << "Volume: " << comic.mVolume << endl
		 << "Series: " << comic.mSeries << endl;

	return output;
}