#include "method1.h"

Method1::Method1() : Encryption()
{
}

Method1::Method1(string inputFile, string outputFile) : Encryption(inputFile, outputFile, 0)
{
}

Method1::Method1(Method1& obj) : Encryption(obj)
{
}

Method1::~Method1()
{
}

char Method1::transform(char ch)
{
	return ch + mKey;
}
