
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Encryption
{
	protected:
		string mIfName;
		string mOfName;
		int mKey;
	public:
		Encryption();
		Encryption(string inputFile, string outputFile, int key);
		Encryption(Encryption& obj);
		~Encryption();

		int getKey();

		void setKey(int key);

		void encrypt();

		virtual char transform(char ch) = 0;

};