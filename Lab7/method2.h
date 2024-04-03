
#include "method1.h"

class Method2 : public Encryption
{
	public:
		Method2();
		Method2(string inputFile, string outputFile);
		Method2(Method2& obj);
		~Method2();

		virtual char transform(char ch);
};