#include "method2.h"

Method2::Method2() : Encryption()
{
}

Method2::Method2(string inputFile, string outputFile) : Encryption(inputFile, outputFile, 0)
{
}

Method2::Method2(Method2& obj) : Encryption(obj)
{
}

Method2::~Method2()
{
}

char Method2::transform(char ch)
{
	return static_cast<char>(ch ^ mKey);
}

