
#include "encryption.h"

class Method1 : public Encryption
{
	public:
		Method1();
		Method1(string inputFile, string outputFile);
		Method1(Method1& obj);
		~Method1();

		virtual char transform(char ch);
};