
#include "encryption.h"

Encryption::Encryption()
{
	mIfName = "unset File";
	mOfName = "unset File";
	mKey = 0;
}

Encryption::Encryption(string inputFile, string outputFile, int key)
{
	mIfName = inputFile;
	mOfName = outputFile;
	mKey = key;
}

Encryption::Encryption(Encryption& obj)
{
	mIfName = obj.mIfName;
	mOfName = obj.mOfName;
	mKey = obj.mKey;
}

Encryption::~Encryption()
{
}

int Encryption::getKey()
{
	return mKey;
}

void Encryption::setKey(int key)
{
	mKey = key;
}

void Encryption::encrypt()
{
	ifstream fin;
	ofstream out;

	fin.open(mIfName);
	if (fin.fail())
	{
		cout << "fin failed to open" << endl;
		return;
	}


	string plainText, cipherText;
	//gets plaintext
	getline(fin, plainText);
	fin.close();
	if (plainText.length() == 0)
	{
		cout << "fin file is empty" << endl;
		return;
	}

	int i;
	for (i = 0; i < plainText.length(); i++)
	{
		cipherText += transform(plainText[i]);
	}

	out.open(mOfName);
	out << cipherText << endl;
	out.close();
}
