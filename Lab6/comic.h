
#ifndef COMIC_H
#define COMIC_H

#include "book.h"

class Comic : public Book
{
	private:
		int mSeries;
		int mVolume;

	public:
		Comic();
		Comic(string code, string title, string author, double price, int quantity, int volume, int series);
		~Comic();

		int getSeries();
		int getVolume();

		void setSeries(int series);
		void setVolume(int volume);

		friend istream& operator>>(istream& input, Comic& comic);
		friend ostream& operator<<(ostream& output, Comic& comic);
};


#endif